using UnityEngine;

public class GameplayInitializer : MonoBehaviour
{
    [Header("Required Prefabs")]
    [SerializeField] private GameObject playerPrefab;
    [SerializeField] private GameObject cameraPrefab;
    [SerializeField] private GameObject worldGeneratorPrefab;
    [SerializeField] private GameObject uiManagerPrefab;
    [SerializeField] private GameObject audioManagerPrefab;
    [SerializeField] private GameObject saveManagerPrefab;
    [SerializeField] private GameObject objectPoolPrefab;
    [SerializeField] private GameObject particleManagerPrefab;
    [SerializeField] private GameObject performanceManagerPrefab;

    [Header("Spawn Points")]
    [SerializeField] private Transform playerSpawnPoint;
    [SerializeField] private Transform cameraSpawnPoint;

    [Header("Scene Settings")]
    [SerializeField] private Color backgroundColor = new Color(0.1f, 0.1f, 0.15f);
    [SerializeField] private float gravity = -25f;

    void Awake()
    {
        InitializeScene();
    }

    void InitializeScene()
    {
        // Set physics
        Physics2D.gravity = new Vector2(0, gravity);

        // Set background color
        Camera.main.backgroundColor = backgroundColor;

        // Instantiate managers if not present
        EnsureManager(ref saveManagerPrefab, "SaveManager");
        EnsureManager(ref audioManagerPrefab, "AudioManager");
        EnsureManager(ref objectPoolPrefab, "ObjectPool");
        EnsureManager(ref particleManagerPrefab, "ParticleManager");
        EnsureManager(ref performanceManagerPrefab, "PerformanceManager");

        // Instantiate player
        if (playerPrefab != null && playerSpawnPoint != null)
        {
            GameObject player = Instantiate(playerPrefab, playerSpawnPoint.position, Quaternion.identity);
            player.name = "Player";
        }

        // Instantiate camera
        if (cameraPrefab != null && cameraSpawnPoint != null)
        {
            GameObject cam = Instantiate(cameraPrefab, cameraSpawnPoint.position, Quaternion.identity);
            cam.name = "MainCamera";
        }

        // Instantiate world generator
        if (worldGeneratorPrefab != null)
        {
            GameObject worldGen = Instantiate(worldGeneratorPrefab);
            worldGen.name = "WorldGenerator";
        }

        // Instantiate UI
        if (uiManagerPrefab != null)
        {
            GameObject ui = Instantiate(uiManagerPrefab);
            ui.name = "UIManager";
        }

        // Setup game manager references
        SetupGameManager();

        Debug.Log("Gameplay scene initialized successfully!");
    }

    void EnsureManager(ref GameObject prefab, string managerName)
    {
        GameObject existing = GameObject.Find(managerName);
        if (existing == null && prefab != null)
        {
            GameObject manager = Instantiate(prefab);
            manager.name = managerName;
        }
    }

    void SetupGameManager()
    {
        GameManager gm = GameManager.Instance;
        if (gm == null) return;

        // Find and assign references
        gm.Player = FindObjectOfType<PlayerController>();
        gm.WorldGen = FindObjectOfType<WorldGenerator>();
        gm.UI = FindObjectOfType<UIManager>();
        gm.Audio = FindObjectOfType<AudioManager>();
        gm.Save = FindObjectOfType<SaveManager>();
    }

    void Start()
    {
        // Start the game
        GameManager.Instance?.StartGame();
    }
}
