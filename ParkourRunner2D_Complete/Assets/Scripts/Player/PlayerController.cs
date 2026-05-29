using UnityEngine;
using System.Collections;

[RequireComponent(typeof(Rigidbody2D))]
[RequireComponent(typeof(Animator))]
public class PlayerController : MonoBehaviour
{
    [Header("Movement Settings")]
    [SerializeField] private float baseSpeed = 8f;
    [SerializeField] private float maxSpeed = 15f;
    [SerializeField] private float acceleration = 20f;
    [SerializeField] private float deceleration = 15f;
    [SerializeField] private float jumpForce = 12f;
    [SerializeField] private float doubleJumpForce = 10f;
    [SerializeField] private float wallJumpForce = 14f;
    [SerializeField] private float slideSpeed = 12f;
    [SerializeField] private float dashForce = 25f;
    [SerializeField] private float grappleForce = 18f;

    [Header("Ground Detection")]
    [SerializeField] private Transform groundCheck;
    [SerializeField] private Transform wallCheck;
    [SerializeField] private float groundCheckRadius = 0.3f;
    [SerializeField] private float wallCheckDistance = 0.5f;
    [SerializeField] private LayerMask groundLayer;
    [SerializeField] private LayerMask wallLayer;

    [Header("Parkour Settings")]
    [SerializeField] private float vaultHeight = 1.5f;
    [SerializeField] private float wallRunDuration = 1.5f;
    [SerializeField] private float slideDuration = 0.8f;
    [SerializeField] private float dashDuration = 0.2f;
    [SerializeField] private float dashCooldown = 1f;
    [SerializeField] private float grappleRange = 10f;
    [SerializeField] private float swingForce = 15f;

    [Header("Physics")]
    [SerializeField] private float gravityScale = 3f;
    [SerializeField] private float fallMultiplier = 2.5f;
    [SerializeField] private float lowJumpMultiplier = 2f;
    [SerializeField] private float coyoteTime = 0.1f;
    [SerializeField] private float jumpBufferTime = 0.1f;

    [Header("Mobile Controls")]
    [SerializeField] private float swipeThreshold = 50f;
    [SerializeField] private float tapMaxTime = 0.2f;

    // Components
    private Rigidbody2D rb;
    private Animator anim;
    private SpriteRenderer spriteRenderer;
    private TrailRenderer trailRenderer;

    // State
    private bool isGrounded;
    private bool isWallSliding;
    private bool isSliding;
    private bool isDashing;
    private bool isGrappling;
    private bool isWallRunning;
    private bool isVaulting;
    private bool canDoubleJump;
    private bool canDash = true;
    private bool facingRight = true;

    // Timers
    private float coyoteTimeCounter;
    private float jumpBufferCounter;
    private float slideTimer;
    private float dashTimer;
    private float wallRunTimer;
    private float currentSpeed;

    // Input
    private Vector2 moveInput;
    private bool jumpPressed;
    private bool jumpHeld;
    private bool slidePressed;
    private bool dashPressed;

    // Mobile
    private Vector2 touchStartPos;
    private float touchStartTime;
    private bool isTouching;

    // Checkpoint
    private Vector3 checkpointPosition;
    private int checkpointChunk;

    // Combo System
    private int comboCount = 0;
    private float comboTimer = 0f;
    private float comboWindow = 2f;

    // Events
    public System.Action<string> OnParkourMove;
    public System.Action<int> OnComboUpdate;

    void Awake()
    {
        rb = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        trailRenderer = GetComponentInChildren<TrailRenderer>();

        rb.gravityScale = gravityScale;
        rb.interpolation = RigidbodyInterpolation2D.Interpolate;
        rb.collisionDetectionMode = CollisionDetectionMode2D.Continuous;

        checkpointPosition = transform.position;
    }

    void Update()
    {
        if (GameManager.Instance?.CurrentState != GameState.Playing) return;

        HandleInput();
        UpdateTimers();
        CheckGround();
        CheckWall();
        UpdateAnimations();
        UpdateCombo();
    }

    void FixedUpdate()
    {
        if (GameManager.Instance?.CurrentState != GameState.Playing) return;

        if (!isDashing && !isGrappling && !isVaulting)
        {
            HandleMovement();
            HandleJump();
            HandleWallSlide();
            HandleSlide();
            HandleWallRun();
        }

        ApplyBetterGravity();
    }

    void HandleInput()
    {
        // Keyboard (for testing)
        moveInput = new Vector2(Input.GetAxisRaw("Horizontal"), 0);
        jumpPressed = Input.GetButtonDown("Jump");
        jumpHeld = Input.GetButton("Jump");
        slidePressed = Input.GetKeyDown(KeyCode.S) || Input.GetKeyDown(KeyCode.LeftControl);
        dashPressed = Input.GetKeyDown(KeyCode.LeftShift);

        // Mobile Touch Input
        HandleMobileInput();

        // Input buffering
        if (jumpPressed)
        {
            jumpBufferCounter = jumpBufferTime;
        }
    }

    void HandleMobileInput()
    {
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);

            switch (touch.phase)
            {
                case TouchPhase.Began:
                    touchStartPos = touch.position;
                    touchStartTime = Time.time;
                    isTouching = true;
                    break;

                case TouchPhase.Ended:
                    if (!isTouching) return;
                    isTouching = false;

                    Vector2 swipeDelta = touch.position - touchStartPos;
                    float swipeTime = Time.time - touchStartTime;

                    // Tap detection
                    if (swipeTime < tapMaxTime && swipeDelta.magnitude < swipeThreshold)
                    {
                        jumpPressed = true;
                        jumpBufferCounter = jumpBufferTime;
                    }
                    // Swipe detection
                    else if (swipeDelta.magnitude > swipeThreshold)
                    {
                        float angle = Mathf.Atan2(swipeDelta.y, swipeDelta.x) * Mathf.Rad2Deg;

                        if (angle > 45 && angle < 135) // Up swipe
                        {
                            jumpPressed = true;
                            jumpBufferCounter = jumpBufferTime;
                        }
                        else if (angle > -135 && angle < -45) // Down swipe
                        {
                            slidePressed = true;
                        }
                        else if (Mathf.Abs(angle) < 45 && swipeDelta.x > 0) // Right swipe
                        {
                            dashPressed = true;
                        }
                    }
                    break;
            }
        }
    }

    void HandleMovement()
    {
        // Auto-run forward with slight control
        float targetSpeed = baseSpeed + (moveInput.x * 2f);
        targetSpeed = Mathf.Clamp(targetSpeed, baseSpeed * 0.5f, maxSpeed);

        // Smooth acceleration
        currentSpeed = Mathf.MoveTowards(currentSpeed, targetSpeed, acceleration * Time.fixedDeltaTime);

        // Apply velocity
        Vector2 velocity = rb.velocity;
        velocity.x = currentSpeed;
        rb.velocity = velocity;

        // Face direction
        if (velocity.x > 0.1f && !facingRight)
            Flip();
        else if (velocity.x < -0.1f && facingRight)
            Flip();
    }

    void HandleJump()
    {
        // Coyote time
        if (isGrounded)
        {
            coyoteTimeCounter = coyoteTime;
            canDoubleJump = true;
        }
        else
        {
            coyoteTimeCounter -= Time.fixedDeltaTime;
        }

        jumpBufferCounter -= Time.fixedDeltaTime;

        if (jumpBufferCounter > 0 && coyoteTimeCounter > 0)
        {
            ExecuteJump(jumpForce);
            jumpBufferCounter = 0;
            coyoteTimeCounter = 0;
            AddCombo("Jump");
        }
        else if (jumpBufferCounter > 0 && canDoubleJump && !isGrounded)
        {
            ExecuteJump(doubleJumpForce);
            canDoubleJump = false;
            jumpBufferCounter = 0;
            AddCombo("DoubleJump");

            // Visual effect
            CreateDustEffect();
        }
    }

    void ExecuteJump(float force)
    {
        Vector2 velocity = rb.velocity;
        velocity.y = force;
        rb.velocity = velocity;

        anim.SetTrigger("Jump");
        AudioManager.Instance?.PlaySFX("Jump");

        // Haptic feedback
        HapticFeedback();
    }

    void HandleWallSlide()
    {
        if (isWallSliding && !isGrounded && rb.velocity.y < 0)
        {
            rb.velocity = new Vector2(rb.velocity.x, Mathf.Clamp(rb.velocity.y, -2f, float.MaxValue));
            anim.SetBool("WallSlide", true);
        }
        else
        {
            anim.SetBool("WallSlide", false);
        }
    }

    void HandleWallRun()
    {
        if (isWallRunning)
        {
            wallRunTimer -= Time.fixedDeltaTime;
            rb.gravityScale = 0.5f;
            rb.velocity = new Vector2(rb.velocity.x, 2f);

            if (wallRunTimer <= 0)
            {
                isWallRunning = false;
                rb.gravityScale = gravityScale;
            }
        }
    }

    void HandleSlide()
    {
        if (slidePressed && isGrounded && !isSliding)
        {
            StartSlide();
        }

        if (isSliding)
        {
            slideTimer -= Time.fixedDeltaTime;

            if (slideTimer <= 0 || (!isGrounded))
            {
                EndSlide();
            }
        }
    }

    void StartSlide()
    {
        isSliding = true;
        slideTimer = slideDuration;

        // Reduce collider size
        GetComponent<CapsuleCollider2D>().size = new Vector2(1f, 0.5f);
        GetComponent<CapsuleCollider2D>().offset = new Vector2(0f, -0.25f);

        // Boost speed
        rb.velocity = new Vector2(slideSpeed, rb.velocity.y);

        anim.SetBool("Slide", true);
        AudioManager.Instance?.PlaySFX("Slide");
        AddCombo("Slide");

        HapticFeedback();
    }

    void EndSlide()
    {
        isSliding = false;

        // Restore collider
        GetComponent<CapsuleCollider2D>().size = new Vector2(1f, 2f);
        GetComponent<CapsuleCollider2D>().offset = new Vector2(0f, 0f);

        anim.SetBool("Slide", false);
    }

    public void PerformDash()
    {
        if (canDash && !isDashing)
        {
            StartCoroutine(DashCoroutine());
        }
    }

    IEnumerator DashCoroutine()
    {
        isDashing = true;
        canDash = false;

        float originalGravity = rb.gravityScale;
        rb.gravityScale = 0f;
        rb.velocity = new Vector2(dashForce * (facingRight ? 1 : -1), 0);

        if (trailRenderer != null)
            trailRenderer.emitting = true;

        anim.SetTrigger("Dash");
        AudioManager.Instance?.PlaySFX("Dash");
        AddCombo("Dash");

        yield return new WaitForSeconds(dashDuration);

        isDashing = false;
        rb.gravityScale = originalGravity;

        if (trailRenderer != null)
            trailRenderer.emitting = false;

        yield return new WaitForSeconds(dashCooldown);
        canDash = true;
    }

    public void PerformVault()
    {
        if (!isVaulting)
        {
            StartCoroutine(VaultCoroutine());
        }
    }

    IEnumerator VaultCoroutine()
    {
        isVaulting = true;

        rb.velocity = new Vector2(rb.velocity.x, vaultHeight);
        anim.SetTrigger("Vault");
        AudioManager.Instance?.PlaySFX("Vault");
        AddCombo("Vault");

        yield return new WaitForSeconds(0.3f);

        isVaulting = false;
    }

    public void PerformGrapple(Vector2 targetPoint)
    {
        if (!isGrappling)
        {
            StartCoroutine(GrappleCoroutine(targetPoint));
        }
    }

    IEnumerator GrappleCoroutine(Vector2 targetPoint)
    {
        isGrappling = true;

        Vector2 direction = (targetPoint - (Vector2)transform.position).normalized;
        rb.velocity = direction * grappleForce;

        anim.SetTrigger("Grapple");
        AudioManager.Instance?.PlaySFX("Grapple");
        AddCombo("Grapple");

        yield return new WaitForSeconds(0.5f);

        isGrappling = false;
    }

    void ApplyBetterGravity()
    {
        if (rb.velocity.y < 0)
        {
            rb.velocity += Vector2.up * Physics2D.gravity.y * (fallMultiplier - 1) * Time.fixedDeltaTime;
        }
        else if (rb.velocity.y > 0 && !jumpHeld)
        {
            rb.velocity += Vector2.up * Physics2D.gravity.y * (lowJumpMultiplier - 1) * Time.fixedDeltaTime;
        }
    }

    void CheckGround()
    {
        isGrounded = Physics2D.OverlapCircle(groundCheck.position, groundCheckRadius, groundLayer);
        anim.SetBool("Grounded", isGrounded);
    }

    void CheckWall()
    {
        bool wallDetected = Physics2D.Raycast(wallCheck.position, Vector2.right * (facingRight ? 1 : -1), wallCheckDistance, wallLayer);
        isWallSliding = wallDetected && !isGrounded && rb.velocity.y < 0;

        // Wall run detection
        if (wallDetected && jumpPressed && !isGrounded)
        {
            isWallRunning = true;
            wallRunTimer = wallRunDuration;
            AddCombo("WallRun");
        }
    }

    void Flip()
    {
        facingRight = !facingRight;
        Vector3 scale = transform.localScale;
        scale.x *= -1;
        transform.localScale = scale;
    }

    void UpdateTimers()
    {
        if (dashTimer > 0) dashTimer -= Time.deltaTime;
    }

    void UpdateAnimations()
    {
        anim.SetFloat("Speed", Mathf.Abs(rb.velocity.x));
        anim.SetFloat("VerticalSpeed", rb.velocity.y);
        anim.SetBool("Dashing", isDashing);
        anim.SetBool("Grappling", isGrappling);
    }

    void UpdateCombo()
    {
        if (comboCount > 0)
        {
            comboTimer -= Time.deltaTime;
            if (comboTimer <= 0)
            {
                // Combo ended - award points
                int comboPoints = comboCount * 100;
                GameManager.Instance?.AddScore(comboPoints);
                comboCount = 0;
                OnComboUpdate?.Invoke(comboCount);
            }
        }
    }

    void AddCombo(string moveName)
    {
        comboCount++;
        comboTimer = comboWindow;
        OnParkourMove?.Invoke(moveName);
        OnComboUpdate?.Invoke(comboCount);

        // Score for individual move
        GameManager.Instance?.AddScore(50);
    }

    void CreateDustEffect()
    {
        // Particle effect would be instantiated here
    }

    void HapticFeedback()
    {
        #if UNITY_ANDROID || UNITY_IOS
        Handheld.Vibrate();
        #endif
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Coin"))
        {
            GameManager.Instance?.AddCoins(1);
            Destroy(other.gameObject);
            AudioManager.Instance?.PlaySFX("Coin");
        }
        else if (other.CompareTag("Checkpoint"))
        {
            SetCheckpoint(other.transform.position);
            GameManager.Instance?.ChangeState(GameState.Checkpoint);
        }
        else if (other.CompareTag("Hazard"))
        {
            if (!isDashing)
            {
                Die();
            }
        }
        else if (other.CompareTag("Collectible"))
        {
            other.GetComponent<ICollectible>()?.Collect();
        }
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Enemy"))
        {
            if (isDashing || isSliding)
            {
                // Kill enemy
                collision.gameObject.GetComponent<EnemyBase>()?.TakeDamage(1);
                AddCombo("EnemyKill");
            }
            else
            {
                Die();
            }
        }
    }

    void SetCheckpoint(Vector3 position)
    {
        checkpointPosition = position;
        checkpointChunk = GameManager.Instance?.CurrentChunk ?? 0;
        AudioManager.Instance?.PlaySFX("Checkpoint");
    }

    public void RespawnAtCheckpoint()
    {
        transform.position = checkpointPosition;
        rb.velocity = Vector2.zero;
        currentSpeed = baseSpeed;

        // Reset states
        isDashing = false;
        isGrappling = false;
        isSliding = false;
        isWallRunning = false;
        isVaulting = false;

        anim.SetTrigger("Respawn");
        AudioManager.Instance?.PlaySFX("Respawn");
    }

    public void ResetPlayer()
    {
        transform.position = Vector3.zero;
        checkpointPosition = Vector3.zero;
        rb.velocity = Vector2.zero;
        currentSpeed = baseSpeed;
        comboCount = 0;

        // Reset all states
        isDashing = false;
        isGrappling = false;
        isSliding = false;
        isWallRunning = false;
        isVaulting = false;
        canDash = true;
    }

    void Die()
    {
        anim.SetTrigger("Die");
        AudioManager.Instance?.PlaySFX("Die");

        // Slow motion effect
        StartCoroutine(DeathSlowMotion());
    }

    IEnumerator DeathSlowMotion()
    {
        Time.timeScale = 0.3f;
        yield return new WaitForSecondsRealtime(0.5f);
        Time.timeScale = 1f;

        GameManager.Instance?.GameOver();
    }

    void OnDrawGizmos()
    {
        // Ground check
        Gizmos.color = Color.green;
        Gizmos.DrawWireSphere(groundCheck.position, groundCheckRadius);

        // Wall check
        Gizmos.color = Color.blue;
        Gizmos.DrawLine(wallCheck.position, wallCheck.position + Vector3.right * wallCheckDistance);

        // Grapple range
        Gizmos.color = Color.yellow;
        Gizmos.DrawWireSphere(transform.position, grappleRange);
    }
}
