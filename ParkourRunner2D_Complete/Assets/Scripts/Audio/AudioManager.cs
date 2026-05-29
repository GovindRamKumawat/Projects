using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class AudioManager : MonoBehaviour
{
    public static AudioManager Instance { get; private set; }

    [Header("Music")]
    [SerializeField] private AudioSource musicSource;
    [SerializeField] private AudioSource musicSource2; // For crossfading
    [SerializeField] private float musicFadeTime = 1f;
    [SerializeField] private float musicVolume = 0.7f;

    [Header("SFX")]
    [SerializeField] private AudioSource sfxSource;
    [SerializeField] private AudioSource[] sfxPool;
    [SerializeField] private int sfxPoolSize = 10;
    [SerializeField] private float sfxVolume = 0.8f;

    [Header("Ambient")]
    [SerializeField] private AudioSource ambientSource;
    [SerializeField] private float ambientVolume = 0.3f;

    [Header("Sound Effects")]
    [SerializeField] private AudioClip jumpSFX;
    [SerializeField] private AudioClip landSFX;
    [SerializeField] private AudioClip slideSFX;
    [SerializeField] private AudioClip dashSFX;
    [SerializeField] private AudioClip wallRunSFX;
    [SerializeField] private AudioClip grappleSFX;
    [SerializeField] private AudioClip coinSFX;
    [SerializeField] private AudioClip checkpointSFX;
    [SerializeField] private AudioClip deathSFX;
    [SerializeField] private AudioClip respawnSFX;
    [SerializeField] private AudioClip clickSFX;
    [SerializeField] private AudioClip comboSFX;
    [SerializeField] private AudioClip enemyHitSFX;
    [SerializeField] private AudioClip enemyDeathSFX;
    [SerializeField] private AudioClip droneShootSFX;
    [SerializeField] private AudioClip sniperShotSFX;
    [SerializeField] private AudioClip vaultSFX;

    [Header("Music Tracks")]
    [SerializeField] private AudioClip menuMusic;
    [SerializeField] private AudioClip gameplayMusic;
    [SerializeField] private AudioClip chaseMusic;
    [SerializeField] private AudioClip bossMusic;

    // Runtime
    private Dictionary<string, AudioClip> sfxDictionary;
    private int currentSfxPoolIndex = 0;
    private AudioSource activeMusicSource;
    private AudioSource inactiveMusicSource;
    private Coroutine musicFadeCoroutine;

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

        InitializeAudio();
    }

    void InitializeAudio()
    {
        // Setup music sources
        if (musicSource == null)
        {
            musicSource = gameObject.AddComponent<AudioSource>();
            musicSource.loop = true;
            musicSource.volume = musicVolume;
        }

        if (musicSource2 == null)
        {
            musicSource2 = gameObject.AddComponent<AudioSource>();
            musicSource2.loop = true;
            musicSource2.volume = 0;
        }

        activeMusicSource = musicSource;
        inactiveMusicSource = musicSource2;

        // Setup SFX pool
        if (sfxPool == null || sfxPool.Length == 0)
        {
            sfxPool = new AudioSource[sfxPoolSize];
            for (int i = 0; i < sfxPoolSize; i++)
            {
                sfxPool[i] = gameObject.AddComponent<AudioSource>();
                sfxPool[i].volume = sfxVolume;
            }
        }

        // Setup ambient
        if (ambientSource == null)
        {
            ambientSource = gameObject.AddComponent<AudioSource>();
            ambientSource.loop = true;
            ambientSource.volume = ambientVolume;
        }

        // Build SFX dictionary
        BuildSFXDictionary();
    }

    void BuildSFXDictionary()
    {
        sfxDictionary = new Dictionary<string, AudioClip>
        {
            { "Jump", jumpSFX },
            { "Land", landSFX },
            { "Slide", slideSFX },
            { "Dash", dashSFX },
            { "WallRun", wallRunSFX },
            { "Grapple", grappleSFX },
            { "Coin", coinSFX },
            { "Checkpoint", checkpointSFX },
            { "Die", deathSFX },
            { "Respawn", respawnSFX },
            { "Click", clickSFX },
            { "Combo", comboSFX },
            { "EnemyHit", enemyHitSFX },
            { "EnemyDeath", enemyDeathSFX },
            { "DroneShoot", droneShootSFX },
            { "SniperShot", sniperShotSFX },
            { "Vault", vaultSFX }
        };
    }

    void Start()
    {
        // Subscribe to game state changes
        GameManager.OnGameStateChanged += OnGameStateChanged;
    }

    void OnDestroy()
    {
        GameManager.OnGameStateChanged -= OnGameStateChanged;
    }

    void OnGameStateChanged(GameState state)
    {
        switch (state)
        {
            case GameState.MainMenu:
                PlayMusic(menuMusic);
                StopAmbient();
                break;

            case GameState.Playing:
                PlayMusic(gameplayMusic);
                StartAmbient();
                break;

            case GameState.GameOver:
                PlayMusic(menuMusic);
                StopAmbient();
                break;
        }
    }

    // Music Methods
    public void PlayMusic(AudioClip clip)
    {
        if (clip == null) return;

        if (musicFadeCoroutine != null)
            StopCoroutine(musicFadeCoroutine);

        musicFadeCoroutine = StartCoroutine(CrossfadeMusic(clip));
    }

    IEnumerator CrossfadeMusic(AudioClip newClip)
    {
        // Swap sources
        AudioSource fadeOutSource = activeMusicSource;
        AudioSource fadeInSource = inactiveMusicSource;

        // Setup fade in source
        fadeInSource.clip = newClip;
        fadeInSource.Play();

        float timer = 0;
        while (timer < musicFadeTime)
        {
            timer += Time.deltaTime;
            float t = timer / musicFadeTime;

            fadeOutSource.volume = Mathf.Lerp(musicVolume, 0, t);
            fadeInSource.volume = Mathf.Lerp(0, musicVolume, t);

            yield return null;
        }

        fadeOutSource.Stop();
        fadeOutSource.volume = musicVolume;

        // Swap active source
        activeMusicSource = fadeInSource;
        inactiveMusicSource = fadeOutSource;
    }

    public void StopMusic()
    {
        activeMusicSource?.Stop();
        inactiveMusicSource?.Stop();
    }

    public void PauseMusic()
    {
        activeMusicSource?.Pause();
    }

    public void ResumeMusic()
    {
        activeMusicSource?.UnPause();
    }

    // SFX Methods
    public void PlaySFX(string soundName)
    {
        if (sfxDictionary.TryGetValue(soundName, out AudioClip clip))
        {
            PlaySFX(clip);
        }
    }

    public void PlaySFX(AudioClip clip)
    {
        if (clip == null) return;

        // Get next available source from pool
        AudioSource source = sfxPool[currentSfxPoolIndex];
        currentSfxPoolIndex = (currentSfxPoolIndex + 1) % sfxPoolSize;

        source.clip = clip;
        source.volume = sfxVolume;
        source.Play();
    }

    public void PlaySFXAtPosition(AudioClip clip, Vector3 position)
    {
        if (clip == null) return;

        AudioSource.PlayClipAtPoint(clip, position, sfxVolume);
    }

    public void PlayRandomSFX(AudioClip[] clips)
    {
        if (clips == null || clips.Length == 0) return;

        AudioClip clip = clips[Random.Range(0, clips.Length)];
        PlaySFX(clip);
    }

    // Ambient Methods
    public void PlayAmbient(AudioClip clip)
    {
        if (ambientSource == null || clip == null) return;

        ambientSource.clip = clip;
        ambientSource.Play();
    }

    public void StopAmbient()
    {
        ambientSource?.Stop();
    }

    void StartAmbient()
    {
        ambientSource?.Play();
    }

    // Volume Controls
    public void SetMusicVolume(float volume)
    {
        musicVolume = Mathf.Clamp01(volume);
        if (activeMusicSource != null)
            activeMusicSource.volume = musicVolume;
    }

    public void SetSFXVolume(float volume)
    {
        sfxVolume = Mathf.Clamp01(volume);
        foreach (var source in sfxPool)
        {
            if (source != null)
                source.volume = sfxVolume;
        }
    }

    public void SetAmbientVolume(float volume)
    {
        ambientVolume = Mathf.Clamp01(volume);
        if (ambientSource != null)
            ambientSource.volume = ambientVolume;
    }

    public void SetMasterVolume(float volume)
    {
        AudioListener.volume = Mathf.Clamp01(volume);
    }

    // Adaptive Music
    public void SetMusicIntensity(float intensity)
    {
        // Adjust music based on gameplay intensity
        // This could switch between calm and intense music layers
        intensity = Mathf.Clamp01(intensity);

        // Example: pitch shift based on intensity
        if (activeMusicSource != null)
        {
            activeMusicSource.pitch = Mathf.Lerp(0.9f, 1.1f, intensity);
        }
    }

    public void PlayChaseMusic()
    {
        PlayMusic(chaseMusic);
    }

    public void PlayBossMusic()
    {
        PlayMusic(bossMusic);
    }

    // Utility
    public void FadeOutAll(float duration)
    {
        StartCoroutine(FadeOutAllCoroutine(duration));
    }

    IEnumerator FadeOutAllCoroutine(float duration)
    {
        float startMusicVol = activeMusicSource?.volume ?? 0;
        float startAmbientVol = ambientSource?.volume ?? 0;
        float timer = 0;

        while (timer < duration)
        {
            timer += Time.deltaTime;
            float t = timer / duration;

            if (activeMusicSource != null)
                activeMusicSource.volume = Mathf.Lerp(startMusicVol, 0, t);
            if (ambientSource != null)
                ambientSource.volume = Mathf.Lerp(startAmbientVol, 0, t);

            yield return null;
        }

        StopMusic();
        StopAmbient();
    }
}
