using UnityEngine;

public interface ICollectible
{
    void Collect();
    int GetValue();
    CollectibleType GetCollectibleType();
}

public enum CollectibleType
{
    Coin,
    TechPart,
    StylePoint,
    RareToken,
    HealthPack,
    Shield,
    Magnet,
    ScoreMultiplier,
    SpeedBoost,
    LoreItem,
    SecretItem
}

public class CollectibleBase : MonoBehaviour, ICollectible
{
    [Header("Collectible Settings")]
    [SerializeField] protected CollectibleType collectibleType = CollectibleType.Coin;
    [SerializeField] protected int value = 1;
    [SerializeField] protected float lifeTime = 0f; // 0 = infinite
    [SerializeField] protected bool magnetAttract = true;
    [SerializeField] protected float magnetRange = 5f;
    [SerializeField] protected float magnetSpeed = 10f;

    [Header("Visual")]
    [SerializeField] protected SpriteRenderer spriteRenderer;
    [SerializeField] protected ParticleSystem collectEffect;
    [SerializeField] protected AnimationCurve floatCurve;
    [SerializeField] protected float floatSpeed = 2f;
    [SerializeField] protected float floatAmplitude = 0.3f;

    [Header("Audio")]
    [SerializeField] protected AudioClip collectSound;

    // Runtime
    protected float startY;
    protected float floatOffset;
    protected bool isCollected = false;
    protected Transform player;

    protected virtual void Awake()
    {
        spriteRenderer = GetComponent<SpriteRenderer>();
        startY = transform.position.y;
        floatOffset = Random.Range(0f, Mathf.PI * 2f);
    }

    protected virtual void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player")?.transform;
    }

    protected virtual void Update()
    {
        if (isCollected) return;

        // Floating animation
        float y = startY + Mathf.Sin(Time.time * floatSpeed + floatOffset) * floatAmplitude;
        transform.position = new Vector3(transform.position.x, y, transform.position.z);

        // Magnet effect
        if (magnetAttract && player != null)
        {
            float distance = Vector2.Distance(transform.position, player.position);

            if (distance < magnetRange)
            {
                // Move towards player
                Vector2 direction = (player.position - transform.position).normalized;
                transform.position = Vector2.MoveTowards(
                    transform.position,
                    player.position,
                    magnetSpeed * Time.deltaTime
                );
            }
        }

        // Lifetime
        if (lifeTime > 0)
        {
            lifeTime -= Time.deltaTime;
            if (lifeTime <= 0)
            {
                Destroy(gameObject);
            }
        }
    }

    public virtual void Collect()
    {
        if (isCollected) return;
        isCollected = true;

        // Play effect
        if (collectEffect != null)
        {
            Instantiate(collectEffect, transform.position, Quaternion.identity);
        }

        // Play sound
        if (collectSound != null)
        {
            AudioManager.Instance?.PlaySFX(collectSound);
        }
        else
        {
            AudioManager.Instance?.PlaySFX("Coin");
        }

        // Apply effect
        ApplyEffect();

        // Destroy
        Destroy(gameObject);
    }

    protected virtual void ApplyEffect()
    {
        // Override in derived classes
    }

    public virtual int GetValue()
    {
        return value;
    }

    public CollectibleType GetCollectibleType()
    {
        return collectibleType;
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Player"))
        {
            Collect();
        }
    }
}

// Specific Collectible Types

public class CoinCollectible : CollectibleBase
{
    [Header("Coin Settings")]
    [SerializeField] private bool isGoldCoin = true;
    [SerializeField] private int coinValue = 1;

    protected override void Awake()
    {
        base.Awake();
        collectibleType = CollectibleType.Coin;
        value = coinValue;

        // Set color based on type
        if (spriteRenderer != null)
        {
            spriteRenderer.color = isGoldCoin ? Color.yellow : new Color(0.7f, 0.7f, 0.7f);
        }
    }

    protected override void ApplyEffect()
    {
        GameManager.Instance?.AddCoins(value);

        // Style multiplier
        float multiplier = StyleManager.Instance?.GetStyleMultiplier() ?? 1f;
        int bonus = Mathf.RoundToInt(value * (multiplier - 1));
        if (bonus > 0)
        {
            GameManager.Instance?.AddCoins(bonus);
        }
    }
}

public class PowerUpCollectible : CollectibleBase
{
    [Header("Power-up Settings")]
    [SerializeField] private PowerUpType powerUpType = PowerUpType.Shield;
    [SerializeField] private float duration = 10f;

    protected override void ApplyEffect()
    {
        PlayerController player = GameManager.Instance?.Player;
        if (player == null) return;

        switch (powerUpType)
        {
            case PowerUpType.Shield:
                // player.ActivateShield(duration);
                break;
            case PowerUpType.Magnet:
                // player.ActivateMagnet(duration);
                break;
            case PowerUpType.ScoreMultiplier:
                // player.ActivateScoreMultiplier(duration, 2f);
                break;
            case PowerUpType.SpeedBoost:
                // player.ActivateSpeedBoost(duration, 1.5f);
                break;
        }

        AudioManager.Instance?.PlaySFX("PowerUp");
    }
}

public enum PowerUpType
{
    Shield,
    Magnet,
    ScoreMultiplier,
    SpeedBoost
}

public class LoreCollectible : CollectibleBase
{
    [Header("Lore Settings")]
    [SerializeField] private string loreTitle = "Unknown";
    [SerializeField] [TextArea] private string loreText = "";
    [SerializeField] private Sprite loreImage;
    [SerializeField] private int loreIndex = 0;

    protected override void Awake()
    {
        base.Awake();
        collectibleType = CollectibleType.LoreItem;
        magnetAttract = false; // Lore items don't magnet
    }

    protected override void ApplyEffect()
    {
        // Unlock lore
        // LoreManager.Instance?.UnlockLore(loreIndex, loreTitle, loreText, loreImage);

        GameManager.Instance?.AddScore(500); // Bonus score for lore

        // Show lore popup
        // UIManager.Instance?.ShowLorePopup(loreTitle, loreText, loreImage);
    }
}

public class HealthCollectible : CollectibleBase
{
    [Header("Health Settings")]
    [SerializeField] private int healthAmount = 1;

    protected override void Awake()
    {
        base.Awake();
        collectibleType = CollectibleType.HealthPack;
    }

    protected override void ApplyEffect()
    {
        // player.Heal(healthAmount);
        AudioManager.Instance?.PlaySFX("Heal");
    }
}
