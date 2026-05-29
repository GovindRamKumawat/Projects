using UnityEngine;
using System.Collections.Generic;

public class SocialManager : MonoBehaviour
{
    public static SocialManager Instance { get; private set; }

    [Header("Share Settings")]
    [SerializeField] private string shareMessage = "I scored {0} in Parkour Runner 2D! Can you beat me?";
    [SerializeField] private string gameURL = "https://play.google.com/store/apps/details?id=com.yourcompany.parkourrunner2d";
    [SerializeField] private string hashtag = "#ParkourRunner2D";

    [Header("Invite Settings")]
    [SerializeField] private string inviteMessage = "Join me in Parkour Runner 2D! Use my code: {0}";
    [SerializeField] private int inviteRewardCoins = 500;
    [SerializeField] private int inviteRewardForInviter = 200;

    [Header("Screenshot")]
    [SerializeField] private int screenshotWidth = 1080;
    [SerializeField] private int screenshotHeight = 1920;

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

    #region Share
    public void ShareScore(int score, float distance)
    {
        string message = string.Format(shareMessage, score);
        string fullMessage = $"{message}

{hashtag}
{gameURL}";

        ShareText(fullMessage);
    }

    public void ShareScreenshot()
    {
        StartCoroutine(CaptureAndShareScreenshot());
    }

    System.Collections.IEnumerator CaptureAndShareScreenshot()
    {
        yield return new WaitForEndOfFrame();

        // Capture screenshot
        Texture2D screenshot = new Texture2D(screenshotWidth, screenshotHeight, TextureFormat.RGB24, false);
        screenshot.ReadPixels(new Rect(0, 0, screenshotWidth, screenshotHeight), 0, 0);
        screenshot.Apply();

        // Save to file
        byte[] bytes = screenshot.EncodeToPNG();
        string fileName = $"ParkourRunner_{System.DateTime.Now:yyyyMMdd_HHmmss}.png";
        string filePath = System.IO.Path.Combine(Application.persistentDataPath, fileName);
        System.IO.File.WriteAllBytes(filePath, bytes);

        Destroy(screenshot);

        // Share
        ShareImage(filePath, "Check out my Parkour Runner 2D gameplay!");
    }

    void ShareText(string text)
    {
        #if UNITY_ANDROID
        AndroidJavaClass intentClass = new AndroidJavaClass("android.content.Intent");
        AndroidJavaObject intentObject = new AndroidJavaObject("android.content.Intent");
        intentObject.Call<AndroidJavaObject>("setAction", intentClass.GetStatic<string>("ACTION_SEND"));
        intentObject.Call<AndroidJavaObject>("setType", "text/plain");
        intentObject.Call<AndroidJavaObject>("putExtra", intentClass.GetStatic<string>("EXTRA_TEXT"), text);

        AndroidJavaClass unity = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        AndroidJavaObject currentActivity = unity.GetStatic<AndroidJavaObject>("currentActivity");
        AndroidJavaObject chooser = intentClass.CallStatic<AndroidJavaObject>("createChooser", intentObject, "Share via");
        currentActivity.Call("startActivity", chooser);
        #elif UNITY_IOS
        // iOS share implementation
        #else
        // Editor - copy to clipboard
        GUIUtility.systemCopyBuffer = text;
        Debug.Log("Copied to clipboard: " + text);
        #endif
    }

    void ShareImage(string filePath, string message)
    {
        #if UNITY_ANDROID
        AndroidJavaClass intentClass = new AndroidJavaClass("android.content.Intent");
        AndroidJavaObject intentObject = new AndroidJavaObject("android.content.Intent");
        intentObject.Call<AndroidJavaObject>("setAction", intentClass.GetStatic<string>("ACTION_SEND"));
        intentObject.Call<AndroidJavaObject>("setType", "image/png");

        AndroidJavaClass uriClass = new AndroidJavaClass("android.net.Uri");
        AndroidJavaObject fileObject = new AndroidJavaObject("java.io.File", filePath);
        AndroidJavaObject uriObject = uriClass.CallStatic<AndroidJavaObject>("fromFile", fileObject);

        intentObject.Call<AndroidJavaObject>("putExtra", intentClass.GetStatic<string>("EXTRA_STREAM"), uriObject);
        intentObject.Call<AndroidJavaObject>("putExtra", intentClass.GetStatic<string>("EXTRA_TEXT"), message);

        AndroidJavaClass unity = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        AndroidJavaObject currentActivity = unity.GetStatic<AndroidJavaObject>("currentActivity");
        AndroidJavaObject chooser = intentClass.CallStatic<AndroidJavaObject>("createChooser", intentObject, "Share via");
        currentActivity.Call("startActivity", chooser);
        #endif
    }
    #endregion

    #region Invite
    public void InviteFriends()
    {
        string inviteCode = GetInviteCode();
        string message = string.Format(inviteMessage, inviteCode);

        ShareText(message);
    }

    public void EnterInviteCode(string code)
    {
        // Validate code
        if (IsValidInviteCode(code))
        {
            // Give reward
            GameManager.Instance?.AddCoins(inviteRewardCoins);

            // Mark as used
            PlayerPrefs.SetInt($"InviteUsed_{code}", 1);

            NotificationManager.Instance?.ShowNotification(
                $"Invite code applied! +{inviteRewardCoins} Coins", 
                NotificationType.Success
            );

            AudioManager.Instance?.PlaySFX("Reward");
        }
        else
        {
            NotificationManager.Instance?.ShowWarning("Invalid or already used invite code!");
        }
    }

    string GetInviteCode()
    {
        string code = PlayerPrefs.GetString("InviteCode", "");
        if (string.IsNullOrEmpty(code))
        {
            // Generate new code
            code = GenerateInviteCode();
            PlayerPrefs.SetString("InviteCode", code);
        }
        return code;
    }

    string GenerateInviteCode()
    {
        const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string code = "";
        System.Random random = new System.Random();

        for (int i = 0; i < 6; i++)
        {
            code += chars[random.Next(chars.Length)];
        }

        return code;
    }

    bool IsValidInviteCode(string code)
    {
        if (string.IsNullOrEmpty(code) || code.Length != 6) return false;
        if (PlayerPrefs.GetInt($"InviteUsed_{code}", 0) == 1) return false;
        if (code == GetInviteCode()) return false; // Can't use own code
        return true;
    }
    #endregion

    #region Rate App
    public void RateApp()
    {
        #if UNITY_ANDROID
        Application.OpenURL(gameURL);
        #elif UNITY_IOS
        Application.OpenURL("itms-apps://itunes.apple.com/app/idYOUR_APP_ID");
        #endif

        PlayerPrefs.SetInt("HasRated", 1);
    }

    public void ShowRateDialog()
    {
        // Check if already rated
        if (PlayerPrefs.GetInt("HasRated", 0) == 1) return;

        // Check if enough plays
        int totalRuns = SaveManager.Instance?.GetCurrentData()?.TotalRuns ?? 0;
        if (totalRuns < 5) return;

        // Show rate dialog via UI
        // UIManager.Instance?.ShowRateDialog();
    }
    #endregion

    #region Social Features
    public void ConnectToFacebook()
    {
        // Facebook SDK integration
        Debug.Log("Facebook connect placeholder");
    }

    public void ConnectToGooglePlay()
    {
        // Google Play Games integration
        Debug.Log("Google Play Games connect placeholder");
    }

    public void ShowLeaderboardUI()
    {
        // Show native leaderboard
        #if UNITY_ANDROID
        // Google Play Games leaderboard
        #elif UNITY_IOS
        // Game Center leaderboard
        #endif
    }

    public void ShowAchievementsUI()
    {
        // Show native achievements
        #if UNITY_ANDROID
        // Google Play Games achievements
        #elif UNITY_IOS
        // Game Center achievements
        #endif
    }
    #endregion
}
