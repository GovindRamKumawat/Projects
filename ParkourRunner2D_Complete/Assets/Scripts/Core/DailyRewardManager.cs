using UnityEngine;
using System;
using System.Collections.Generic;

[CreateAssetMenu(fileName = "DailyRewardData", menuName = "Parkour Runner/Daily Reward Data")]
public class DailyRewardData : ScriptableObject
{
    [System.Serializable]
    public class DailyReward
    {
        public int day;
        public int coins;
        public int techParts;
        public bool isPremium;
        public Sprite rewardIcon;
        public string rewardName;
    }

    public DailyReward[] rewards;
    public int maxStreakDays = 7;
    public int streakResetDays = 2; // Missed days before streak resets
}

public class DailyRewardManager : MonoBehaviour
{
    public static DailyRewardManager Instance { get; private set; }

    [Header("Reward Data")]
    [SerializeField] private DailyRewardData rewardData;

    [Header("UI")]
    [SerializeField] private GameObject dailyRewardPanel;
    [SerializeField] private Transform rewardContainer;

    // Runtime
    private int currentStreak = 0;
    private int currentDay = 0;
    private string lastClaimDate;
    private bool isRewardAvailable = false;

    // Events
    public event Action<int> OnDailyRewardClaimed;
    public event Action<int> OnStreakUpdated;

    void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        else
        {
            Destroy(gameObject);
            return;
        }

        LoadProgress();
    }

    void Start()
    {
        CheckDailyReward();
    }

    void LoadProgress()
    {
        currentStreak = PlayerPrefs.GetInt("DailyStreak", 0);
        currentDay = PlayerPrefs.GetInt("DailyDay", 0);
        lastClaimDate = PlayerPrefs.GetString("LastClaimDate", "");
    }

    void SaveProgress()
    {
        PlayerPrefs.SetInt("DailyStreak", currentStreak);
        PlayerPrefs.SetInt("DailyDay", currentDay);
        PlayerPrefs.SetString("LastClaimDate", lastClaimDate);
        PlayerPrefs.Save();
    }

    public void CheckDailyReward()
    {
        string today = DateTime.Now.ToString("yyyy-MM-dd");

        if (string.IsNullOrEmpty(lastClaimDate))
        {
            // First time
            isRewardAvailable = true;
            currentDay = 1;
        }
        else
        {
            DateTime lastClaim = DateTime.Parse(lastClaimDate);
            DateTime now = DateTime.Now;

            int daysDifference = (now - lastClaim).Days;

            if (daysDifference == 0)
            {
                // Already claimed today
                isRewardAvailable = false;
            }
            else if (daysDifference == 1)
            {
                // Next day - continue streak
                isRewardAvailable = true;
                currentStreak++;
                currentDay++;

                if (currentDay > rewardData.rewards.Length)
                {
                    currentDay = 1; // Reset cycle
                }
            }
            else if (daysDifference > rewardData.streakResetDays)
            {
                // Streak broken
                isRewardAvailable = true;
                currentStreak = 1;
                currentDay = 1;
            }
            else
            {
                // Within grace period
                isRewardAvailable = true;
                currentDay++;

                if (currentDay > rewardData.rewards.Length)
                {
                    currentDay = 1;
                }
            }
        }

        // Cap streak
        if (currentStreak > rewardData.maxStreakDays)
        {
            currentStreak = rewardData.maxStreakDays;
        }

        OnStreakUpdated?.Invoke(currentStreak);

        if (isRewardAvailable)
        {
            ShowDailyRewardPanel();
        }
    }

    public void ClaimDailyReward()
    {
        if (!isRewardAvailable) return;

        var reward = GetCurrentReward();
        if (reward == null) return;

        // Give rewards
        GameManager.Instance?.AddCoins(reward.coins);

        // Tech parts
        // GameManager.Instance?.AddTechParts(reward.techParts);

        // Update state
        lastClaimDate = DateTime.Now.ToString("yyyy-MM-dd");
        isRewardAvailable = false;

        SaveProgress();

        // Notify
        OnDailyRewardClaimed?.Invoke(currentDay);

        NotificationManager.Instance?.ShowNotification(
            $"Day {currentDay} Reward Claimed! +{reward.coins} Coins",
            NotificationType.Success
        );

        AudioManager.Instance?.PlaySFX("Reward");

        // Hide panel
        dailyRewardPanel?.SetActive(false);
    }

    DailyRewardData.DailyReward GetCurrentReward()
    {
        if (rewardData == null || rewardData.rewards == null) return null;

        foreach (var reward in rewardData.rewards)
        {
            if (reward.day == currentDay)
                return reward;
        }

        return null;
    }

    void ShowDailyRewardPanel()
    {
        if (dailyRewardPanel == null) return;

        dailyRewardPanel.SetActive(true);

        // Setup UI
        // Show streak, available reward, etc.
    }

    public bool IsRewardAvailable()
    {
        return isRewardAvailable;
    }

    public int GetCurrentStreak()
    {
        return currentStreak;
    }

    public int GetCurrentDay()
    {
        return currentDay;
    }

    public void ResetProgress()
    {
        currentStreak = 0;
        currentDay = 0;
        lastClaimDate = "";
        SaveProgress();
    }
}
