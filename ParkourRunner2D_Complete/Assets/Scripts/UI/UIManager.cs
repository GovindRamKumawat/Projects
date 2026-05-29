using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using DG.Tweening;

public class UIManager : MonoBehaviour
{
    [Header("Screens")]
    [SerializeField] private GameObject mainMenuScreen;
    [SerializeField] private GameObject gameplayScreen;
    [SerializeField] private GameObject pauseScreen;
    [SerializeField] private GameObject gameOverScreen;
    [SerializeField] private GameObject checkpointScreen;
    [SerializeField] private GameObject settingsScreen;
    [SerializeField] private GameObject shopScreen;
    [SerializeField] private GameObject characterSelectScreen;
    [SerializeField] private GameObject loadingScreen;

    [Header("HUD Elements")]
    [SerializeField] private TextMeshProUGUI scoreText;
    [SerializeField] private TextMeshProUGUI coinText;
    [SerializeField] private TextMeshProUGUI distanceText;
    [SerializeField] private TextMeshProUGUI comboText;
    [SerializeField] private Slider staminaSlider;
    [SerializeField] private Slider progressSlider;
    [SerializeField] private Image staminaFill;
    [SerializeField] private Image comboFill;

    [Header("Game Over")]
    [SerializeField] private TextMeshProUGUI finalScoreText;
    [SerializeField] private TextMeshProUGUI finalDistanceText;
    [SerializeField] private TextMeshProUGUI highScoreText;
    [SerializeField] private TextMeshProUGUI coinsEarnedText;

    [Header("Main Menu")]
    [SerializeField] private TextMeshProUGUI menuHighScoreText;
    [SerializeField] private TextMeshProUGUI menuTotalCoinsText;
    [SerializeField] private TextMeshProUGUI menuBestDistanceText;

    [Header("Mobile Controls")]
    [SerializeField] private GameObject mobileControlsPanel;
    [SerializeField] private Button jumpButton;
    [SerializeField] private Button slideButton;
    [SerializeField] private Button dashButton;
    [SerializeField] private Button grappleButton;

    [Header("Animation Settings")]
    [SerializeField] private float screenTransitionTime = 0.3f;
    [SerializeField] private Ease screenTransitionEase = Ease.OutQuad;

    [Header("Combo Display")]
    [SerializeField] private float comboDisplayDuration = 1.5f;
    [SerializeField] private Vector3 comboPopupScale = new Vector3(1.5f, 1.5f, 1.5f);

    // Runtime
    private CanvasGroup currentScreen;
    private int currentCombo = 0;
    private Coroutine comboCoroutine;

    void Awake()
    {
        // Subscribe to events
        GameManager.OnGameStateChanged += OnGameStateChanged;

        if (GameManager.Instance?.Player != null)
        {
            GameManager.Instance.Player.OnComboUpdate += OnComboUpdate;
            GameManager.Instance.Player.OnParkourMove += OnParkourMove;
        }
    }

    void Start()
    {
        InitializeUI();
        SetupMobileControls();
    }

    void OnDestroy()
    {
        GameManager.OnGameStateChanged -= OnGameStateChanged;

        if (GameManager.Instance?.Player != null)
        {
            GameManager.Instance.Player.OnComboUpdate -= OnComboUpdate;
            GameManager.Instance.Player.OnParkourMove -= OnParkourMove;
        }
    }

    void InitializeUI()
    {
        // Hide all screens
        HideAllScreens();

        // Show main menu
        ShowScreen(mainMenuScreen);

        // Update menu stats
        UpdateMenuStats();

        // Hide mobile controls on non-mobile
        #if UNITY_STANDALONE
        mobileControlsPanel?.SetActive(false);
        #else
        mobileControlsPanel?.SetActive(true);
        #endif
    }

    void SetupMobileControls()
    {
        jumpButton?.onClick.AddListener(() => {
            // Simulate jump input
            // This would be connected to player input system
        });

        slideButton?.onClick.AddListener(() => {
            // Simulate slide input
        });

        dashButton?.onClick.AddListener(() => {
            GameManager.Instance?.Player?.PerformDash();
        });

        grappleButton?.onClick.AddListener(() => {
            // Simulate grapple input
        });
    }

    void OnGameStateChanged(GameState state)
    {
        switch (state)
        {
            case GameState.MainMenu:
                HideAllScreens();
                ShowScreen(mainMenuScreen);
                UpdateMenuStats();
                break;

            case GameState.Playing:
                HideAllScreens();
                ShowScreen(gameplayScreen);
                ResetHUD();
                break;

            case GameState.Paused:
                ShowScreen(pauseScreen);
                break;

            case GameState.GameOver:
                ShowScreen(gameOverScreen);
                break;

            case GameState.Checkpoint:
                ShowScreen(checkpointScreen);
                break;
        }
    }

    void HideAllScreens()
    {
        mainMenuScreen?.SetActive(false);
        gameplayScreen?.SetActive(false);
        pauseScreen?.SetActive(false);
        gameOverScreen?.SetActive(false);
        checkpointScreen?.SetActive(false);
        settingsScreen?.SetActive(false);
        shopScreen?.SetActive(false);
        characterSelectScreen?.SetActive(false);
        loadingScreen?.SetActive(false);
    }

    void ShowScreen(GameObject screen)
    {
        if (screen == null) return;

        screen.SetActive(true);

        // Animate in
        CanvasGroup cg = screen.GetComponent<CanvasGroup>();
        if (cg == null) cg = screen.AddComponent<CanvasGroup>();

        cg.alpha = 0;
        cg.DOFade(1, screenTransitionTime).SetEase(screenTransitionEase);

        // Scale animation
        RectTransform rt = screen.GetComponent<RectTransform>();
        if (rt != null)
        {
            rt.localScale = Vector3.one * 0.9f;
            rt.DOScale(Vector3.one, screenTransitionTime).SetEase(screenTransitionEase);
        }
    }

    void ResetHUD()
    {
        scoreText.text = "0";
        coinText.text = "0";
        distanceText.text = "0m";
        comboText.text = "";
        comboText.gameObject.SetActive(false);

        if (staminaSlider != null)
            staminaSlider.value = 1f;

        if (progressSlider != null)
            progressSlider.value = 0f;
    }

    // HUD Updates
    public void UpdateScore(int score)
    {
        if (scoreText != null)
        {
            scoreText.text = score.ToString("N0");

            // Pop animation
            scoreText.transform.DOPunchScale(Vector3.one * 0.2f, 0.2f, 1);
        }
    }

    public void UpdateCoins(int coins)
    {
        if (coinText != null)
        {
            coinText.text = coins.ToString();
            coinText.transform.DOPunchScale(Vector3.one * 0.3f, 0.2f, 1);
        }
    }

    public void UpdateDistance(float distance)
    {
        if (distanceText != null)
        {
            distanceText.text = $"{distance:F0}m";
        }
    }

    void OnComboUpdate(int combo)
    {
        currentCombo = combo;

        if (combo > 1)
        {
            ShowCombo(combo);
        }
    }

    void OnParkourMove(string moveName)
    {
        // Show move name briefly
        // Could add a floating text system here
    }

    void ShowCombo(int combo)
    {
        if (comboText == null) return;

        comboText.gameObject.SetActive(true);
        comboText.text = $"{combo}x COMBO!";

        // Animate
        comboText.transform.localScale = Vector3.one;
        comboText.transform.DOPunchScale(comboPopupScale, 0.3f, 1);

        // Color based on combo
        if (combo >= 10)
            comboText.color = Color.red;
        else if (combo >= 5)
            comboText.color = Color.yellow;
        else
            comboText.color = Color.white;

        // Reset timer
        if (comboCoroutine != null)
            StopCoroutine(comboCoroutine);

        comboCoroutine = StartCoroutine(HideComboAfterDelay());
    }

    IEnumerator HideComboAfterDelay()
    {
        yield return new WaitForSeconds(comboDisplayDuration);

        if (comboText != null)
        {
            comboText.DOFade(0, 0.3f).OnComplete(() => {
                comboText.gameObject.SetActive(false);
                comboText.alpha = 1;
            });
        }
    }

    public void UpdateStamina(float current, float max)
    {
        if (staminaSlider != null)
        {
            staminaSlider.value = current / max;

            // Color change based on stamina
            if (staminaFill != null)
            {
                staminaFill.color = Color.Lerp(Color.red, Color.green, current / max);
            }
        }
    }

    public void UpdateProgress(float progress)
    {
        if (progressSlider != null)
        {
            progressSlider.value = progress;
        }
    }

    // Game Over Screen
    public void ShowGameOver(int score, float distance)
    {
        if (finalScoreText != null)
            finalScoreText.text = $"Score: {score:N0}";

        if (finalDistanceText != null)
            finalDistanceText.text = $"Distance: {distance:F0}m";

        // Get high score
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null)
        {
            if (highScoreText != null)
                highScoreText.text = $"Best: {data.HighScore:N0}";

            if (coinsEarnedText != null)
                coinsEarnedText.text = $"+{score / 100} Coins";
        }

        // Animate in
        ShowScreen(gameOverScreen);
    }

    void UpdateMenuStats()
    {
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null)
        {
            if (menuHighScoreText != null)
                menuHighScoreText.text = $"Best Score: {data.HighScore:N0}";

            if (menuTotalCoinsText != null)
                menuTotalCoinsText.text = $"Coins: {data.TotalCoins}";

            if (menuBestDistanceText != null)
                menuBestDistanceText.text = $"Best Distance: {data.BestDistance:F0}m";
        }
    }

    // Button Handlers
    public void OnPlayButton()
    {
        AudioManager.Instance?.PlaySFX("Click");
        GameManager.Instance?.StartGame();
    }

    public void OnPauseButton()
    {
        AudioManager.Instance?.PlaySFX("Click");
        GameManager.Instance?.TogglePause();
    }

    public void OnResumeButton()
    {
        AudioManager.Instance?.PlaySFX("Click");
        GameManager.Instance?.TogglePause();
    }

    public void OnRestartButton()
    {
        AudioManager.Instance?.PlaySFX("Click");
        GameManager.Instance?.StartGame();
    }

    public void OnMainMenuButton()
    {
        AudioManager.Instance?.PlaySFX("Click");
        GameManager.Instance?.ChangeState(GameState.MainMenu);
    }

    public void OnSettingsButton()
    {
        AudioManager.Instance?.PlaySFX("Click");
        settingsScreen?.SetActive(true);
    }

    public void OnShopButton()
    {
        AudioManager.Instance?.PlaySFX("Click");
        shopScreen?.SetActive(true);
    }

    public void OnCharacterSelectButton()
    {
        AudioManager.Instance?.PlaySFX("Click");
        characterSelectScreen?.SetActive(true);
    }

    public void OnCloseSettings()
    {
        AudioManager.Instance?.PlaySFX("Click");
        settingsScreen?.SetActive(false);
    }

    public void OnCloseShop()
    {
        AudioManager.Instance?.PlaySFX("Click");
        shopScreen?.SetActive(false);
    }

    public void OnCloseCharacterSelect()
    {
        AudioManager.Instance?.PlaySFX("Click");
        characterSelectScreen?.SetActive(false);
    }

    public void ShowLoadingScreen(bool show)
    {
        loadingScreen?.SetActive(show);
    }

    // Settings handlers
    public void OnMusicVolumeChanged(float value)
    {
        AudioManager.Instance?.SetMusicVolume(value);
    }

    public void OnSFXVolumeChanged(float value)
    {
        AudioManager.Instance?.SetSFXVolume(value);
    }

    public void OnVibrationToggle(bool enabled)
    {
        // Save vibration setting
    }

    public void OnGraphicsQualityChanged(int quality)
    {
        QualitySettings.SetQualityLevel(quality);
    }
}
