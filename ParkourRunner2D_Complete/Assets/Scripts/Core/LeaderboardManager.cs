using UnityEngine;
using System.Collections.Generic;
using System;

[Serializable]
public class LeaderboardEntry
{
    public string playerName;
    public int score;
    public float distance;
    public string date;
    public string characterUsed;
    public string styleUsed;
}

public class LeaderboardManager : MonoBehaviour
{
    public static LeaderboardManager Instance { get; private set; }

    [Header("Leaderboard Settings")]
    [SerializeField] private int maxEntries = 100;
    [SerializeField] private bool useLocalLeaderboard = true;
    [SerializeField] private string onlineLeaderboardURL = "";

    [Header("Player Info")]
    [SerializeField] private string playerName = "Player";

    // Runtime
    private List<LeaderboardEntry> localEntries = new List<LeaderboardEntry>();
    private List<LeaderboardEntry> globalEntries = new List<LeaderboardEntry>();

    // Events
    public event Action OnLeaderboardUpdated;
    public event Action OnScoreSubmitted;

    void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
            return;
        }

        LoadLocalLeaderboard();
    }

    void LoadLocalLeaderboard()
    {
        string json = PlayerPrefs.GetString("LocalLeaderboard", "[]");
        localEntries = JsonUtility.FromJson<LeaderboardList>(json)?.entries ?? new List<LeaderboardEntry>();
    }

    void SaveLocalLeaderboard()
    {
        LeaderboardList list = new LeaderboardList { entries = localEntries };
        string json = JsonUtility.ToJson(list);
        PlayerPrefs.SetString("LocalLeaderboard", json);
        PlayerPrefs.Save();
    }

    public void SubmitScore(int score, float distance, string character, string style)
    {
        LeaderboardEntry entry = new LeaderboardEntry
        {
            playerName = playerName,
            score = score,
            distance = distance,
            date = DateTime.Now.ToString("yyyy-MM-dd"),
            characterUsed = character,
            styleUsed = style
        };

        // Add to local leaderboard
        localEntries.Add(entry);

        // Sort by score
        localEntries.Sort((a, b) => b.score.CompareTo(a.score));

        // Trim to max entries
        if (localEntries.Count > maxEntries)
        {
            localEntries.RemoveRange(maxEntries, localEntries.Count - maxEntries);
        }

        SaveLocalLeaderboard();

        // Submit to online if available
        if (!useLocalLeaderboard && !string.IsNullOrEmpty(onlineLeaderboardURL))
        {
            StartCoroutine(SubmitOnlineScore(entry));
        }

        OnScoreSubmitted?.Invoke();
        OnLeaderboardUpdated?.Invoke();
    }

    System.Collections.IEnumerator SubmitOnlineScore(LeaderboardEntry entry)
    {
        // Implement online leaderboard submission
        // This would use UnityWebRequest to POST to your server
        yield return null;
    }

    System.Collections.IEnumerator FetchGlobalLeaderboard()
    {
        // Implement online leaderboard fetching
        yield return null;
    }

    public List<LeaderboardEntry> GetLocalLeaderboard()
    {
        return localEntries;
    }

    public List<LeaderboardEntry> GetGlobalLeaderboard()
    {
        return globalEntries;
    }

    public int GetPlayerRank(int score)
    {
        for (int i = 0; i < localEntries.Count; i++)
        {
            if (score > localEntries[i].score)
            {
                return i + 1;
            }
        }
        return localEntries.Count + 1;
    }

    public void SetPlayerName(string name)
    {
        playerName = name;
        PlayerPrefs.SetString("PlayerName", name);
    }

    public void ClearLeaderboard()
    {
        localEntries.Clear();
        SaveLocalLeaderboard();
        OnLeaderboardUpdated?.Invoke();
    }
}

[Serializable]
public class LeaderboardList
{
    public List<LeaderboardEntry> entries;
}
