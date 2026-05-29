using UnityEngine;
using System.Collections.Generic;
using System;

public class AnalyticsManager : MonoBehaviour
{
    public static AnalyticsManager Instance { get; private set; }

    [Header("Analytics Settings")]
    [SerializeField] private bool enableAnalytics = true;
    [SerializeField] private bool logToConsole = true;

    [Header("Events")]
    [SerializeField] private bool trackPlayerEvents = true;
    [SerializeField] private bool trackGameEvents = true;
    [SerializeField] private bool trackEconomyEvents = true;
    [SerializeField] private bool trackProgressionEvents = true;

    // Runtime data
    private Dictionary<string, object> sessionData = new Dictionary<string, object>();
    private float sessionStartTime;
    private int sessionRunCount = 0;

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

        sessionStartTime = Time.time;
    }

    void Start()
    {
        if (enableAnalytics)
        {
            InitializeAnalytics();
        }
    }

    void InitializeAnalytics()
    {
        // Initialize Firebase, Unity Analytics, or other SDK
        // FirebaseAnalytics.SetAnalyticsCollectionEnabled(true);

        LogEvent("session_start", new Dictionary<string, object>
        {
            { "device_model", SystemInfo.deviceModel },
            { "device_os", SystemInfo.operatingSystem },
            { "game_version", Application.version }
        });
    }

    #region Player Events
    public void LogPlayerDeath(float distance, int score, string cause, string biome)
    {
        if (!trackPlayerEvents) return;

        LogEvent("player_death", new Dictionary<string, object>
        {
            { "distance", distance },
            { "score", score },
            { "cause", cause },
            { "biome", biome },
            { "session_run", sessionRunCount }
        });
    }

    public void LogParkourMove(string moveName, float distance, int combo)
    {
        if (!trackPlayerEvents) return;

        LogEvent("parkour_move", new Dictionary<string, object>
        {
            { "move", moveName },
            { "distance", distance },
            { "combo", combo }
        });
    }

    public void LogCheckpointReached(float distance, int chunk)
    {
        if (!trackPlayerEvents) return;

        LogEvent("checkpoint_reached", new Dictionary<string, object>
        {
            { "distance", distance },
            { "chunk", chunk }
        });
    }
    #endregion

    #region Game Events
    public void LogGameStart(string character, string style, string biome)
    {
        if (!trackGameEvents) return;

        sessionRunCount++;

        LogEvent("game_start", new Dictionary<string, object>
        {
            { "character", character },
            { "style", style },
            { "biome", biome },
            { "run_number", sessionRunCount }
        });
    }

    public void LogGameEnd(float distance, int score, int coins, float duration, bool isHighScore)
    {
        if (!trackGameEvents) return;

        LogEvent("game_end", new Dictionary<string, object>
        {
            { "distance", distance },
            { "score", score },
            { "coins", coins },
            { "duration", duration },
            { "is_high_score", isHighScore }
        });
    }

    public void LogPause(float gameTime)
    {
        if (!trackGameEvents) return;

        LogEvent("game_pause", new Dictionary<string, object>
        {
            { "game_time", gameTime }
        });
    }

    public void LogResume(float pauseDuration)
    {
        if (!trackGameEvents) return;

        LogEvent("game_resume", new Dictionary<string, object>
        {
            { "pause_duration", pauseDuration }
        });
    }
    #endregion

    #region Economy Events
    public void LogCoinEarned(int amount, string source)
    {
        if (!trackEconomyEvents) return;

        LogEvent("coin_earned", new Dictionary<string, object>
        {
            { "amount", amount },
            { "source", source }
        });
    }

    public void LogCoinSpent(int amount, string item)
    {
        if (!trackEconomyEvents) return;

        LogEvent("coin_spent", new Dictionary<string, object>
        {
            { "amount", amount },
            { "item", item }
        });
    }

    public void LogPurchase(string productId, float price, string currency)
    {
        if (!trackEconomyEvents) return;

        LogEvent("purchase", new Dictionary<string, object>
        {
            { "product_id", productId },
            { "price", price },
            { "currency", currency }
        });
    }

    public void LogAdShown(string adType, string placement)
    {
        if (!trackEconomyEvents) return;

        LogEvent("ad_shown", new Dictionary<string, object>
        {
            { "ad_type", adType },
            { "placement", placement }
        });
    }

    public void LogAdReward(string adType, string reward)
    {
        if (!trackEconomyEvents) return;

        LogEvent("ad_reward", new Dictionary<string, object>
        {
            { "ad_type", adType },
            { "reward", reward }
        });
    }
    #endregion

    #region Progression Events
    public void LogLevelUp(int newLevel, int totalXP)
    {
        if (!trackProgressionEvents) return;

        LogEvent("level_up", new Dictionary<string, object>
        {
            { "new_level", newLevel },
            { "total_xp", totalXP }
        });
    }

    public void LogAchievementUnlocked(string achievementName)
    {
        if (!trackProgressionEvents) return;

        LogEvent("achievement_unlocked", new Dictionary<string, object>
        {
            { "achievement", achievementName }
        });
    }

    public void LogCharacterUnlocked(string characterName)
    {
        if (!trackProgressionEvents) return;

        LogEvent("character_unlocked", new Dictionary<string, object>
        {
            { "character", characterName }
        });
    }

    public void LogStyleUnlocked(string styleName)
    {
        if (!trackProgressionEvents) return;

        LogEvent("style_unlocked", new Dictionary<string, object>
        {
            { "style", styleName }
        });
    }

    public void LogUpgradePurchased(string upgradeName, int level)
    {
        if (!trackProgressionEvents) return;

        LogEvent("upgrade_purchased", new Dictionary<string, object>
        {
            { "upgrade", upgradeName },
            { "level", level }
        });
    }
    #endregion

    #region Core Logging
    void LogEvent(string eventName, Dictionary<string, object> parameters)
    {
        if (!enableAnalytics) return;

        // Log to console for debugging
        if (logToConsole)
        {
            string paramString = "";
            foreach (var param in parameters)
            {
                paramString += $"{param.Key}={param.Value}, ";
            }
            Debug.Log($"[Analytics] {eventName}: {paramString}");
        }

        // Send to analytics SDK
        // FirebaseAnalytics.LogEvent(eventName, parameters);
        // UnityAnalytics.CustomEvent(eventName, parameters);
    }

    public void LogCustomEvent(string eventName, Dictionary<string, object> parameters)
    {
        LogEvent(eventName, parameters);
    }
    #endregion

    #region Session Data
    public void LogSessionEnd()
    {
        float sessionDuration = Time.time - sessionStartTime;

        LogEvent("session_end", new Dictionary<string, object>
        {
            { "duration", sessionDuration },
            { "runs", sessionRunCount },
            { "quit_type", Application.isEditor ? "editor" : "normal" }
        });
    }

    void OnApplicationQuit()
    {
        LogSessionEnd();
    }

    void OnApplicationPause(bool pauseStatus)
    {
        if (pauseStatus)
        {
            LogEvent("app_pause", new Dictionary<string, object>
            {
                { "session_time", Time.time - sessionStartTime }
            });
        }
    }
    #endregion

    #region Funnel Tracking
    public void LogTutorialStep(int step, string stepName, bool completed)
    {
        LogEvent("tutorial_step", new Dictionary<string, object>
        {
            { "step_number", step },
            { "step_name", stepName },
            { "completed", completed }
        });
    }

    public void LogTutorialComplete(float duration)
    {
        LogEvent("tutorial_complete", new Dictionary<string, object>
        {
            { "duration", duration }
        });
    }

    public void LogFirstPurchase()
    {
        LogEvent("first_purchase", new Dictionary<string, object>
        {
            { "days_since_install", (DateTime.Now - DateTime.Parse(PlayerPrefs.GetString("InstallDate", DateTime.Now.ToString()))).TotalDays }
        });
    }

    public void LogRetention(int day)
    {
        LogEvent($"retention_day_{day}", new Dictionary<string, object>
        {
            { "day", day }
        });
    }
    #endregion
}
