using UnityEngine;
using System.Collections.Generic;

public class ObjectPool : MonoBehaviour
{
    [System.Serializable]
    public class Pool
    {
        public string tag;
        public GameObject prefab;
        public int size;
    }

    public static ObjectPool Instance { get; private set; }

    [SerializeField] private List<Pool> pools;
    private Dictionary<string, Queue<GameObject>> poolDictionary;
    private Dictionary<string, GameObject> prefabDictionary;

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

        InitializePools();
    }

    void InitializePools()
    {
        poolDictionary = new Dictionary<string, Queue<GameObject>>();
        prefabDictionary = new Dictionary<string, GameObject>();

        foreach (Pool pool in pools)
        {
            Queue<GameObject> objectPool = new Queue<GameObject>();

            for (int i = 0; i < pool.size; i++)
            {
                GameObject obj = Instantiate(pool.prefab);
                obj.SetActive(false);
                obj.transform.SetParent(transform);
                objectPool.Enqueue(obj);
            }

            poolDictionary.Add(pool.tag, objectPool);
            prefabDictionary.Add(pool.tag, pool.prefab);
        }
    }

    public GameObject SpawnFromPool(string tag, Vector3 position, Quaternion rotation)
    {
        if (!poolDictionary.ContainsKey(tag))
        {
            Debug.LogWarning($"Pool with tag {tag} doesn't exist.");
            return null;
        }

        Queue<GameObject> pool = poolDictionary[tag];
        GameObject objectToSpawn;

        if (pool.Count > 0)
        {
            objectToSpawn = pool.Dequeue();
        }
        else
        {
            // Pool exhausted, create new (with warning)
            Debug.LogWarning($"Pool {tag} exhausted! Creating new object.");
            objectToSpawn = Instantiate(prefabDictionary[tag]);
        }

        objectToSpawn.SetActive(true);
        objectToSpawn.transform.position = position;
        objectToSpawn.transform.rotation = rotation;
        objectToSpawn.transform.SetParent(null);

        // Notify object
        IPoolable poolable = objectToSpawn.GetComponent<IPoolable>();
        poolable?.OnSpawnFromPool();

        return objectToSpawn;
    }

    public void ReturnToPool(string tag, GameObject obj)
    {
        if (!poolDictionary.ContainsKey(tag))
        {
            Debug.LogWarning($"Pool with tag {tag} doesn't exist. Destroying object.");
            Destroy(obj);
            return;
        }

        // Notify object
        IPoolable poolable = obj.GetComponent<IPoolable>();
        poolable?.OnReturnToPool();

        obj.SetActive(false);
        obj.transform.SetParent(transform);

        poolDictionary[tag].Enqueue(obj);
    }

    public void ReturnToPool(GameObject obj)
    {
        // Try to find pool by prefab type
        IPoolable poolable = obj.GetComponent<IPoolable>();
        if (poolable != null)
        {
            ReturnToPool(poolable.PoolTag, obj);
        }
        else
        {
            Destroy(obj);
        }
    }
}

public interface IPoolable
{
    string PoolTag { get; }
    void OnSpawnFromPool();
    void OnReturnToPool();
}

// Example pooled object
public class PooledCoin : MonoBehaviour, IPoolable
{
    public string PoolTag => "Coin";

    [SerializeField] private float rotateSpeed = 180f;
    [SerializeField] private float floatAmplitude = 0.2f;
    [SerializeField] private float floatSpeed = 2f;

    private Vector3 startPosition;
    private float floatOffset;

    public void OnSpawnFromPool()
    {
        startPosition = transform.position;
        floatOffset = Random.Range(0f, Mathf.PI * 2f);
    }

    public void OnReturnToPool()
    {
        // Reset state
    }

    void Update()
    {
        // Rotate
        transform.Rotate(Vector3.up, rotateSpeed * Time.deltaTime);

        // Float
        float y = startPosition.y + Mathf.Sin(Time.time * floatSpeed + floatOffset) * floatAmplitude;
        transform.position = new Vector3(transform.position.x, y, transform.position.z);
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Player"))
        {
            // Collect coin
            GameManager.Instance?.AddCoins(1);
            AudioManager.Instance?.PlaySFX("Coin");

            // Return to pool
            ObjectPool.Instance?.ReturnToPool("Coin", gameObject);
        }
    }
}
