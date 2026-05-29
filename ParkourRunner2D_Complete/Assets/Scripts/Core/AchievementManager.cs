using UnityEngine;
using System;
using System.Collections.Generic;

[CreateAssetMenu(fileName = "NewAchievement", menuName = "Parkour Runner/Achievement")]
public class Achievement : ScriptableObject
{
    public string achievementName;
    public string description;
    public Sprite icon;
    public AchievementType type;
    public int targetValue;
    public int rewardCoins;
    public bool isHidden;

    [HideInInspector] public bool isCompleted;
    [HideInInspector] public int currentProgress;
    [HideInInspector] public bool rewardClaimed;
}

public enum AchievementType
{
    Distance,
    Score,
    Coins,
    Combos,
    EnemiesKilled,
    MovesPerformed,
    Checkpoints,
    BiomesVisited,
    TimePlayed,
    Deaths,
    PerfectRuns,
    StylePoints
}

public class AchievementManager : MonoBehaviour
{
    public static AchievementManager Instance { get; private set; }

    [Header("Achievements")]
    [SerializeField] private List<Achievement> achievements;

    [Header("Daily Challenges")]
    [SerializeField] private List<Achievement> dailyChallenges;
    [SerializeField] private string lastDailyReset;

    // Events
    public event Action<Achievement> OnAchievementCompleted;
    public event Action<Achievement> OnAchievementProgress;
    public event Action OnDailyChallengesReset;

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
        CheckDailyReset();
    }

    void LoadProgress()
    {
        // Load from save data
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null)
        {
            // Load completed missions
            for (int i = 0; i < achievements.Count && i < data.CompletedMissions.Length; i++)
            {
                achievements[i].isCompleted = data.CompletedMissions[i];
            }
        }
    }

    void CheckDailyReset()
    {
        string today = DateTime.Now.ToString("yyyy-MM-dd");

        if (lastDailyReset != today)
        {
            ResetDailyChallenges();
            lastDailyReset = today;
        }
    }

    void ResetDailyChallenges()
    {
        foreach (var challenge in dailyChallenges)
        {
            challenge.currentProgress = 0;
            challenge.isCompleted = false;
            challenge.rewardClaimed = false;
        }

        OnDailyChallengesReset?.Invoke();
    }

    public void UpdateProgress(AchievementType type, int value)
    {
        foreach (var achievement in achievements)
        {
            if (achievement.type == type && !achievement.isCompleted)
            {
                achievement.currentProgress += value;

                OnAchievementProgress?.Invoke(achievement);

                if (achievement.currentProgress >= achievement.targetValue)
                {
                    CompleteAchievement(achievement);
                }
            }
        }

        // Also update daily challenges
        foreach (var challenge in dailyChallenges)
        {
            if (challenge.type == type && !challenge.isCompleted)
            {
                challenge.currentProgress += value;

                if (challenge.currentProgress >= challenge.targetValue)
                {
                    CompleteAchievement(challenge);
                }
            }
        }
    }

    public void SetProgress(AchievementType type, int value)
    {
        foreach (var achievement in achievements)
        {
            if (achievement.type == type && !achievement.isCompleted)
            {
                achievement.currentProgress = value;

                if (achievement.currentProgress >= achievement.targetValue)
                {
                    CompleteAchievement(achievement);
                }
            }
        }
    }

    void CompleteAchievement(Achievement achievement)
    {
        achievement.isCompleted = true;

        // Save
        int index = achievements.IndexOf(achievement);
        if (index >= 0)
        {
            SaveManager.Instance?.GetCurrentData()?.CompletedMissions[index] = true;
        }

        // Notify
        OnAchievementCompleted?.Invoke(achievement);

        // Show notification
        ShowAchievementNotification(achievement);

        AudioManager.Instance?.PlaySFX("Achievement");
    }

    public bool ClaimReward(Achievement achievement)
    {
        if (achievement.isCompleted && !achievement.rewardClaimed)
        {
            achievement.rewardClaimed = true;
            GameManager.Instance?.AddCoins(achievement.rewardCoins);
            return true;
        }
        return false;
    }

    void ShowAchievementNotification(Achievement achievement)
    {
        // Trigger UI notification
        Debug.Log($"Achievement Unlocked: {achievement.achievementName}");
    }

    public List<Achievement> GetAchievements()
    {
        return achievements;
    }

    public List<Achievement> GetDailyChallenges()
    {
        return dailyChallenges;
    }

    public List<Achievement> GetCompletedAchievements()
    {
        return achievements.FindAll(a => a.isCompleted);
    }

    public List<Achievement> GetInProgressAchievements()
    {
        return achievements.FindAll(a => !a.isCompleted);
    }

    public float GetProgressPercentage(Achievement achievement)
    {
        return Mathf.Clamp01((float)achievement.currentProgress / achievement.targetValue);
    }
}
