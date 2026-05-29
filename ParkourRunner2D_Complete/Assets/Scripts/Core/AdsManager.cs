using UnityEngine;
using System;
using System.Collections;

public class AdsManager : MonoBehaviour
{
    public static AdsManager Instance { get; private set; }

    [Header("Ad Settings")]
    [SerializeField] private bool enableAds = true;
    [SerializeField] private bool testMode = true;
    [SerializeField] private int interstitialInterval = 3; // Every N runs
    [SerializeField] private float minTimeBetweenAds = 60f; // Seconds

    [Header("Ad IDs")]
    [SerializeField] private string bannerAdUnitId = "ca-app-pub-3940256099942544/6300978111"; // Test ID
    [SerializeField] private string interstitialAdUnitId = "ca-app-pub-3940256099942544/1033173712"; // Test ID
    [SerializeField] private string rewardedAdUnitId = "ca-app-pub-3940256099942544/5224354917"; // Test ID

    [Header("Rewards")]
    [SerializeField] private int rewardCoins = 100;
    [SerializeField] private int rewardExtraLife = 1;
    [SerializeField] private float rewardDoubleCoinsDuration = 300f; // 5 minutes

    // Runtime
    private int runCount = 0;
    private float lastAdTime = -999f;
    private bool isAdPlaying = false;

    // Events
    public event Action OnRewardedAdCompleted;
    public event Action OnRewardedAdSkipped;
    public event Action OnInterstitialAdClosed;

    // Ad state
    private bool isBannerLoaded = false;
    private bool isInterstitialLoaded = false;
    private bool isRewardedLoaded = false;

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
    }

    void Start()
    {
        if (enableAds)
        {
            InitializeAds();
        }
    }

    void InitializeAds()
    {
        // Mobile Ads SDK initialize
        // GoogleMobileAds.Api.MobileAds.Initialize(initStatus => {
        //     Debug.Log("Mobile Ads SDK initialized");
        //     LoadAds();
        // });

        Debug.Log("Ads initialization placeholder - integrate your preferred ad SDK");
        LoadAds();
    }

    void LoadAds()
    {
        LoadBannerAd();
        LoadInterstitialAd();
        LoadRewardedAd();
    }

    #region Banner Ad
    void LoadBannerAd()
    {
        // GoogleMobileAds implementation placeholder
        // BannerView bannerView = new BannerView(bannerAdUnitId, AdSize.Banner, AdPosition.Bottom);
        // AdRequest request = new AdRequest.Builder().Build();
        // bannerView.LoadAd(request);
        // isBannerLoaded = true;

        Debug.Log("Banner ad loading placeholder");
    }

    public void ShowBannerAd()
    {
        if (!enableAds) return;
        // bannerView?.Show();
    }

    public void HideBannerAd()
    {
        // bannerView?.Hide();
    }

    public void DestroyBannerAd()
    {
        // bannerView?.Destroy();
    }
    #endregion

    #region Interstitial Ad
    void LoadInterstitialAd()
    {
        // InterstitialAd.Load(interstitialAdUnitId, new AdRequest.Builder().Build(), 
        //     (ad, error) => {
        //         if (error == null) {
        //             interstitialAd = ad;
        //             isInterstitialLoaded = true;
        //         }
        //     });

        Debug.Log("Interstitial ad loading placeholder");
        isInterstitialLoaded = true;
    }

    public void ShowInterstitialAd()
    {
        if (!enableAds || isAdPlaying) return;

        // Check interval
        runCount++;
        if (runCount < interstitialInterval) return;

        // Check time
        if (Time.time - lastAdTime < minTimeBetweenAds) return;

        if (isInterstitialLoaded)
        {
            isAdPlaying = true;
            // interstitialAd?.Show();

            // Simulate ad closed
            StartCoroutine(SimulateAdClosed());

            runCount = 0;
            lastAdTime = Time.time;
        }
        else
        {
            LoadInterstitialAd();
        }
    }

    IEnumerator SimulateAdClosed()
    {
        yield return new WaitForSeconds(1f);
        isAdPlaying = false;
        OnInterstitialAdClosed?.Invoke();
        LoadInterstitialAd(); // Preload next
    }
    #endregion

    #region Rewarded Ad
    void LoadRewardedAd()
    {
        // RewardedAd.Load(rewardedAdUnitId, new AdRequest.Builder().Build(),
        //     (ad, error) => {
        //         if (error == null) {
        //             rewardedAd = ad;
        //             isRewardedLoaded = true;
        //         }
        //     });

        Debug.Log("Rewarded ad loading placeholder");
        isRewardedLoaded = true;
    }

    public void ShowRewardedAd(RewardType rewardType)
    {
        if (!enableAds || isAdPlaying) return;

        if (isRewardedLoaded)
        {
            isAdPlaying = true;
            // rewardedAd?.Show(reward => {
            //     GiveReward(rewardType);
            // });

            // Simulate reward
            StartCoroutine(SimulateRewardedAd(rewardType));
        }
        else
        {
            LoadRewardedAd();
            // Show notification that ad is loading
            NotificationManager.Instance?.ShowWarning("Ad loading... Please try again!");
        }
    }

    IEnumerator SimulateRewardedAd(RewardType rewardType)
    {
        yield return new WaitForSeconds(1f);
        isAdPlaying = false;
        GiveReward(rewardType);
        OnRewardedAdCompleted?.Invoke();
        LoadRewardedAd(); // Preload next
    }

    void GiveReward(RewardType type)
    {
        switch (type)
        {
            case RewardType.Coins:
                GameManager.Instance?.AddCoins(rewardCoins);
                NotificationManager.Instance?.ShowCoinReward(rewardCoins);
                break;

            case RewardType.ExtraLife:
                // GameManager.Instance?.AddExtraLife(rewardExtraLife);
                NotificationManager.Instance?.ShowNotification("Extra Life Added!", NotificationType.Success);
                break;

            case RewardType.DoubleCoins:
                // Activate double coins for duration
                // GameManager.Instance?.ActivateDoubleCoins(rewardDoubleCoinsDuration);
                NotificationManager.Instance?.ShowNotification("Double Coins Activated!", NotificationType.Success);
                break;

            case RewardType.Continue:
                // Continue from death
                // GameManager.Instance?.ContinueFromDeath();
                NotificationManager.Instance?.ShowNotification("Run Continued!", NotificationType.Success);
                break;

            case RewardType.PowerUp:
                // Give random power-up
                NotificationManager.Instance?.ShowNotification("Power-Up Rewarded!", NotificationType.Success);
                break;
        }

        AudioManager.Instance?.PlaySFX("Reward");
    }
    #endregion

    public bool IsAdPlaying()
    {
        return isAdPlaying;
    }

    public void OnRunStarted()
    {
        HideBannerAd();
    }

    public void OnRunEnded()
    {
        ShowBannerAd();
        ShowInterstitialAd();
    }

    public void RemoveAds()
    {
        enableAds = false;
        DestroyBannerAd();
        PlayerPrefs.SetInt("AdsRemoved", 1);
    }

    public bool AreAdsRemoved()
    {
        return PlayerPrefs.GetInt("AdsRemoved", 0) == 1;
    }
}

public enum RewardType
{
    Coins,
    ExtraLife,
    DoubleCoins,
    Continue,
    PowerUp
}
