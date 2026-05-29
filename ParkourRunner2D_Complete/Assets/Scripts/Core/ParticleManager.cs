using UnityEngine;
using System.Collections.Generic;

public class ParticleManager : MonoBehaviour
{
    public static ParticleManager Instance { get; private set; }

    [Header("Player Effects")]
    [SerializeField] private ParticleSystem runDustEffect;
    [SerializeField] private ParticleSystem jumpEffect;
    [SerializeField] private ParticleSystem landEffect;
    [SerializeField] private ParticleSystem slideEffect;
    [SerializeField] private ParticleSystem dashEffect;
    [SerializeField] private ParticleSystem wallRunEffect;
    [SerializeField] private ParticleSystem deathEffect;
    [SerializeField] private ParticleSystem respawnEffect;

    [Header("Collectible Effects")]
    [SerializeField] private ParticleSystem coinCollectEffect;
    [SerializeField] private ParticleSystem powerUpCollectEffect;
    [SerializeField] private ParticleSystem rareCollectEffect;

    [Header("Combat Effects")]
    [SerializeField] private ParticleSystem enemyHitEffect;
    [SerializeField] private ParticleSystem enemyDeathEffect;
    [SerializeField] private ParticleSystem playerHitEffect;

    [Header("Environment Effects")]
    [SerializeField] private ParticleSystem rainEffect;
    [SerializeField] private ParticleSystem snowEffect;
    [SerializeField] private ParticleSystem dustStormEffect;
    [SerializeField] private ParticleSystem leavesEffect;

    [Header("UI Effects")]
    [SerializeField] private ParticleSystem scorePopupEffect;
    [SerializeField] private ParticleSystem comboEffect;
    [SerializeField] private ParticleSystem levelUpEffect;

    // Object pool for effects
    private Dictionary<string, Queue<ParticleSystem>> effectPools = new Dictionary<string, Queue<ParticleSystem>>();
    private Dictionary<string, ParticleSystem> effectPrefabs = new Dictionary<string, ParticleSystem>();

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

        InitializePools();
    }

    void InitializePools()
    {
        // Register all effects
        RegisterEffect("RunDust", runDustEffect);
        RegisterEffect("Jump", jumpEffect);
        RegisterEffect("Land", landEffect);
        RegisterEffect("Slide", slideEffect);
        RegisterEffect("Dash", dashEffect);
        RegisterEffect("WallRun", wallRunEffect);
        RegisterEffect("Death", deathEffect);
        RegisterEffect("Respawn", respawnEffect);
        RegisterEffect("CoinCollect", coinCollectEffect);
        RegisterEffect("PowerUp", powerUpCollectEffect);
        RegisterEffect("RareCollect", rareCollectEffect);
        RegisterEffect("EnemyHit", enemyHitEffect);
        RegisterEffect("EnemyDeath", enemyDeathEffect);
        RegisterEffect("PlayerHit", playerHitEffect);
        RegisterEffect("ScorePopup", scorePopupEffect);
        RegisterEffect("Combo", comboEffect);
        RegisterEffect("LevelUp", levelUpEffect);
    }

    void RegisterEffect(string name, ParticleSystem prefab)
    {
        if (prefab == null) return;

        effectPrefabs[name] = prefab;
        effectPools[name] = new Queue<ParticleSystem>();

        // Pre-instantiate some
        for (int i = 0; i < 5; i++)
        {
            ParticleSystem ps = Instantiate(prefab, transform);
            ps.gameObject.SetActive(false);
            effectPools[name].Enqueue(ps);
        }
    }

    public void PlayEffect(string effectName, Vector3 position, Quaternion rotation)
    {
        if (!effectPools.ContainsKey(effectName)) return;

        ParticleSystem ps = GetFromPool(effectName);
        if (ps != null)
        {
            ps.transform.position = position;
            ps.transform.rotation = rotation;
            ps.gameObject.SetActive(true);
            ps.Play();

            // Return to pool after duration
            float duration = ps.main.duration + ps.main.startLifetime.constantMax;
            StartCoroutine(ReturnToPoolAfterDelay(effectName, ps, duration));
        }
    }

    public void PlayEffect(string effectName, Vector3 position)
    {
        PlayEffect(effectName, position, Quaternion.identity);
    }

    public void PlayEffect(string effectName, Transform parent)
    {
        if (!effectPools.ContainsKey(effectName)) return;

        ParticleSystem ps = GetFromPool(effectName);
        if (ps != null)
        {
            ps.transform.SetParent(parent);
            ps.transform.localPosition = Vector3.zero;
            ps.gameObject.SetActive(true);
            ps.Play();
        }
    }

    ParticleSystem GetFromPool(string effectName)
    {
        Queue<ParticleSystem> pool = effectPools[effectName];

        if (pool.Count > 0)
        {
            return pool.Dequeue();
        }
        else
        {
            // Create new if pool empty
            if (effectPrefabs.TryGetValue(effectName, out ParticleSystem prefab))
            {
                return Instantiate(prefab, transform);
            }
        }

        return null;
    }

    System.Collections.IEnumerator ReturnToPoolAfterDelay(string effectName, ParticleSystem ps, float delay)
    {
        yield return new WaitForSeconds(delay);

        ps.Stop(true, ParticleSystemStopBehavior.StopEmittingAndClear);
        ps.gameObject.SetActive(false);
        ps.transform.SetParent(transform);

        if (effectPools.ContainsKey(effectName))
        {
            effectPools[effectName].Enqueue(ps);
        }
        else
        {
            Destroy(ps.gameObject);
        }
    }

    // Convenience methods
    public void PlayJumpEffect(Vector3 position)
    {
        PlayEffect("Jump", position);
    }

    public void PlayLandEffect(Vector3 position)
    {
        PlayEffect("Land", position);
    }

    public void PlayDashEffect(Vector3 position, bool facingRight)
    {
        Quaternion rotation = facingRight ? Quaternion.identity : Quaternion.Euler(0, 180, 0);
        PlayEffect("Dash", position, rotation);
    }

    public void PlayCoinEffect(Vector3 position)
    {
        PlayEffect("CoinCollect", position);
    }

    public void PlayEnemyDeathEffect(Vector3 position)
    {
        PlayEffect("EnemyDeath", position);
    }

    public void PlayDeathEffect(Vector3 position)
    {
        PlayEffect("Death", position);
    }

    public void PlayComboEffect(Vector3 position, int combo)
    {
        PlayEffect("Combo", position);

        // Scale effect based on combo
        // Could instantiate different effects for higher combos
    }

    public void PlayWeatherEffect(string weatherType)
    {
        switch (weatherType)
        {
            case "Rain":
                rainEffect?.Play();
                break;
            case "Snow":
                snowEffect?.Play();
                break;
            case "Dust":
                dustStormEffect?.Play();
                break;
            case "Leaves":
                leavesEffect?.Play();
                break;
        }
    }

    public void StopWeatherEffect()
    {
        rainEffect?.Stop();
        snowEffect?.Stop();
        dustStormEffect?.Stop();
        leavesEffect?.Stop();
    }
}
