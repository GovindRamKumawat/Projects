using UnityEngine;

[CreateAssetMenu(fileName = "NewBiome", menuName = "Parkour Runner/Biome Data")]
public class BiomeData : ScriptableObject
{
    [Header("Basic Info")]
    public string biomeName = "New Biome";
    public string description = "";
    public Sprite backgroundSprite;
    public Color backgroundColor = Color.gray;

    [Header("Music")]
    public AudioClip musicClip;
    public AudioClip ambientSound;

    [Header("Visual")]
    public Color groundColor = Color.gray;
    public Color skyColor = Color.blue;
    public ParticleSystem weatherEffect;
    public float lightIntensity = 1f;
    public Color lightColor = Color.white;

    [Header("Generation Settings")]
    public bool hasHeightVariation = true;
    public float minHeight = -1f;
    public float maxHeight = 3f;
    public float gapFrequency = 0.3f;
    public int maxObstaclesPerChunk = 5;
    public int maxEnemiesPerChunk = 3;

    [Header("Parkour Elements")]
    public bool hasWallRunElements = true;
    public bool hasZiplines = true;
    public bool hasSwingPoints = true;

    [Header("Prefabs")]
    public GameObject[] groundPrefabs;
    public GameObject[] obstaclePrefabs;
    public GameObject[] enemyPrefabs;
    public GameObject[] decorationPrefabs;
    public GameObject[] platformPrefabs;

    [Header("Difficulty Multipliers")]
    public float speedMultiplier = 1f;
    public float obstacleDensityMultiplier = 1f;
    public float enemyDensityMultiplier = 1f;

    [Header("Special Features")]
    public bool hasMovingPlatforms = false;
    public bool hasCrushingWalls = false;
    public bool hasLasers = false;
    public bool hasWind = false;
    public float windForce = 0f;
}
