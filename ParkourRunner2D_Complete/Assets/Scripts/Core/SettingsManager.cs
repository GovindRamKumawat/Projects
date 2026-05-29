using UnityEngine;
using UnityEngine.Audio;
using System;

public class SettingsManager : MonoBehaviour
{
    public static SettingsManager Instance { get; private set; }

    [Header("Audio")]
    [SerializeField] private AudioMixer mainMixer;
    [SerializeField] private float defaultMusicVolume = 0.7f;
    [SerializeField] private float defaultSFXVolume = 0.8f;
    [SerializeField] private float defaultAmbientVolume = 0.3f;

    [Header("Graphics")]
    [SerializeField] private int defaultQualityLevel = 2;
    [SerializeField] private bool defaultVSync = false;
    [SerializeField] private int defaultTargetFPS = 60;

    [Header("Gameplay")]
    [SerializeField] private bool defaultVibration = true;
    [SerializeField] private bool defaultLeftHanded = false;
    [SerializeField] private float defaultSensitivity = 1f;
    [SerializeField] private bool defaultAutoRun = true;

    [Header("Notifications")]
    [SerializeField] private bool defaultPushNotifications = true;
    [SerializeField] private bool defaultDailyReminder = true;

    // Runtime values
    public float MusicVolume { get; private set; }
    public float SFXVolume { get; private set; }
    public float AmbientVolume { get; private set; }
    public int QualityLevel { get; private set; }
    public bool VSync { get; private set; }
    public int TargetFPS { get; private set; }
    public bool Vibration { get; private set; }
    public bool LeftHanded { get; private set; }
    public float Sensitivity { get; private set; }
    public bool AutoRun { get; private set; }
    public bool PushNotifications { get; private set; }
    public bool DailyReminder { get; private set; }

    // Events
    public event Action OnSettingsChanged;

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

        LoadSettings();
    }

    void LoadSettings()
    {
        MusicVolume = PlayerPrefs.GetFloat("MusicVolume", defaultMusicVolume);
        SFXVolume = PlayerPrefs.GetFloat("SFXVolume", defaultSFXVolume);
        AmbientVolume = PlayerPrefs.GetFloat("AmbientVolume", defaultAmbientVolume);
        QualityLevel = PlayerPrefs.GetInt("QualityLevel", defaultQualityLevel);
        VSync = PlayerPrefs.GetInt("VSync", defaultVSync ? 1 : 0) == 1;
        TargetFPS = PlayerPrefs.GetInt("TargetFPS", defaultTargetFPS);
        Vibration = PlayerPrefs.GetInt("Vibration", defaultVibration ? 1 : 0) == 1;
        LeftHanded = PlayerPrefs.GetInt("LeftHanded", defaultLeftHanded ? 1 : 0) == 1;
        Sensitivity = PlayerPrefs.GetFloat("Sensitivity", defaultSensitivity);
        AutoRun = PlayerPrefs.GetInt("AutoRun", defaultAutoRun ? 1 : 0) == 1;
        PushNotifications = PlayerPrefs.GetInt("PushNotifications", defaultPushNotifications ? 1 : 0) == 1;
        DailyReminder = PlayerPrefs.GetInt("DailyReminder", defaultDailyReminder ? 1 : 0) == 1;

        ApplySettings();
    }

    void SaveSettings()
    {
        PlayerPrefs.SetFloat("MusicVolume", MusicVolume);
        PlayerPrefs.SetFloat("SFXVolume", SFXVolume);
        PlayerPrefs.SetFloat("AmbientVolume", AmbientVolume);
        PlayerPrefs.SetInt("QualityLevel", QualityLevel);
        PlayerPrefs.SetInt("VSync", VSync ? 1 : 0);
        PlayerPrefs.SetInt("TargetFPS", TargetFPS);
        PlayerPrefs.SetInt("Vibration", Vibration ? 1 : 0);
        PlayerPrefs.SetInt("LeftHanded", LeftHanded ? 1 : 0);
        PlayerPrefs.SetFloat("Sensitivity", Sensitivity);
        PlayerPrefs.SetInt("AutoRun", AutoRun ? 1 : 0);
        PlayerPrefs.SetInt("PushNotifications", PushNotifications ? 1 : 0);
        PlayerPrefs.SetInt("DailyReminder", DailyReminder ? 1 : 0);
        PlayerPrefs.Save();
    }

    void ApplySettings()
    {
        // Audio
        if (mainMixer != null)
        {
            mainMixer.SetFloat("MusicVolume", Mathf.Log10(Mathf.Max(MusicVolume, 0.001f)) * 20);
            mainMixer.SetFloat("SFXVolume", Mathf.Log10(Mathf.Max(SFXVolume, 0.001f)) * 20);
            mainMixer.SetFloat("AmbientVolume", Mathf.Log10(Mathf.Max(AmbientVolume, 0.001f)) * 20);
        }

        // Graphics
        QualitySettings.SetQualityLevel(QualityLevel);
        QualitySettings.vSyncCount = VSync ? 1 : 0;
        Application.targetFrameRate = TargetFPS;

        // Apply to managers
        AudioManager.Instance?.SetMusicVolume(MusicVolume);
        AudioManager.Instance?.SetSFXVolume(SFXVolume);
        PerformanceManager.Instance?.SetQualityLevel(QualityLevel);

        OnSettingsChanged?.Invoke();
    }

    #region Setters
    public void SetMusicVolume(float volume)
    {
        MusicVolume = Mathf.Clamp01(volume);
        SaveSettings();
        ApplySettings();
    }

    public void SetSFXVolume(float volume)
    {
        SFXVolume = Mathf.Clamp01(volume);
        SaveSettings();
        ApplySettings();
    }

    public void SetAmbientVolume(float volume)
    {
        AmbientVolume = Mathf.Clamp01(volume);
        SaveSettings();
        ApplySettings();
    }

    public void SetQualityLevel(int level)
    {
        QualityLevel = Mathf.Clamp(level, 0, 2);
        SaveSettings();
        ApplySettings();
    }

    public void SetVSync(bool enabled)
    {
        VSync = enabled;
        SaveSettings();
        ApplySettings();
    }

    public void SetTargetFPS(int fps)
    {
        TargetFPS = Mathf.Clamp(fps, 30, 120);
        SaveSettings();
        ApplySettings();
    }

    public void SetVibration(bool enabled)
    {
        Vibration = enabled;
        SaveSettings();
    }

    public void SetLeftHanded(bool enabled)
    {
        LeftHanded = enabled;
        SaveSettings();
        // Update UI layout
    }

    public void SetSensitivity(float sensitivity)
    {
        Sensitivity = Mathf.Clamp(sensitivity, 0.1f, 3f);
        SaveSettings();
    }

    public void SetAutoRun(bool enabled)
    {
        AutoRun = enabled;
        SaveSettings();
    }

    public void SetPushNotifications(bool enabled)
    {
        PushNotifications = enabled;
        SaveSettings();
    }

    public void SetDailyReminder(bool enabled)
    {
        DailyReminder = enabled;
        SaveSettings();
    }
    #endregion

    public void ResetToDefaults()
    {
        MusicVolume = defaultMusicVolume;
        SFXVolume = defaultSFXVolume;
        AmbientVolume = defaultAmbientVolume;
        QualityLevel = defaultQualityLevel;
        VSync = defaultVSync;
        TargetFPS = defaultTargetFPS;
        Vibration = defaultVibration;
        LeftHanded = defaultLeftHanded;
        Sensitivity = defaultSensitivity;
        AutoRun = defaultAutoRun;
        PushNotifications = defaultPushNotifications;
        DailyReminder = defaultDailyReminder;

        SaveSettings();
        ApplySettings();
    }
}
