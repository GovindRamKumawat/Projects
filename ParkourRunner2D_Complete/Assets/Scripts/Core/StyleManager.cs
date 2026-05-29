using UnityEngine;

[CreateAssetMenu(fileName = "NewStyle", menuName = "Parkour Runner/Style Data")]
public class StyleData : ScriptableObject
{
    [Header("Basic Info")]
    public string styleName = "Freerunner";
    public string description = "Classic parkour style";
    public Sprite icon;

    [Header("Visual Effects")]
    public Color trailColor = Color.white;
    public Gradient trailGradient;
    public ParticleSystem trailEffect;
    public ParticleSystem landingEffect;
    public ParticleSystem dashEffect;
    public ParticleSystem jumpEffect;

    [Header("Animation Overrides")]
    public AnimationClip[] customAnimations;
    public float animationSpeedMultiplier = 1f;

    [Header("Movement Modifiers")]
    public float speedMultiplier = 1f;
    public float jumpHeightMultiplier = 1f;
    public float gravityMultiplier = 1f;
    public float dashDistanceMultiplier = 1f;

    [Header("Style Scoring")]
    public float styleMultiplier = 1f;
    public float comboBonus = 0f;
    public string[] styleMoveNames;

    [Header("Audio")]
    public AudioClip[] moveSounds;
    public AudioClip dashSound;
    public AudioClip landSound;
    public AudioClip styleMusic;

    [Header("UI")]
    public Color uiPrimaryColor = Color.white;
    public Color uiSecondaryColor = Color.gray;
    public Sprite styleBackground;

    [Header("Unlock")]
    public int unlockCost = 0;
    public string unlockCondition = "Default";
    public bool isUnlocked = true;
    public int requiredLevel = 1;
}

public class StyleManager : MonoBehaviour
{
    public static StyleManager Instance { get; private set; }

    [Header("Styles")]
    [SerializeField] private StyleData[] styles;
    [SerializeField] private int selectedStyleIndex = 0;

    [Header("Default Style")]
    [SerializeField] private StyleData defaultStyle;

    // Events
    public System.Action<StyleData> OnStyleSelected;
    public System.Action<StyleData> OnStyleUnlocked;

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

        LoadStyleProgress();
    }

    void LoadStyleProgress()
    {
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null && data.UnlockedStyles != null)
        {
            for (int i = 0; i < styles.Length && i < data.UnlockedStyles.Length; i++)
            {
                styles[i].isUnlocked = data.UnlockedStyles[i];
            }
        }
    }

    public void SelectStyle(int index)
    {
        if (index < 0 || index >= styles.Length) return;

        StyleData style = styles[index];

        if (!style.isUnlocked)
        {
            Debug.Log($"Style {style.styleName} is locked!");
            return;
        }

        selectedStyleIndex = index;

        // Apply style effects
        ApplyStyle(style);

        OnStyleSelected?.Invoke(style);

        PlayerPrefs.SetInt("SelectedStyle", index);
    }

    void ApplyStyle(StyleData style)
    {
        // Apply to player
        PlayerController player = GameManager.Instance?.Player;
        if (player == null) return;

        // Apply trail color
        TrailRenderer trail = player.GetComponentInChildren<TrailRenderer>();
        if (trail != null)
        {
            trail.startColor = style.trailColor;
            trail.endColor = new Color(style.trailColor.r, style.trailColor.g, style.trailColor.b, 0);
        }

        // Apply UI colors
        UIManager ui = GameManager.Instance?.UI;
        if (ui != null)
        {
            // Update UI theme
        }

        // Play style music
        if (style.styleMusic != null)
        {
            AudioManager.Instance?.PlayMusic(style.styleMusic);
        }
    }

    public bool UnlockStyle(int index)
    {
        if (index < 0 || index >= styles.Length) return false;

        StyleData style = styles[index];

        if (style.isUnlocked) return true;

        int coins = GameManager.Instance?.Coins ?? 0;

        if (coins >= style.unlockCost)
        {
            GameManager.Instance?.AddCoins(-style.unlockCost);
            style.isUnlocked = true;

            SaveManager.Instance?.UnlockStyle(index);

            OnStyleUnlocked?.Invoke(style);

            AudioManager.Instance?.PlaySFX("Unlock");

            return true;
        }

        return false;
    }

    public StyleData GetSelectedStyle()
    {
        if (selectedStyleIndex >= 0 && selectedStyleIndex < styles.Length)
        {
            return styles[selectedStyleIndex];
        }
        return defaultStyle;
    }

    public StyleData GetStyle(int index)
    {
        if (index >= 0 && index < styles.Length)
        {
            return styles[index];
        }
        return null;
    }

    public StyleData[] GetAllStyles()
    {
        return styles;
    }

    public int GetSelectedIndex()
    {
        return selectedStyleIndex;
    }

    public float GetStyleMultiplier()
    {
        return GetSelectedStyle()?.styleMultiplier ?? 1f;
    }
}
