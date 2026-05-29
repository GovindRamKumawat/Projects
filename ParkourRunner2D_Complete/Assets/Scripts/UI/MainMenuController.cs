using UnityEngine;
using UnityEngine.UI;
using TMPro;
using DG.Tweening;

public class MainMenuController : MonoBehaviour
{
    [Header("UI Elements")]
    [SerializeField] private GameObject titlePanel;
    [SerializeField] private GameObject menuButtonsPanel;
    [SerializeField] private GameObject statsPanel;
    [SerializeField] private GameObject characterPreview;

    [Header("Buttons")]
    [SerializeField] private Button playButton;
    [SerializeField] private Button shopButton;
    [SerializeField] private Button charactersButton;
    [SerializeField] private Button settingsButton;
    [SerializeField] private Button leaderboardButton;
    [SerializeField] private Button achievementsButton;

    [Header("Stats Display")]
    [SerializeField] private TextMeshProUGUI highScoreText;
    [SerializeField] private TextMeshProUGUI totalCoinsText;
    [SerializeField] private TextMeshProUGUI bestDistanceText;
    [SerializeField] private TextMeshProUGUI totalRunsText;

    [Header("Animation")]
    [SerializeField] private float animationDuration = 0.5f;
    [SerializeField] private Ease animationEase = Ease.OutBack;

    [Header("Background")]
    [SerializeField] private ParallaxBackground parallaxBackground;
    [SerializeField] private ParticleSystem ambientParticles;

    void Start()
    {
        SetupButtons();
        AnimateMenuIn();
        UpdateStats();
        PlayMenuMusic();
    }

    void SetupButtons()
    {
        playButton?.onClick.AddListener(OnPlayClicked);
        shopButton?.onClick.AddListener(OnShopClicked);
        charactersButton?.onClick.AddListener(OnCharactersClicked);
        settingsButton?.onClick.AddListener(OnSettingsClicked);
        leaderboardButton?.onClick.AddListener(OnLeaderboardClicked);
        achievementsButton?.onClick.AddListener(OnAchievementsClicked);
    }

    void AnimateMenuIn()
    {
        // Title animation
        if (titlePanel != null)
        {
            titlePanel.transform.localScale = Vector3.zero;
            titlePanel.transform.DOScale(Vector3.one, animationDuration).SetEase(animationEase);
        }

        // Buttons stagger animation
        if (menuButtonsPanel != null)
        {
            Button[] buttons = menuButtonsPanel.GetComponentsInChildren<Button>();
            for (int i = 0; i < buttons.Length; i++)
            {
                buttons[i].transform.localScale = Vector3.zero;
                buttons[i].transform.DOScale(Vector3.one, animationDuration)
                    .SetEase(animationEase)
                    .SetDelay(0.1f * i);
            }
        }

        // Stats fade in
        if (statsPanel != null)
        {
            CanvasGroup cg = statsPanel.GetComponent<CanvasGroup>();
            if (cg != null)
            {
                cg.alpha = 0;
                cg.DOFade(1, animationDuration).SetDelay(0.5f);
            }
        }
    }

    void UpdateStats()
    {
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null)
        {
            highScoreText?.SetText($"Best Score: {data.HighScore:N0}");
            totalCoinsText?.SetText($"Coins: {data.TotalCoins}");
            bestDistanceText?.SetText($"Best Distance: {data.BestDistance:F0}m");
            totalRunsText?.SetText($"Total Runs: {data.TotalRuns}");
        }
    }

    void PlayMenuMusic()
    {
        AudioManager.Instance?.PlayMusic(AudioManager.Instance.GetComponent<AudioManager>()?.menuMusic);
    }

    void OnPlayClicked()
    {
        AudioManager.Instance?.PlaySFX("Click");

        // Transition to gameplay
        StartCoroutine(LoadGameplayScene());
    }

    System.Collections.IEnumerator LoadGameplayScene()
    {
        // Fade out
        CanvasGroup cg = GetComponent<CanvasGroup>();
        if (cg == null) cg = gameObject.AddComponent<CanvasGroup>();

        cg.DOFade(0, 0.5f);

        yield return new WaitForSeconds(0.5f);

        // Load scene
        UnityEngine.SceneManagement.SceneManager.LoadScene("Gameplay");
    }

    void OnShopClicked()
    {
        AudioManager.Instance?.PlaySFX("Click");
        UIManager.Instance?.OnShopButton();
    }

    void OnCharactersClicked()
    {
        AudioManager.Instance?.PlaySFX("Click");
        UIManager.Instance?.OnCharacterSelectButton();
    }

    void OnSettingsClicked()
    {
        AudioManager.Instance?.PlaySFX("Click");
        UIManager.Instance?.OnSettingsButton();
    }

    void OnLeaderboardClicked()
    {
        AudioManager.Instance?.PlaySFX("Click");
        // Show leaderboard
    }

    void OnAchievementsClicked()
    {
        AudioManager.Instance?.PlaySFX("Click");
        // Show achievements
    }
}

// Parallax Background for Menu
public class ParallaxBackground : MonoBehaviour
{
    [SerializeField] private Transform[] layers;
    [SerializeField] private float[] parallaxSpeeds;
    [SerializeField] private float scrollSpeed = 1f;

    private Vector3 previousMousePosition;

    void Update()
    {
        // Auto scroll
        for (int i = 0; i < layers.Length; i++)
        {
            if (layers[i] != null)
            {
                layers[i].position += Vector3.left * parallaxSpeeds[i] * scrollSpeed * Time.deltaTime;

                // Loop background
                if (layers[i].position.x < -20f)
                {
                    layers[i].position += Vector3.right * 40f;
                }
            }
        }

        // Mouse parallax
        Vector3 mouseDelta = Input.mousePosition - previousMousePosition;
        for (int i = 0; i < layers.Length; i++)
        {
            if (layers[i] != null)
            {
                layers[i].position += new Vector3(mouseDelta.x * 0.001f * parallaxSpeeds[i], 0, 0);
            }
        }
        previousMousePosition = Input.mousePosition;
    }
}
