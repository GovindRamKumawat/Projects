using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.SceneManagement;
using DG.Tweening;
using System.Collections;

public class LoadingManager : MonoBehaviour
{
    public static LoadingManager Instance { get; private set; }

    [Header("UI Elements")]
    [SerializeField] private GameObject loadingPanel;
    [SerializeField] private Slider progressBar;
    [SerializeField] private TextMeshProUGUI progressText;
    [SerializeField] private TextMeshProUGUI tipText;
    [SerializeField] private TextMeshProUGUI loadingTitle;

    [Header("Tips")]
    [SerializeField] private string[] loadingTips;

    [Header("Animation")]
    [SerializeField] private float fadeInDuration = 0.3f;
    [SerializeField] private float fadeOutDuration = 0.3f;

    // Runtime
    private CanvasGroup canvasGroup;
    private bool isLoading = false;

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

        canvasGroup = loadingPanel?.GetComponent<CanvasGroup>();
        if (canvasGroup == null && loadingPanel != null)
            canvasGroup = loadingPanel.AddComponent<CanvasGroup>();

        loadingPanel?.SetActive(false);
    }

    public void LoadScene(string sceneName)
    {
        if (isLoading) return;
        StartCoroutine(LoadSceneCoroutine(sceneName));
    }

    public void LoadScene(int sceneIndex)
    {
        if (isLoading) return;
        StartCoroutine(LoadSceneCoroutine(sceneIndex));
    }

    IEnumerator LoadSceneCoroutine(string sceneName)
    {
        isLoading = true;

        // Show loading screen
        ShowLoadingScreen();

        // Start async load
        AsyncOperation operation = SceneManager.LoadSceneAsync(sceneName);
        operation.allowSceneActivation = false;

        // Update progress
        while (operation.progress < 0.9f)
        {
            float progress = Mathf.Clamp01(operation.progress / 0.9f);
            UpdateProgress(progress);
            yield return null;
        }

        // Fake extra loading time for smooth transition
        float fakeProgress = 0.9f;
        while (fakeProgress < 1f)
        {
            fakeProgress += Time.deltaTime * 0.5f;
            UpdateProgress(fakeProgress);
            yield return null;
        }

        // Activate scene
        operation.allowSceneActivation = true;

        // Hide loading screen
        yield return new WaitForSeconds(0.5f);
        HideLoadingScreen();

        isLoading = false;
    }

    IEnumerator LoadSceneCoroutine(int sceneIndex)
    {
        isLoading = true;

        ShowLoadingScreen();

        AsyncOperation operation = SceneManager.LoadSceneAsync(sceneIndex);
        operation.allowSceneActivation = false;

        while (operation.progress < 0.9f)
        {
            float progress = Mathf.Clamp01(operation.progress / 0.9f);
            UpdateProgress(progress);
            yield return null;
        }

        float fakeProgress = 0.9f;
        while (fakeProgress < 1f)
        {
            fakeProgress += Time.deltaTime * 0.5f;
            UpdateProgress(fakeProgress);
            yield return null;
        }

        operation.allowSceneActivation = true;

        yield return new WaitForSeconds(0.5f);
        HideLoadingScreen();

        isLoading = false;
    }

    void ShowLoadingScreen()
    {
        if (loadingPanel == null) return;

        loadingPanel.SetActive(true);

        // Random tip
        if (tipText != null && loadingTips.Length > 0)
        {
            tipText.text = loadingTips[Random.Range(0, loadingTips.Length)];
        }

        // Reset progress
        UpdateProgress(0);

        // Fade in
        if (canvasGroup != null)
        {
            canvasGroup.alpha = 0;
            canvasGroup.DOFade(1, fadeInDuration);
        }
    }

    void HideLoadingScreen()
    {
        if (loadingPanel == null) return;

        // Fade out
        if (canvasGroup != null)
        {
            canvasGroup.DOFade(0, fadeOutDuration).OnComplete(() => {
                loadingPanel.SetActive(false);
            });
        }
        else
        {
            loadingPanel.SetActive(false);
        }
    }

    void UpdateProgress(float progress)
    {
        if (progressBar != null)
        {
            progressBar.value = progress;
        }

        if (progressText != null)
        {
            progressText.text = $"{progress * 100:F0}%";
        }
    }

    public bool IsLoading()
    {
        return isLoading;
    }
}

// Scene Transition Effect
public class SceneTransition : MonoBehaviour
{
    [Header("Transition Settings")]
    [SerializeField] private float transitionDuration = 0.5f;
    [SerializeField] private Color fadeColor = Color.black;

    [Header("Optional")]
    [SerializeField] private Image transitionImage;
    [SerializeField] private Animator transitionAnimator;

    public static SceneTransition Instance { get; private set; }

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
        }
    }

    public void FadeIn(System.Action onComplete = null)
    {
        if (transitionAnimator != null)
        {
            transitionAnimator.SetTrigger("FadeIn");
            StartCoroutine(WaitForAnimation(onComplete));
        }
        else if (transitionImage != null)
        {
            transitionImage.color = new Color(fadeColor.r, fadeColor.g, fadeColor.b, 0);
            transitionImage.DOFade(1, transitionDuration).OnComplete(() => {
                onComplete?.Invoke();
            });
        }
    }

    public void FadeOut(System.Action onComplete = null)
    {
        if (transitionAnimator != null)
        {
            transitionAnimator.SetTrigger("FadeOut");
            StartCoroutine(WaitForAnimation(onComplete));
        }
        else if (transitionImage != null)
        {
            transitionImage.DOFade(0, transitionDuration).OnComplete(() => {
                onComplete?.Invoke();
            });
        }
    }

    IEnumerator WaitForAnimation(System.Action onComplete)
    {
        yield return new WaitForSeconds(transitionDuration);
        onComplete?.Invoke();
    }
}
