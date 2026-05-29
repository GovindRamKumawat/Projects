using UnityEngine;

public class CameraController : MonoBehaviour
{
    [Header("Target")]
    [SerializeField] private Transform target;
    [SerializeField] private Vector3 offset = new Vector3(5f, 2f, -10f);

    [Header("Smoothing")]
    [SerializeField] private float smoothSpeed = 5f;
    [SerializeField] private float lookAheadDistance = 3f;
    [SerializeField] private float lookAheadSpeed = 3f;

    [Header("Dynamic Offset")]
    [SerializeField] private bool dynamicOffset = true;
    [SerializeField] private float speedOffsetMultiplier = 0.5f;
    [SerializeField] private float maxExtraOffset = 3f;

    [Header("Screen Shake")]
    [SerializeField] private float shakeDuration = 0.2f;
    [SerializeField] private float shakeIntensity = 0.3f;

    [Header("Bounds")]
    [SerializeField] private bool useBounds = false;
    [SerializeField] private Vector2 minBounds;
    [SerializeField] private Vector2 maxBounds;

    [Header("Effects")]
    [SerializeField] private bool useFOVEffect = true;
    [SerializeField] private float baseFOV = 60f;
    [SerializeField] private float maxFOV = 75f;
    [SerializeField] private float fovChangeSpeed = 2f;

    // Components
    private Camera cam;
    private Rigidbody2D targetRb;

    // Runtime
    private Vector3 currentVelocity;
    private Vector3 lookAheadPos;
    private float currentShakeIntensity;
    private float shakeTimer;
    private Vector3 shakeOffset;
    private float currentFOV;

    void Awake()
    {
        cam = GetComponent<Camera>();
        if (cam == null) cam = Camera.main;

        currentFOV = baseFOV;
    }

    void Start()
    {
        if (target == null)
        {
            // Auto-find player
            GameObject player = GameObject.FindGameObjectWithTag("Player");
            if (player != null)
            {
                target = player.transform;
                targetRb = player.GetComponent<Rigidbody2D>();
            }
        }
        else
        {
            targetRb = target.GetComponent<Rigidbody2D>();
        }
    }

    void LateUpdate()
    {
        if (target == null) return;
        if (GameManager.Instance?.CurrentState != GameState.Playing) return;

        // Calculate target position
        Vector3 targetPosition = CalculateTargetPosition();

        // Apply screen shake
        if (shakeTimer > 0)
        {
            shakeTimer -= Time.deltaTime;
            shakeOffset = Random.insideUnitSphere * currentShakeIntensity;
            shakeOffset.z = 0;
        }
        else
        {
            shakeOffset = Vector3.zero;
        }

        // Smooth follow
        Vector3 smoothedPosition = Vector3.SmoothDamp(
            transform.position, 
            targetPosition + shakeOffset, 
            ref currentVelocity, 
            1f / smoothSpeed
        );

        // Apply bounds
        if (useBounds)
        {
            smoothedPosition.x = Mathf.Clamp(smoothedPosition.x, minBounds.x, maxBounds.x);
            smoothedPosition.y = Mathf.Clamp(smoothedPosition.y, minBounds.y, maxBounds.y);
        }

        transform.position = smoothedPosition;

        // FOV effect based on speed
        if (useFOVEffect && targetRb != null)
        {
            float speed = targetRb.velocity.magnitude;
            float targetFOV = Mathf.Lerp(baseFOV, maxFOV, speed / 20f);
            currentFOV = Mathf.Lerp(currentFOV, targetFOV, Time.deltaTime * fovChangeSpeed);
            cam.fieldOfView = currentFOV;
        }
    }

    Vector3 CalculateTargetPosition()
    {
        Vector3 basePosition = target.position + offset;

        // Dynamic offset based on speed
        if (dynamicOffset && targetRb != null)
        {
            float speed = targetRb.velocity.x;
            float extraOffset = Mathf.Clamp(speed * speedOffsetMultiplier, 0, maxExtraOffset);
            basePosition.x += extraOffset;
        }

        // Look ahead
        if (targetRb != null)
        {
            Vector3 targetLookAhead = target.position + Vector3.right * lookAheadDistance;
            lookAheadPos = Vector3.Lerp(lookAheadPos, targetLookAhead, Time.deltaTime * lookAheadSpeed);
            basePosition.x = Mathf.Lerp(basePosition.x, lookAheadPos.x + offset.x, 0.3f);
        }

        return basePosition;
    }

    public void SetTarget(Transform newTarget)
    {
        target = newTarget;
        if (target != null)
        {
            targetRb = target.GetComponent<Rigidbody2D>();
        }
    }

    public void ShakeCamera(float intensity, float duration)
    {
        currentShakeIntensity = intensity;
        shakeTimer = duration;
    }

    public void ShakeCamera()
    {
        ShakeCamera(shakeIntensity, shakeDuration);
    }

    public void SetOffset(Vector3 newOffset)
    {
        offset = newOffset;
    }

    public void ResetCamera()
    {
        if (target != null)
        {
            transform.position = target.position + offset;
        }
    }
}
