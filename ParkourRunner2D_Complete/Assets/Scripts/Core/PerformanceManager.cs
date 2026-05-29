using UnityEngine;
using UnityEngine.Rendering;
using System.Collections;

public class PerformanceManager : MonoBehaviour
{
    public static PerformanceManager Instance { get; private set; }

    [Header("Target Frame Rate")]
    [SerializeField] private int targetFPS = 60;
    [SerializeField] private bool adaptiveQuality = true;

    [Header("Quality Settings")]
    [SerializeField] private int lowQualityLevel = 0;
    [SerializeField] private int mediumQualityLevel = 1;
    [SerializeField] private int highQualityLevel = 2;

    [Header("Dynamic Quality")]
    [SerializeField] private float fpsCheckInterval = 2f;
    [SerializeField] private float fpsThresholdLow = 45f;
    [SerializeField] private float fpsThresholdHigh = 58f;
    [SerializeField] private int consecutiveLowFPS = 3;
    [SerializeField] private int consecutiveHighFPS = 5;

    [Header("Optimization")]
    [SerializeField] private bool useGPUInstancing = true;
    [SerializeField] private bool useOcclusionCulling = true;
    [SerializeField] private bool useLOD = true;
    [SerializeField] private float maxParticleCount = 100;

    [Header("Memory")]
    [SerializeField] private long maxMemoryMB = 512;
    [SerializeField] private float garbageCollectInterval = 30f;

    // Runtime
    private float fpsTimer;
    private float currentFPS;
    private int lowFPSCount;
    private int highFPSCount;
    private int currentQualityLevel;
    private float gcTimer;

    // FPS tracking
    private float[] fpsHistory = new float[10];
    private int fpsIndex = 0;

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

        InitializeOptimizations();
    }

    void InitializeOptimizations()
    {
        // Set target frame rate
        Application.targetFrameRate = targetFPS;

        // Disable vsync for mobile
        QualitySettings.vSyncCount = 0;

        // Enable GPU instancing
        if (useGPUInstancing)
        {
            // Set in material settings via script if needed
        }

        // Enable occlusion culling
        if (useOcclusionCulling)
        {
            // Occlusion culling is scene-specific, enable in烘焙 settings
        }

        // Set initial quality based on device
        SetInitialQuality();

        // Reduce physics iterations
        Physics2D.velocityIterations = 4;
        Physics2D.positionIterations = 2;

        // Optimize audio
        AudioSettings.SetDSPBufferSize(1024, 4);

        // Disable unused features
        Camera.main?.GetComponent<AudioListener>()?.enabled(false);
    }

    void SetInitialQuality()
    {
        // Detect device tier
        int processorCount = SystemInfo.processorCount;
        int systemMemory = SystemInfo.systemMemorySize;
        string graphicsDevice = SystemInfo.graphicsDeviceName;

        if (systemMemory < 2048 || processorCount < 4)
        {
            currentQualityLevel = lowQualityLevel;
        }
        else if (systemMemory < 4096 || processorCount < 6)
        {
            currentQualityLevel = mediumQualityLevel;
        }
        else
        {
            currentQualityLevel = highQualityLevel;
        }

        QualitySettings.SetQualityLevel(currentQualityLevel);
        ApplyQualitySettings(currentQualityLevel);
    }

    void ApplyQualitySettings(int level)
    {
        switch (level)
        {
            case 0: // Low
                QualitySettings.shadows = ShadowQuality.Disable;
                QualitySettings.antiAliasing = 0;
                QualitySettings.anisotropicFiltering = AnisotropicFiltering.Disable;
                QualitySettings.softParticles = false;
                QualitySettings.realtimeReflectionProbes = false;
                QualitySettings.shadowResolution = ShadowResolution.Low;
                QualitySettings.shadowDistance = 20f;
                QualitySettings.lodBias = 1f;
                break;

            case 1: // Medium
                QualitySettings.shadows = ShadowQuality.HardOnly;
                QualitySettings.antiAliasing = 0;
                QualitySettings.anisotropicFiltering = AnisotropicFiltering.Enable;
                QualitySettings.softParticles = false;
                QualitySettings.realtimeReflectionProbes = false;
                QualitySettings.shadowResolution = ShadowResolution.Medium;
                QualitySettings.shadowDistance = 40f;
                QualitySettings.lodBias = 1.5f;
                break;

            case 2: // High
                QualitySettings.shadows = ShadowQuality.All;
                QualitySettings.antiAliasing = 2;
                QualitySettings.anisotropicFiltering = AnisotropicFiltering.ForceEnable;
                QualitySettings.softParticles = true;
                QualitySettings.realtimeReflectionProbes = true;
                QualitySettings.shadowResolution = ShadowResolution.High;
                QualitySettings.shadowDistance = 100f;
                QualitySettings.lodBias = 2f;
                break;
        }
    }

    void Update()
    {
        TrackFPS();

        if (adaptiveQuality)
        {
            fpsTimer += Time.deltaTime;
            if (fpsTimer >= fpsCheckInterval)
            {
                fpsTimer = 0f;
                CheckAdaptiveQuality();
            }
        }

        // Periodic garbage collection
        gcTimer += Time.deltaTime;
        if (gcTimer >= garbageCollectInterval)
        {
            gcTimer = 0f;
            RequestGarbageCollection();
        }

        // Monitor memory
        MonitorMemory();
    }

    void TrackFPS()
    {
        currentFPS = 1f / Time.unscaledDeltaTime;

        fpsHistory[fpsIndex] = currentFPS;
        fpsIndex = (fpsIndex + 1) % fpsHistory.Length;
    }

    float GetAverageFPS()
    {
        float sum = 0;
        for (int i = 0; i < fpsHistory.Length; i++)
        {
            sum += fpsHistory[i];
        }
        return sum / fpsHistory.Length;
    }

    void CheckAdaptiveQuality()
    {
        float avgFPS = GetAverageFPS();

        if (avgFPS < fpsThresholdLow)
        {
            lowFPSCount++;
            highFPSCount = 0;

            if (lowFPSCount >= consecutiveLowFPS && currentQualityLevel > lowQualityLevel)
            {
                currentQualityLevel--;
                QualitySettings.SetQualityLevel(currentQualityLevel);
                ApplyQualitySettings(currentQualityLevel);
                lowFPSCount = 0;

                Debug.Log($"Quality lowered to level {currentQualityLevel}. Avg FPS: {avgFPS:F1}");
            }
        }
        else if (avgFPS > fpsThresholdHigh)
        {
            highFPSCount++;
            lowFPSCount = 0;

            if (highFPSCount >= consecutiveHighFPS && currentQualityLevel < highQualityLevel)
            {
                currentQualityLevel++;
                QualitySettings.SetQualityLevel(currentQualityLevel);
                ApplyQualitySettings(currentQualityLevel);
                highFPSCount = 0;

                Debug.Log($"Quality raised to level {currentQualityLevel}. Avg FPS: {avgFPS:F1}");
            }
        }
        else
        {
            lowFPSCount = 0;
            highFPSCount = 0;
        }
    }

    void MonitorMemory()
    {
        long usedMemory = GC.GetTotalMemory(false) / (1024 * 1024);

        if (usedMemory > maxMemoryMB)
        {
            Debug.LogWarning($"High memory usage: {usedMemory}MB. Triggering cleanup.");
            Resources.UnloadUnusedAssets();
        }
    }

    public void RequestGarbageCollection()
    {
        System.GC.Collect();
    }

    public void SetQualityLevel(int level)
    {
        currentQualityLevel = Mathf.Clamp(level, lowQualityLevel, highQualityLevel);
        QualitySettings.SetQualityLevel(currentQualityLevel);
        ApplyQualitySettings(currentQualityLevel);
    }

    public int GetCurrentQualityLevel()
    {
        return currentQualityLevel;
    }

    public float GetCurrentFPS()
    {
        return currentFPS;
    }

    public void OptimizeForMenu()
    {
        // Reduce frame rate in menu
        Application.targetFrameRate = 30;
    }

    public void OptimizeForGameplay()
    {
        Application.targetFrameRate = targetFPS;
    }

    // Texture streaming
    public void SetTextureQuality(int quality)
    {
        QualitySettings.masterTextureLimit = 3 - quality; // 0=full, 3=lowest
    }

    // Particle optimization
    public void LimitParticles(ParticleSystem particles)
    {
        if (particles == null) return;

        var main = particles.main;
        main.maxParticles = Mathf.Min(main.maxParticles, (int)maxParticleCount);
    }
}
