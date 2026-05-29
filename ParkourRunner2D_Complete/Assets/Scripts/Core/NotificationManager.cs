using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;
using DG.Tweening;

public class NotificationManager : MonoBehaviour
{
    public static NotificationManager Instance { get; private set; }

    [Header("Notification Prefab")]
    [SerializeField] private GameObject notificationPrefab;
    [SerializeField] private Transform notificationContainer;

    [Header("Settings")]
    [SerializeField] private float displayDuration = 3f;
    [SerializeField] private float fadeInDuration = 0.3f;
    [SerializeField] private float fadeOutDuration = 0.5f;
    [SerializeField] private float spacing = 80f;
    [SerializeField] private int maxNotifications = 5;

    [Header("Colors")]
    [SerializeField] private Color achievementColor = new Color(1f, 0.84f, 0f);
    [SerializeField] private Color warningColor = new Color(1f, 0.5f, 0f);
    [SerializeField] private Color errorColor = new Color(1f, 0.2f, 0.2f);
    [SerializeField] private Color infoColor = new Color(0.2f, 0.6f, 1f);
    [SerializeField] private Color successColor = new Color(0.2f, 1f, 0.4f);

    // Runtime
    private Queue<GameObject> activeNotifications = new Queue<GameObject>();
    private List<GameObject> notificationPool = new List<GameObject>();

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
        // Pre-instantiate pool
        for (int i = 0; i < maxNotifications; i++)
        {
            GameObject notif = Instantiate(notificationPrefab, notificationContainer);
            notif.SetActive(false);
            notificationPool.Add(notif);
        }
    }

    public void ShowNotification(string message, NotificationType type = NotificationType.Info)
    {
        ShowNotification(message, null, type);
    }

    public void ShowNotification(string message, Sprite icon, NotificationType type = NotificationType.Info)
    {
        GameObject notif = GetNotificationFromPool();
        if (notif == null) return;

        // Setup notification
        SetupNotification(notif, message, icon, type);

        // Position
        PositionNotification(notif);

        // Show
        notif.SetActive(true);

        // Animate in
        AnimateNotificationIn(notif);

        // Auto hide
        StartCoroutine(HideNotificationAfterDelay(notif, displayDuration));
    }

    public void ShowAchievement(string achievementName, string description)
    {
        ShowNotification($"Achievement Unlocked: {achievementName}", null, NotificationType.Achievement);
    }

    public void ShowCombo(int comboCount)
    {
        ShowNotification($"{comboCount}x Combo!", null, NotificationType.Success);
    }

    public void ShowLevelUp(int newLevel)
    {
        ShowNotification($"Level Up! You are now level {newLevel}", null, NotificationType.Success);
    }

    public void ShowCoinReward(int amount)
    {
        ShowNotification($"+{amount} Coins", null, NotificationType.Success);
    }

    public void ShowError(string message)
    {
        ShowNotification(message, null, NotificationType.Error);
    }

    public void ShowWarning(string message)
    {
        ShowNotification(message, null, NotificationType.Warning);
    }

    GameObject GetNotificationFromPool()
    {
        // Find inactive notification
        foreach (var notif in notificationPool)
        {
            if (!notif.activeInHierarchy)
                return notif;
        }

        // If all active, reuse oldest
        if (activeNotifications.Count > 0)
        {
            GameObject oldest = activeNotifications.Dequeue();
            return oldest;
        }

        return null;
    }

    void SetupNotification(GameObject notif, string message, Sprite icon, NotificationType type)
    {
        // Get components
        TextMeshProUGUI text = notif.GetComponentInChildren<TextMeshProUGUI>();
        Image bg = notif.GetComponent<Image>();
        Image iconImage = notif.transform.Find("Icon")?.GetComponent<Image>();

        // Set text
        if (text != null)
        {
            text.text = message;
        }

        // Set icon
        if (iconImage != null)
        {
            iconImage.sprite = icon;
            iconImage.gameObject.SetActive(icon != null);
        }

        // Set color based on type
        if (bg != null)
        {
            switch (type)
            {
                case NotificationType.Achievement:
                    bg.color = achievementColor;
                    break;
                case NotificationType.Warning:
                    bg.color = warningColor;
                    break;
                case NotificationType.Error:
                    bg.color = errorColor;
                    break;
                case NotificationType.Info:
                    bg.color = infoColor;
                    break;
                case NotificationType.Success:
                    bg.color = successColor;
                    break;
            }
        }
    }

    void PositionNotification(GameObject notif)
    {
        RectTransform rt = notif.GetComponent<RectTransform>();
        if (rt == null) return;

        // Stack from top
        int index = activeNotifications.Count;
        float yPos = -index * spacing;

        rt.anchoredPosition = new Vector2(0, yPos);
    }

    void AnimateNotificationIn(GameObject notif)
    {
        RectTransform rt = notif.GetComponent<RectTransform>();
        CanvasGroup cg = notif.GetComponent<CanvasGroup>();
        if (cg == null) cg = notif.AddComponent<CanvasGroup>();

        cg.alpha = 0;
        rt.localScale = Vector3.one * 0.8f;

        cg.DOFade(1, fadeInDuration);
        rt.DOScale(Vector3.one, fadeInDuration).SetEase(Ease.OutBack);

        activeNotifications.Enqueue(notif);
    }

    IEnumerator HideNotificationAfterDelay(GameObject notif, float delay)
    {
        yield return new WaitForSeconds(delay);

        if (notif != null)
        {
            AnimateNotificationOut(notif);
        }
    }

    void AnimateNotificationOut(GameObject notif)
    {
        CanvasGroup cg = notif.GetComponent<CanvasGroup>();
        RectTransform rt = notif.GetComponent<RectTransform>();

        if (cg != null)
        {
            cg.DOFade(0, fadeOutDuration).OnComplete(() => {
                notif.SetActive(false);
            });
        }

        if (rt != null)
        {
            rt.DOAnchorPosX(rt.anchoredPosition.x + 200, fadeOutDuration);
        }

        // Reposition remaining notifications
        RepositionNotifications();
    }

    void RepositionNotifications()
    {
        GameObject[] notifications = activeNotifications.ToArray();
        activeNotifications.Clear();

        for (int i = 0; i < notifications.Length; i++)
        {
            if (notifications[i] != null && notifications[i].activeInHierarchy)
            {
                RectTransform rt = notifications[i].GetComponent<RectTransform>();
                if (rt != null)
                {
                    float yPos = -i * spacing;
                    rt.DOAnchorPosY(yPos, 0.3f);
                }

                activeNotifications.Enqueue(notifications[i]);
            }
        }
    }
}

public enum NotificationType
{
    Achievement,
    Warning,
    Error,
    Info,
    Success
}
