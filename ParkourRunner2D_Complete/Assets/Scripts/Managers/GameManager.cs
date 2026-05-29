using UnityEngine;
using System;

public class GameManager : MonoBehaviour
{
    public static GameManager Instance { get; private set; }

    [Header("Game State")]
    public GameState CurrentState = GameState.MainMenu;
    public bool IsPaused = false;

    [Header("References")]
    public PlayerController Player;
    public WorldGenerator WorldGen;
    public UIManager UI;
    public AudioManager Audio;
    public SaveManager Save;

    [Header("Game Data")]
    public float TotalDistance = 0f;
    public int Score = 0;
    public int Coins = 0;
    public int CurrentChunk = 0;

    public static event Action<GameState> OnGameStateChanged;
    public static event Action OnGamePaused;
    public static event Action OnGameResumed;

    private void Awake()
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

        InitializeManagers();
    }

    void InitializeManagers()
    {
        // Auto-find if not assigned
        if (Player == null) Player = FindObjectOfType<PlayerController>();
        if (WorldGen == null) WorldGen = FindObjectOfType<WorldGenerator>();
        if (UI == null) UI = FindObjectOfType<UIManager>();
        if (Audio == null) Audio = FindObjectOfType<AudioManager>();
        if (Save == null) Save = FindObjectOfType<SaveManager>();
    }

    void Start()
    {
        LoadGameData();
        ChangeState(GameState.MainMenu);
    }

    public void ChangeState(GameState newState)
    {
        CurrentState = newState;
        OnGameStateChanged?.Invoke(newState);

        switch (newState)
        {
            case GameState.MainMenu:
                Time.timeScale = 1f;
                break;
            case GameState.Playing:
                Time.timeScale = 1f;
                IsPaused = false;
                break;
            case GameState.Paused:
                Time.timeScale = 0f;
                IsPaused = true;
                OnGamePaused?.Invoke();
                break;
            case GameState.GameOver:
                Time.timeScale = 0.5f;
                SaveGameData();
                break;
            case GameState.Checkpoint:
                Time.timeScale = 1f;
                SaveGameData();
                break;
        }
    }

    public void TogglePause()
    {
        if (IsPaused)
        {
            ChangeState(GameState.Playing);
            OnGameResumed?.Invoke();
        }
        else
        {
            ChangeState(GameState.Paused);
        }
    }

    public void StartGame()
    {
        ResetGameData();
        ChangeState(GameState.Playing);
        WorldGen?.StartGeneration();
        Player?.ResetPlayer();
    }

    public void ResumeFromCheckpoint()
    {
        ChangeState(GameState.Playing);
        Player?.RespawnAtCheckpoint();
    }

    void ResetGameData()
    {
        TotalDistance = 0f;
        Score = 0;
        CurrentChunk = 0;
    }

    public void AddScore(int points)
    {
        Score += points;
        UI?.UpdateScore(Score);
    }

    public void AddCoins(int amount)
    {
        Coins += amount;
        Save?.SaveCoins(Coins);
        UI?.UpdateCoins(Coins);
    }

    public void UpdateDistance(float distance)
    {
        TotalDistance = distance;
        UI?.UpdateDistance(TotalDistance);
    }

    void SaveGameData()
    {
        Save?.SaveGame(SaveData.CreateFromGame(this));
    }

    void LoadGameData()
    {
        SaveData data = Save?.LoadGame();
        if (data != null)
        {
            Coins = data.TotalCoins;
            Score = data.HighScore;
        }
    }

    public void GameOver()
    {
        ChangeState(GameState.GameOver);
        UI?.ShowGameOver(Score, TotalDistance);
    }
}

public enum GameState
{
    MainMenu,
    Playing,
    Paused,
    GameOver,
    Checkpoint,
    Loading
}
