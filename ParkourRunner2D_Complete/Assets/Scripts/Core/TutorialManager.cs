using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;

public class TutorialManager : MonoBehaviour
{
    public static TutorialManager Instance { get; private set; }

    [Header("Tutorial Steps")]
    [SerializeField] private TutorialStep[] tutorialSteps;

    [Header("UI Elements")]
    [SerializeField] private GameObject tutorialPanel;
    [SerializeField] private TextMeshProUGUI instructionText;
    [SerializeField] private TextMeshProUGUI stepCounterText;
    [SerializeField] private Image highlightImage;
    [SerializeField] private Button skipButton;
    [SerializeField] private Button nextButton;

    [Header("Settings")]
    [SerializeField] private bool showTutorialOnFirstPlay = true;
    [SerializeField] private bool pauseGameDuringTutorial = true;
    [SerializeField] private float autoAdvanceDelay = 2f;

    // Runtime
    private int currentStep = 0;
    private bool isTutorialActive = false;
    private bool waitingForInput = false;

    [System.Serializable]
    public class TutorialStep
    {
        public string stepName;
        [TextArea] public string instruction;
        public TutorialAction requiredAction;
        public Transform highlightTarget;
        public Vector2 highlightSize = new Vector2(200, 100);
        public bool autoAdvance = false;
        public float displayDuration = 3f;
        public AudioClip voiceOver;
    }

    public enum TutorialAction
    {
        None,
        Tap,
        SwipeUp,
        SwipeDown,
        SwipeRight,
        DoubleTap,
        Jump,
        Slide,
        Dash,
        CollectCoin,
        AvoidObstacle,
        KillEnemy,
        ReachCheckpoint
    }

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
    }

    void Start()
    {
        skipButton?.onClick.AddListener(SkipTutorial);
        nextButton?.onClick.AddListener(NextStep);

        // Check if tutorial should show
        if (showTutorialOnFirstPlay && PlayerPrefs.GetInt("TutorialCompleted", 0) == 0)
        {
            StartTutorial();
        }
    }

    public void StartTutorial()
    {
        if (tutorialSteps.Length == 0) return;

        isTutorialActive = true;
        currentStep = 0;

        if (pauseGameDuringTutorial)
        {
            Time.timeScale = 0.1f; // Slow motion instead of full pause
        }

        tutorialPanel?.SetActive(true);

        ShowStep(0);
    }

    void ShowStep(int stepIndex)
    {
        if (stepIndex >= tutorialSteps.Length)
        {
            CompleteTutorial();
            return;
        }

        currentStep = stepIndex;
        TutorialStep step = tutorialSteps[stepIndex];

        // Update UI
        if (instructionText != null)
        {
            instructionText.text = step.instruction;
        }

        if (stepCounterText != null)
        {
            stepCounterText.text = $"{stepIndex + 1}/{tutorialSteps.Length}";
        }

        // Highlight target
        if (highlightImage != null && step.highlightTarget != null)
        {
            highlightImage.gameObject.SetActive(true);
            highlightImage.rectTransform.position = step.highlightTarget.position;
            highlightImage.rectTransform.sizeDelta = step.highlightSize;
        }
        else if (highlightImage != null)
        {
            highlightImage.gameObject.SetActive(false);
        }

        // Play voice over
        if (step.voiceOver != null)
        {
            AudioManager.Instance?.PlaySFX(step.voiceOver);
        }

        // Auto advance
        if (step.autoAdvance)
        {
            StartCoroutine(AutoAdvanceStep(step.displayDuration));
        }
        else
        {
            waitingForInput = true;
        }
    }

    IEnumerator AutoAdvanceStep(float delay)
    {
        yield return new WaitForSecondsRealtime(delay);
        NextStep();
    }

    public void NextStep()
    {
        if (!isTutorialActive) return;

        ShowStep(currentStep + 1);
    }

    public void CompleteTutorial()
    {
        isTutorialActive = false;

        if (pauseGameDuringTutorial)
        {
            Time.timeScale = 1f;
        }

        tutorialPanel?.SetActive(false);

        // Save completion
        PlayerPrefs.SetInt("TutorialCompleted", 1);
        PlayerPrefs.Save();

        AudioManager.Instance?.PlaySFX("TutorialComplete");
    }

    public void SkipTutorial()
    {
        CompleteTutorial();
    }

    public void OnActionPerformed(TutorialAction action)
    {
        if (!isTutorialActive || !waitingForInput) return;

        if (currentStep < tutorialSteps.Length)
        {
            if (tutorialSteps[currentStep].requiredAction == action)
            {
                waitingForInput = false;
                NextStep();
            }
        }
    }

    public bool IsTutorialActive()
    {
        return isTutorialActive;
    }

    public void ResetTutorial()
    {
        PlayerPrefs.SetInt("TutorialCompleted", 0);
    }
}
