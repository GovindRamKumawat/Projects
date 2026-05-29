using UnityEngine;
using UnityEngine.EventSystems;
using System;

public class MobileInputManager : MonoBehaviour
{
    public static MobileInputManager Instance { get; private set; }

    [Header("Touch Settings")]
    [SerializeField] private float swipeThreshold = 50f;
    [SerializeField] private float tapMaxDuration = 0.2f;
    [SerializeField] private float longPressDuration = 0.5f;
    [SerializeField] private float multiTapMaxDelay = 0.3f;

    [Header("Gesture Zones")]
    [SerializeField] private RectTransform leftZone;
    [SerializeField] private RectTransform rightZone;
    [SerializeField] private bool splitScreenControls = true;

    [Header("Sensitivity")]
    [SerializeField] private float swipeSensitivity = 1f;
    [SerializeField] private float tiltSensitivity = 2f;

    // Events
    public event Action OnTap;
    public event Action OnDoubleTap;
    public event Action OnLongPress;
    public event Action<Vector2> OnSwipeUp;
    public event Action<Vector2> OnSwipeDown;
    public event Action<Vector2> OnSwipeLeft;
    public event Action<Vector2> OnSwipeRight;
    public event Action<Vector2> OnTouchBegin;
    public event Action<Vector2> OnTouchEnd;
    public event Action<Vector2> OnTouchHold;

    // State
    private Vector2 touchStartPos;
    private float touchStartTime;
    private bool isTouching;
    private int tapCount;
    private float lastTapTime;
    private bool isLongPressTriggered;

    // Gyroscope
    private bool gyroEnabled;
    private Gyroscope gyro;

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

        InitializeGyro();
    }

    void InitializeGyro()
    {
        gyroEnabled = SystemInfo.supportsGyroscope;
        if (gyroEnabled)
        {
            gyro = Input.gyro;
            gyro.enabled = true;
        }
    }

    void Update()
    {
        if (GameManager.Instance?.CurrentState != GameState.Playing) return;

        HandleTouchInput();
        HandleGyroInput();
    }

    void HandleTouchInput()
    {
        if (Input.touchCount == 0)
        {
            if (isTouching)
            {
                // Touch ended
                isTouching = false;
                OnTouchEnd?.Invoke(touchStartPos);
            }
            return;
        }

        Touch touch = Input.GetTouch(0);
        Vector2 touchPos = touch.position;

        switch (touch.phase)
        {
            case TouchPhase.Began:
                touchStartPos = touchPos;
                touchStartTime = Time.time;
                isTouching = true;
                isLongPressTriggered = false;
                OnTouchBegin?.Invoke(touchPos);
                break;

            case TouchPhase.Stationary:
            case TouchPhase.Moved:
                if (isTouching)
                {
                    float touchDuration = Time.time - touchStartTime;

                    // Long press detection
                    if (!isLongPressTriggered && touchDuration >= longPressDuration)
                    {
                        isLongPressTriggered = true;
                        OnLongPress?.Invoke(touchPos);
                    }

                    // Continuous hold
                    if (touchDuration > tapMaxDuration)
                    {
                        OnTouchHold?.Invoke(touchPos);
                    }
                }
                break;

            case TouchPhase.Ended:
                if (!isTouching) return;
                isTouching = false;

                Vector2 swipeDelta = touchPos - touchStartPos;
                float swipeTime = Time.time - touchStartTime;
                float swipeDistance = swipeDelta.magnitude;

                OnTouchEnd?.Invoke(touchPos);

                // Tap detection
                if (swipeTime < tapMaxDuration && swipeDistance < swipeThreshold)
                {
                    HandleTap();
                }
                // Swipe detection
                else if (swipeDistance > swipeThreshold)
                {
                    HandleSwipe(swipeDelta);
                }
                break;

            case TouchPhase.Canceled:
                isTouching = false;
                break;
        }
    }

    void HandleTap()
    {
        // Check for double tap
        if (Time.time - lastTapTime < multiTapMaxDelay)
        {
            tapCount++;
        }
        else
        {
            tapCount = 1;
        }

        lastTapTime = Time.time;

        if (tapCount >= 2)
        {
            OnDoubleTap?.Invoke();
            tapCount = 0;
        }
        else
        {
            OnTap?.Invoke();
        }
    }

    void HandleSwipe(Vector2 swipeDelta)
    {
        float angle = Mathf.Atan2(swipeDelta.y, swipeDelta.x) * Mathf.Rad2Deg;

        // Normalize angle to 0-360
        if (angle < 0) angle += 360;

        // Determine swipe direction
        if (angle >= 45 && angle < 135) // Up
        {
            OnSwipeUp?.Invoke(swipeDelta * swipeSensitivity);
        }
        else if (angle >= 225 && angle < 315) // Down
        {
            OnSwipeDown?.Invoke(swipeDelta * swipeSensitivity);
        }
        else if (angle >= 135 && angle < 225) // Left
        {
            OnSwipeLeft?.Invoke(swipeDelta * swipeSensitivity);
        }
        else // Right
        {
            OnSwipeRight?.Invoke(swipeDelta * swipeSensitivity);
        }
    }

    void HandleGyroInput()
    {
        if (!gyroEnabled || gyro == null) return;

        Vector3 gyroRotation = gyro.rotationRateUnbiased;

        // Use gyro for subtle camera tilt or movement
        float tilt = gyroRotation.z * tiltSensitivity;

        // Could be used for leaning in parkour
        // GameManager.Instance?.Player?.ApplyGyroTilt(tilt);
    }

    // Public methods for button-based controls
    public void SimulateJump()
    {
        OnSwipeUp?.Invoke(Vector2.up * 100);
    }

    public void SimulateSlide()
    {
        OnSwipeDown?.Invoke(Vector2.down * 100);
    }

    public void SimulateDash()
    {
        OnSwipeRight?.Invoke(Vector2.right * 100);
    }

    public void SimulateGrapple()
    {
        OnDoubleTap?.Invoke();
    }

    // Utility
    public bool IsTouching()
    {
        return isTouching;
    }

    public Vector2 GetTouchPosition()
    {
        if (Input.touchCount > 0)
        {
            return Input.GetTouch(0).position;
        }
        return Vector2.zero;
    }

    public bool IsTouchInLeftZone(Vector2 position)
    {
        if (leftZone == null) return position.x < Screen.width / 2;
        return RectTransformUtility.RectangleContainsScreenPoint(leftZone, position);
    }

    public bool IsTouchInRightZone(Vector2 position)
    {
        if (rightZone == null) return position.x >= Screen.width / 2;
        return RectTransformUtility.RectangleContainsScreenPoint(rightZone, position);
    }
}
