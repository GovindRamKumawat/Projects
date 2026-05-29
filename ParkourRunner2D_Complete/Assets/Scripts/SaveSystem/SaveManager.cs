using UnityEngine;
using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

[System.Serializable]
public class SaveData
{
    // Player Progress
    public float PlayerX;
    public float PlayerY;
    public int CurrentChunk;
    public int CurrentSeed;
    public int CurrentBiome;

    // Stats
    public int TotalCoins;
    public int HighScore;
    public float BestDistance;
    public int TotalRuns;
    public int TotalDeaths;

    // Unlocks
    public bool[] UnlockedCharacters;
    public bool[] UnlockedStyles;
    public bool[] UnlockedMoves;
    public bool[] CompletedMissions;

    // Upgrades
    public int SpeedLevel;
    public int JumpLevel;
    public int StaminaLevel;
    public int ComboLevel;
    public int DashLevel;

    // Settings
    public float MusicVolume = 0.7f;
    public float SFXVolume = 0.8f;
    public bool VibrationEnabled = true;
    public bool LeftHandedMode = false;
    public int GraphicsQuality = 2; // 0=Low, 1=Medium, 2=High

    // Current Run Data
    public bool HasActiveRun;
    public float RunDistance;
    public int RunScore;
    public int RunCoins;
    public int RunChunk;

    // Timestamp
    public string SaveDate;
    public int SaveVersion = 1;

    public static SaveData CreateDefault()
    {
        return new SaveData
        {
            UnlockedCharacters = new bool[10],
            UnlockedStyles = new bool[10],
            UnlockedMoves = new bool[20],
            CompletedMissions = new bool[50],
            SaveDate = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"),
            UnlockedCharacters = new bool[10] { true, false, false, false, false, false, false, false, false, false },
            UnlockedStyles = new bool[10] { true, false, false, false, false, false, false, false, false, false },
            UnlockedMoves = new bool[20] { true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }
        };
    }

    public static SaveData CreateFromGame(GameManager game)
    {
        SaveData data = LoadOrCreate();

        data.RunDistance = game.TotalDistance;
        data.RunScore = game.Score;
        data.RunCoins = game.Coins;
        data.RunChunk = game.CurrentChunk;
        data.HasActiveRun = game.CurrentState == GameState.Playing;

        // Update stats
        if (game.Score > data.HighScore)
            data.HighScore = game.Score;
        if (game.TotalDistance > data.BestDistance)
            data.BestDistance = game.TotalDistance;

        data.SaveDate = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");

        return data;
    }

    public static SaveData LoadOrCreate()
    {
        SaveManager saveManager = UnityEngine.Object.FindObjectOfType<SaveManager>();
        if (saveManager != null)
        {
            return saveManager.LoadGame() ?? CreateDefault();
        }
        return CreateDefault();
    }
}

public class SaveManager : MonoBehaviour
{
    public static SaveManager Instance { get; private set; }

    [Header("Save Settings")]
    [SerializeField] private bool encryptSaves = true;
    [SerializeField] private int maxBackupSlots = 3;
    [SerializeField] private float autoSaveInterval = 30f;

    private string savePath;
    private string backupPath;
    private float autoSaveTimer;
    private SaveData currentData;
    private bool isSaving;

    // Encryption key (change this for your game!)
    private const string ENCRYPTION_KEY = "ParkourRunner2D_SecureKey_2026!";

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

        InitializePaths();
    }

    void InitializePaths()
    {
        savePath = Path.Combine(Application.persistentDataPath, "save.dat");
        backupPath = Path.Combine(Application.persistentDataPath, "backups");

        if (!Directory.Exists(backupPath))
        {
            Directory.CreateDirectory(backupPath);
        }
    }

    void Update()
    {
        if (GameManager.Instance?.CurrentState == GameState.Playing)
        {
            autoSaveTimer += Time.deltaTime;
            if (autoSaveTimer >= autoSaveInterval)
            {
                AutoSave();
                autoSaveTimer = 0f;
            }
        }
    }

    public void SaveGame(SaveData data)
    {
        if (isSaving) return;
        StartCoroutine(SaveGameCoroutine(data));
    }

    System.Collections.IEnumerator SaveGameCoroutine(SaveData data)
    {
        isSaving = true;

        // Create backup before saving
        CreateBackup();

        // Serialize
        string json = JsonUtility.ToJson(data, true);

        // Encrypt if enabled
        string saveContent = encryptSaves ? EncryptString(json, ENCRYPTION_KEY) : json;

        // Write to temp file first (atomic save)
        string tempPath = savePath + ".tmp";

        try
        {
            File.WriteAllText(tempPath, saveContent);

            // Verify temp file
            if (File.Exists(tempPath) && new FileInfo(tempPath).Length > 0)
            {
                // Replace original with temp
                if (File.Exists(savePath))
                {
                    File.Delete(savePath);
                }
                File.Move(tempPath, savePath);

                currentData = data;
                Debug.Log("Game saved successfully!");
            }
            else
            {
                Debug.LogError("Save verification failed!");
                RestoreFromBackup();
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"Save failed: {e.Message}");
            RestoreFromBackup();
        }

        isSaving = false;
        yield return null;
    }

    public SaveData LoadGame()
    {
        if (!File.Exists(savePath))
        {
            Debug.Log("No save file found. Creating new save.");
            currentData = SaveData.CreateDefault();
            SaveGame(currentData);
            return currentData;
        }

        try
        {
            string saveContent = File.ReadAllText(savePath);

            // Decrypt if encrypted
            string json = encryptSaves ? DecryptString(saveContent, ENCRYPTION_KEY) : saveContent;

            SaveData data = JsonUtility.FromJson<SaveData>(json);

            // Validate save data
            if (ValidateSaveData(data))
            {
                currentData = data;
                Debug.Log("Game loaded successfully!");
                return data;
            }
            else
            {
                Debug.LogWarning("Save data validation failed. Attempting backup restore.");
                return RestoreFromBackup();
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"Load failed: {e.Message}. Attempting backup restore.");
            return RestoreFromBackup();
        }
    }

    bool ValidateSaveData(SaveData data)
    {
        if (data == null) return false;
        if (data.SaveVersion < 1) return false;
        if (data.UnlockedCharacters == null || data.UnlockedCharacters.Length == 0) return false;

        return true;
    }

    void CreateBackup()
    {
        if (!File.Exists(savePath)) return;

        try
        {
            // Rotate backups
            for (int i = maxBackupSlots - 1; i > 0; i--)
            {
                string oldBackup = Path.Combine(backupPath, $"save_backup_{i-1}.dat");
                string newBackup = Path.Combine(backupPath, $"save_backup_{i}.dat");

                if (File.Exists(oldBackup))
                {
                    if (File.Exists(newBackup))
                        File.Delete(newBackup);
                    File.Move(oldBackup, newBackup);
                }
            }

            // Create new backup
            string firstBackup = Path.Combine(backupPath, "save_backup_0.dat");
            File.Copy(savePath, firstBackup, true);
        }
        catch (Exception e)
        {
            Debug.LogWarning($"Backup creation failed: {e.Message}");
        }
    }

    SaveData RestoreFromBackup()
    {
        for (int i = 0; i < maxBackupSlots; i++)
        {
            string backupFile = Path.Combine(backupPath, $"save_backup_{i}.dat");

            if (File.Exists(backupFile))
            {
                try
                {
                    string backupContent = File.ReadAllText(backupFile);
                    string json = encryptSaves ? DecryptString(backupContent, ENCRYPTION_KEY) : backupContent;

                    SaveData data = JsonUtility.FromJson<SaveData>(json);

                    if (ValidateSaveData(data))
                    {
                        // Restore save file
                        File.Copy(backupFile, savePath, true);
                        currentData = data;
                        Debug.Log($"Restored from backup {i}");
                        return data;
                    }
                }
                catch (Exception e)
                {
                    Debug.LogWarning($"Backup {i} restore failed: {e.Message}");
                }
            }
        }

        Debug.LogError("All backups failed. Creating new save.");
        currentData = SaveData.CreateDefault();
        SaveGame(currentData);
        return currentData;
    }

    void AutoSave()
    {
        if (GameManager.Instance != null)
        {
            SaveData data = SaveData.CreateFromGame(GameManager.Instance);
            SaveGame(data);
        }
    }

    public void SaveCoins(int coins)
    {
        if (currentData != null)
        {
            currentData.TotalCoins = coins;
            SaveGame(currentData);
        }
    }

    public void UnlockCharacter(int index)
    {
        if (currentData != null && index >= 0 && index < currentData.UnlockedCharacters.Length)
        {
            currentData.UnlockedCharacters[index] = true;
            SaveGame(currentData);
        }
    }

    public void UnlockStyle(int index)
    {
        if (currentData != null && index >= 0 && index < currentData.UnlockedStyles.Length)
        {
            currentData.UnlockedStyles[index] = true;
            SaveGame(currentData);
        }
    }

    public void UnlockMove(int index)
    {
        if (currentData != null && index >= 0 && index < currentData.UnlockedMoves.Length)
        {
            currentData.UnlockedMoves[index] = true;
            SaveGame(currentData);
        }
    }

    public void UpgradeAbility(string abilityName, int level)
    {
        if (currentData == null) return;

        switch (abilityName)
        {
            case "Speed": currentData.SpeedLevel = level; break;
            case "Jump": currentData.JumpLevel = level; break;
            case "Stamina": currentData.StaminaLevel = level; break;
            case "Combo": currentData.ComboLevel = level; break;
            case "Dash": currentData.DashLevel = level; break;
        }

        SaveGame(currentData);
    }

    public SaveData GetCurrentData()
    {
        return currentData;
    }

    public void ResetProgress()
    {
        currentData = SaveData.CreateDefault();
        SaveGame(currentData);
    }

    public void DeleteAllSaves()
    {
        try
        {
            if (File.Exists(savePath))
                File.Delete(savePath);

            for (int i = 0; i < maxBackupSlots; i++)
            {
                string backupFile = Path.Combine(backupPath, $"save_backup_{i}.dat");
                if (File.Exists(backupFile))
                    File.Delete(backupFile);
            }

            currentData = null;
            Debug.Log("All saves deleted.");
        }
        catch (Exception e)
        {
            Debug.LogError($"Delete failed: {e.Message}");
        }
    }

    // Encryption Methods
    string EncryptString(string text, string key)
    {
        byte[] keyBytes = Encoding.UTF8.GetBytes(key);
        byte[] textBytes = Encoding.UTF8.GetBytes(text);

        // Simple XOR encryption (for production, use AES)
        byte[] encrypted = new byte[textBytes.Length];
        for (int i = 0; i < textBytes.Length; i++)
        {
            encrypted[i] = (byte)(textBytes[i] ^ keyBytes[i % keyBytes.Length]);
        }

        return Convert.ToBase64String(encrypted);
    }

    string DecryptString(string encryptedText, string key)
    {
        byte[] keyBytes = Encoding.UTF8.GetBytes(key);
        byte[] encryptedBytes = Convert.FromBase64String(encryptedText);

        byte[] decrypted = new byte[encryptedBytes.Length];
        for (int i = 0; i < encryptedBytes.Length; i++)
        {
            decrypted[i] = (byte)(encryptedBytes[i] ^ keyBytes[i % keyBytes.Length]);
        }

        return Encoding.UTF8.GetString(decrypted);
    }

    // Cloud Save Support (placeholder for integration)
    public void UploadToCloud()
    {
        // Implement cloud save using Unity Cloud Save, PlayFab, or Firebase
        Debug.Log("Cloud save upload requested");
    }

    public void DownloadFromCloud()
    {
        // Implement cloud save download
        Debug.Log("Cloud save download requested");
    }
}
