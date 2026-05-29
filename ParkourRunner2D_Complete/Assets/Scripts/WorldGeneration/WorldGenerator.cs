using UnityEngine;
using System.Collections.Generic;
using System.Collections;

public class WorldGenerator : MonoBehaviour
{
    [Header("Chunk Settings")]
    [SerializeField] private float chunkLength = 20f;
    [SerializeField] private int chunksAhead = 5;
    [SerializeField] private int chunksBehind = 3;
    [SerializeField] private float generationThreshold = 10f;

    [Header("Biome Settings")]
    [SerializeField] private BiomeData[] biomes;
    [SerializeField] private float biomeChangeDistance = 500f;

    [Header("Difficulty Settings")]
    [SerializeField] private AnimationCurve difficultyCurve;
    [SerializeField] private float maxDifficultyDistance = 5000f;

    [Header("Object Pools")]
    [SerializeField] private int poolSize = 50;

    [Header("Validation")]
    [SerializeField] private bool validatePaths = true;
    [SerializeField] private int maxValidationAttempts = 10;

    // Runtime
    private Dictionary<int, Chunk> activeChunks = new Dictionary<int, Chunk>();
    private Queue<Chunk> chunkPool = new Queue<Chunk>();
    private int currentChunkIndex = 0;
    private int lastGeneratedChunk = -1;
    private float totalDistance = 0f;
    private int currentBiomeIndex = 0;
    private float nextBiomeDistance = 0f;
    private int seed;
    private System.Random random;

    // Checkpoint protection
    private int checkpointChunkIndex = -1;
    private bool hasCheckpoint = false;

    // Events
    public System.Action<int> OnChunkGenerated;
    public System.Action<int> OnChunkDestroyed;
    public System.Action<BiomeData> OnBiomeChanged;

    void Awake()
    {
        InitializePool();
        seed = Random.Range(int.MinValue, int.MaxValue);
        random = new System.Random(seed);
    }

    void InitializePool()
    {
        // Pre-instantiate chunk containers for pooling
        for (int i = 0; i < poolSize; i++)
        {
            GameObject chunkObj = new GameObject($"Chunk_Pool_{i}");
            chunkObj.SetActive(false);
            chunkObj.transform.SetParent(transform);

            Chunk chunk = chunkObj.AddComponent<Chunk>();
            chunk.Initialize();
            chunkPool.Enqueue(chunk);
        }
    }

    public void StartGeneration()
    {
        currentChunkIndex = 0;
        lastGeneratedChunk = -1;
        totalDistance = 0f;
        currentBiomeIndex = 0;
        nextBiomeDistance = biomeChangeDistance;

        // Clear existing
        foreach (var chunk in activeChunks.Values)
        {
            ReturnChunkToPool(chunk);
        }
        activeChunks.Clear();

        // Generate initial chunks
        for (int i = 0; i < chunksAhead; i++)
        {
            GenerateChunk(i);
        }
    }

    void Update()
    {
        if (GameManager.Instance?.CurrentState != GameState.Playing) return;

        // Update based on player position
        if (GameManager.Instance.Player != null)
        {
            float playerX = GameManager.Instance.Player.transform.position.x;
            int playerChunk = Mathf.FloorToInt(playerX / chunkLength);

            // Generate ahead
            int targetChunk = playerChunk + chunksAhead;
            for (int i = lastGeneratedChunk + 1; i <= targetChunk; i++)
            {
                GenerateChunk(i);
            }

            // Destroy behind (except checkpoint)
            List<int> toRemove = new List<int>();
            foreach (var kvp in activeChunks)
            {
                if (kvp.Key < playerChunk - chunksBehind)
                {
                    // Don't destroy checkpoint chunk
                    if (hasCheckpoint && kvp.Key == checkpointChunkIndex)
                        continue;

                    toRemove.Add(kvp.Key);
                }
            }

            foreach (int index in toRemove)
            {
                DestroyChunk(index);
            }

            // Update distance
            totalDistance = playerX;
            GameManager.Instance?.UpdateDistance(totalDistance);

            // Check biome change
            if (totalDistance >= nextBiomeDistance)
            {
                ChangeBiome();
            }
        }
    }

    void GenerateChunk(int index)
    {
        if (activeChunks.ContainsKey(index)) return;

        // Get chunk from pool
        Chunk chunk = GetChunkFromPool();
        if (chunk == null)
        {
            Debug.LogWarning("Chunk pool exhausted!");
            return;
        }

        // Position chunk
        float xPos = index * chunkLength;
        chunk.transform.position = new Vector3(xPos, 0, 0);
        chunk.SetIndex(index);

        // Calculate difficulty
        float difficulty = CalculateDifficulty(totalDistance);

        // Get current biome
        BiomeData biome = biomes[currentBiomeIndex];

        // Generate chunk content
        bool valid = false;
        int attempts = 0;

        while (!valid && attempts < maxValidationAttempts)
        {
            chunk.Clear();
            GenerateChunkContent(chunk, biome, difficulty, index);

            if (validatePaths)
            {
                valid = ValidateChunkPath(chunk);
            }
            else
            {
                valid = true;
            }

            attempts++;
        }

        if (!valid)
        {
            Debug.LogWarning($"Could not generate valid chunk {index} after {maxValidationAttempts} attempts");
            // Generate safe fallback
            chunk.Clear();
            GenerateSafeChunk(chunk, biome);
        }

        // Activate chunk
        chunk.gameObject.SetActive(true);
        activeChunks[index] = chunk;
        lastGeneratedChunk = index;

        OnChunkGenerated?.Invoke(index);

        // Check if this is a checkpoint chunk
        if (index > 0 && index % 10 == 0) // Every 10 chunks
        {
            PlaceCheckpoint(chunk, index);
        }
    }

    void GenerateChunkContent(Chunk chunk, BiomeData biome, float difficulty, int index)
    {
        // Generate ground/platforms
        GenerateGround(chunk, biome, difficulty);

        // Generate obstacles
        GenerateObstacles(chunk, biome, difficulty);

        // Generate collectibles
        GenerateCollectibles(chunk, biome, difficulty);

        // Generate decorations
        GenerateDecorations(chunk, biome);

        // Generate enemies (based on difficulty)
        if (difficulty > 0.3f)
        {
            GenerateEnemies(chunk, biome, difficulty);
        }

        // Special parkour elements
        GenerateParkourElements(chunk, biome, difficulty);
    }

    void GenerateGround(Chunk chunk, BiomeData biome, float difficulty)
    {
        // Base ground
        float groundY = 0f;

        // Random height variations based on biome
        if (biome.hasHeightVariation)
        {
            groundY = Random.Range(biome.minHeight, biome.maxHeight);
        }

        // Create ground segments
        int segments = Mathf.FloorToInt(chunkLength / 2f);
        for (int i = 0; i < segments; i++)
        {
            float x = i * 2f;
            float height = groundY;

            // Add some variation
            if (biome.hasHeightVariation && i > 0)
            {
                height += Random.Range(-1f, 1f);
                height = Mathf.Clamp(height, biome.minHeight, biome.maxHeight);
            }

            // Gap chance increases with difficulty
            float gapChance = difficulty * biome.gapFrequency;
            if (Random.value > gapChance || i == 0 || i == segments - 1)
            {
                // Create ground/platform
                chunk.AddGround(new Vector2(x, height), new Vector2(2f, 1f));
            }
            else
            {
                // Create gap - ensure it's jumpable
                float gapWidth = Mathf.Lerp(2f, 5f, difficulty);
                // Add landing platform after gap
                chunk.AddGround(new Vector2(x + gapWidth, height), new Vector2(2f, 1f));
                i += Mathf.FloorToInt(gapWidth / 2f);
            }
        }
    }

    void GenerateObstacles(Chunk chunk, BiomeData biome, float difficulty)
    {
        int obstacleCount = Mathf.FloorToInt(difficulty * biome.maxObstaclesPerChunk);

        for (int i = 0; i < obstacleCount; i++)
        {
            float x = Random.Range(2f, chunkLength - 2f);
            float y = Random.Range(1f, 5f);

            // Pick random obstacle type
            GameObject obstaclePrefab = biome.obstaclePrefabs[Random.Range(0, biome.obstaclePrefabs.Length)];

            if (obstaclePrefab != null)
            {
                chunk.AddObstacle(obstaclePrefab, new Vector2(x, y));
            }
        }
    }

    void GenerateCollectibles(Chunk chunk, BiomeData biome, float difficulty)
    {
        int coinCount = Random.Range(3, 8);

        for (int i = 0; i < coinCount; i++)
        {
            float x = Random.Range(1f, chunkLength - 1f);
            float y = Random.Range(1.5f, 4f);

            chunk.AddCoin(new Vector2(x, y));
        }

        // Rare collectibles
        if (Random.value < 0.1f)
        {
            float x = Random.Range(2f, chunkLength - 2f);
            float y = Random.Range(3f, 6f);
            chunk.AddRareCollectible(new Vector2(x, y));
        }
    }

    void GenerateDecorations(Chunk chunk, BiomeData biome)
    {
        int decorCount = Random.Range(5, 15);

        for (int i = 0; i < decorCount; i++)
        {
            float x = Random.Range(0f, chunkLength);
            float y = Random.Range(-2f, -5f); // Background

            if (biome.decorationPrefabs.Length > 0)
            {
                GameObject decor = biome.decorationPrefabs[Random.Range(0, biome.decorationPrefabs.Length)];
                chunk.AddDecoration(decor, new Vector2(x, y));
            }
        }
    }

    void GenerateEnemies(Chunk chunk, BiomeData biome, float difficulty)
    {
        int enemyCount = Mathf.FloorToInt(difficulty * biome.maxEnemiesPerChunk);

        for (int i = 0; i < enemyCount; i++)
        {
            float x = Random.Range(3f, chunkLength - 3f);
            float y = Random.Range(1f, 4f);

            if (biome.enemyPrefabs.Length > 0)
            {
                GameObject enemy = biome.enemyPrefabs[Random.Range(0, biome.enemyPrefabs.Length)];
                chunk.AddEnemy(enemy, new Vector2(x, y));
            }
        }
    }

    void GenerateParkourElements(Chunk chunk, BiomeData biome, float difficulty)
    {
        // Add parkour-specific objects based on biome
        if (biome.hasWallRunElements && Random.value < difficulty)
        {
            float x = Random.Range(3f, chunkLength - 3f);
            chunk.AddWallRunElement(new Vector2(x, 2f));
        }

        if (biome.hasZiplines && Random.value < difficulty * 0.5f)
        {
            float startX = Random.Range(2f, chunkLength / 2f);
            float endX = startX + Random.Range(5f, 10f);
            chunk.AddZipline(new Vector2(startX, 4f), new Vector2(endX, 2f));
        }

        if (biome.hasSwingPoints && Random.value < difficulty * 0.3f)
        {
            float x = Random.Range(3f, chunkLength - 3f);
            chunk.AddSwingPoint(new Vector2(x, 5f));
        }
    }

    void GenerateSafeChunk(Chunk chunk, BiomeData biome)
    {
        // Generate a simple safe chunk with no obstacles
        int segments = Mathf.FloorToInt(chunkLength / 2f);
        for (int i = 0; i < segments; i++)
        {
            chunk.AddGround(new Vector2(i * 2f, 0f), new Vector2(2f, 1f));
        }

        // Add some coins
        for (int i = 0; i < 5; i++)
        {
            chunk.AddCoin(new Vector2(i * 4f + 2f, 2f));
        }
    }

    bool ValidateChunkPath(Chunk chunk)
    {
        // Simple validation: ensure there are no impossible jumps
        // and the path is continuous

        var grounds = chunk.GetGrounds();
        if (grounds.Count == 0) return false;

        // Sort by x position
        grounds.Sort((a, b) => a.position.x.CompareTo(b.position.x));

        // Check continuity
        for (int i = 1; i < grounds.Count; i++)
        {
            float gap = grounds[i].position.x - grounds[i - 1].position.x;
            float heightDiff = Mathf.Abs(grounds[i].position.y - grounds[i - 1].position.y);

            // Max jumpable gap: ~5 units, max jumpable height: ~3 units
            if (gap > 6f || heightDiff > 4f)
            {
                return false;
            }
        }

        return true;
    }

    void PlaceCheckpoint(Chunk chunk, int index)
    {
        // Place checkpoint at the end of the chunk
        Vector2 checkpointPos = new Vector2(chunkLength - 1f, 1f);
        chunk.AddCheckpoint(checkpointPos);

        checkpointChunkIndex = index;
        hasCheckpoint = true;
    }

    void DestroyChunk(int index)
    {
        if (activeChunks.TryGetValue(index, out Chunk chunk))
        {
            ReturnChunkToPool(chunk);
            activeChunks.Remove(index);
            OnChunkDestroyed?.Invoke(index);
        }
    }

    Chunk GetChunkFromPool()
    {
        if (chunkPool.Count > 0)
        {
            return chunkPool.Dequeue();
        }
        return null;
    }

    void ReturnChunkToPool(Chunk chunk)
    {
        chunk.Clear();
        chunk.gameObject.SetActive(false);
        chunkPool.Enqueue(chunk);
    }

    void ChangeBiome()
    {
        currentBiomeIndex = (currentBiomeIndex + 1) % biomes.Length;
        nextBiomeDistance += biomeChangeDistance;

        OnBiomeChanged?.Invoke(biomes[currentBiomeIndex]);

        // Notify game manager
        GameManager.Instance?.Audio?.PlayMusic(biomes[currentBiomeIndex].musicClip);
    }

    float CalculateDifficulty(float distance)
    {
        float normalizedDistance = Mathf.Clamp01(distance / maxDifficultyDistance);
        return difficultyCurve.Evaluate(normalizedDistance);
    }

    public void SetCheckpointChunk(int index)
    {
        checkpointChunkIndex = index;
        hasCheckpoint = true;
    }

    public void ClearCheckpoint()
    {
        hasCheckpoint = false;
        checkpointChunkIndex = -1;
    }

    public Chunk GetChunk(int index)
    {
        if (activeChunks.TryGetValue(index, out Chunk chunk))
        {
            return chunk;
        }
        return null;
    }

    public int GetCurrentChunkIndex()
    {
        return currentChunkIndex;
    }

    public BiomeData GetCurrentBiome()
    {
        return biomes[currentBiomeIndex];
    }
}

// Chunk Component
public class Chunk : MonoBehaviour
{
    private int index;
    private List<Transform> contents = new List<Transform>();
    private List<Transform> grounds = new List<Transform>();

    public void Initialize()
    {
        // Setup chunk container
    }

    public void SetIndex(int idx)
    {
        index = idx;
        name = $"Chunk_{idx}";
    }

    public void Clear()
    {
        foreach (var content in contents)
        {
            if (content != null)
            {
                Destroy(content.gameObject);
            }
        }
        contents.Clear();
        grounds.Clear();
    }

    public void AddGround(Vector2 position, Vector2 size)
    {
        GameObject ground = GameObject.CreatePrimitive(PrimitiveType.Cube);
        ground.transform.SetParent(transform);
        ground.transform.position = new Vector3(position.x, position.y, 0);
        ground.transform.localScale = new Vector3(size.x, size.y, 1);

        // Add 2D collider
        var col = ground.AddComponent<BoxCollider2D>();
        col.size = new Vector2(1, 1);

        // Add sprite renderer
        var sr = ground.GetComponent<SpriteRenderer>();
        if (sr == null) sr = ground.AddComponent<SpriteRenderer>();
        sr.color = Color.gray;

        ground.tag = "Ground";
        ground.layer = LayerMask.NameToLayer("Ground");

        contents.Add(ground.transform);
        grounds.Add(ground.transform);
    }

    public void AddObstacle(GameObject prefab, Vector2 position)
    {
        if (prefab == null) return;
        GameObject obj = Instantiate(prefab, transform);
        obj.transform.position = new Vector3(position.x, position.y, 0);
        contents.Add(obj.transform);
    }

    public void AddCoin(Vector2 position)
    {
        GameObject coin = new GameObject("Coin");
        coin.transform.SetParent(transform);
        coin.transform.position = new Vector3(position.x, position.y, 0);

        var sr = coin.AddComponent<SpriteRenderer>();
        sr.color = Color.yellow;
        sr.sprite = Resources.GetBuiltinResource<Sprite>("UISprite");

        var col = coin.AddComponent<CircleCollider2D>();
        col.isTrigger = true;
        col.radius = 0.3f;

        coin.tag = "Coin";

        // Add simple animation
        var anim = coin.AddComponent<SimpleFloatAnimation>();

        contents.Add(coin.transform);
    }

    public void AddRareCollectible(Vector2 position)
    {
        GameObject collectible = new GameObject("RareCollectible");
        collectible.transform.SetParent(transform);
        collectible.transform.position = new Vector3(position.x, position.y, 0);

        var sr = collectible.AddComponent<SpriteRenderer>();
        sr.color = Color.cyan;

        var col = collectible.AddComponent<CircleCollider2D>();
        col.isTrigger = true;

        collectible.tag = "Collectible";

        contents.Add(collectible.transform);
    }

    public void AddDecoration(GameObject prefab, Vector2 position)
    {
        if (prefab == null) return;
        GameObject obj = Instantiate(prefab, transform);
        obj.transform.position = new Vector3(position.x, position.y, 0);
        contents.Add(obj.transform);
    }

    public void AddEnemy(GameObject prefab, Vector2 position)
    {
        if (prefab == null) return;
        GameObject obj = Instantiate(prefab, transform);
        obj.transform.position = new Vector3(position.x, position.y, 0);
        contents.Add(obj.transform);
    }

    public void AddCheckpoint(Vector2 position)
    {
        GameObject checkpoint = new GameObject("Checkpoint");
        checkpoint.transform.SetParent(transform);
        checkpoint.transform.position = new Vector3(position.x, position.y, 0);

        var sr = checkpoint.AddComponent<SpriteRenderer>();
        sr.color = Color.green;

        var col = checkpoint.AddComponent<BoxCollider2D>();
        col.isTrigger = true;
        col.size = new Vector2(1, 2);

        checkpoint.tag = "Checkpoint";

        contents.Add(checkpoint.transform);
    }

    public void AddWallRunElement(Vector2 position)
    {
        GameObject wall = new GameObject("WallRun");
        wall.transform.SetParent(transform);
        wall.transform.position = new Vector3(position.x, position.y, 0);
        wall.transform.localScale = new Vector3(0.5f, 3f, 1);

        var col = wall.AddComponent<BoxCollider2D>();
        wall.tag = "Wall";
        wall.layer = LayerMask.NameToLayer("Wall");

        contents.Add(wall.transform);
    }

    public void AddZipline(Vector2 start, Vector2 end)
    {
        GameObject zipline = new GameObject("Zipline");
        zipline.transform.SetParent(transform);

        // Create line renderer
        var lr = zipline.AddComponent<LineRenderer>();
        lr.positionCount = 2;
        lr.SetPosition(0, new Vector3(start.x, start.y, 0));
        lr.SetPosition(1, new Vector3(end.x, end.y, 0));
        lr.startWidth = 0.1f;
        lr.endWidth = 0.1f;
        lr.material = new Material(Shader.Find("Sprites/Default"));
        lr.startColor = Color.red;
        lr.endColor = Color.red;

        // Add collider for detection
        var col = zipline.AddComponent<EdgeCollider2D>();
        col.points = new Vector2[] { start, end };
        col.isTrigger = true;
        zipline.tag = "Zipline";

        contents.Add(zipline.transform);
    }

    public void AddSwingPoint(Vector2 position)
    {
        GameObject swingPoint = new GameObject("SwingPoint");
        swingPoint.transform.SetParent(transform);
        swingPoint.transform.position = new Vector3(position.x, position.y, 0);

        var col = swingPoint.AddComponent<CircleCollider2D>();
        col.isTrigger = true;
        col.radius = 0.5f;

        swingPoint.tag = "SwingPoint";

        contents.Add(swingPoint.transform);
    }

    public List<Transform> GetGrounds()
    {
        return grounds;
    }

    public int GetIndex()
    {
        return index;
    }
}

// Simple floating animation for coins
public class SimpleFloatAnimation : MonoBehaviour
{
    private float startY;
    private float speed = 2f;
    private float amplitude = 0.2f;

    void Start()
    {
        startY = transform.position.y;
    }

    void Update()
    {
        float y = startY + Mathf.Sin(Time.time * speed) * amplitude;
        transform.position = new Vector3(transform.position.x, y, transform.position.z);
    }
}
