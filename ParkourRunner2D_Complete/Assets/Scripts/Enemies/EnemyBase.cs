using UnityEngine;
using System.Collections;

public abstract class EnemyBase : MonoBehaviour
{
    [Header("Base Stats")]
    [SerializeField] protected int health = 1;
    [SerializeField] protected float speed = 3f;
    [SerializeField] protected int damage = 1;
    [SerializeField] protected int scoreValue = 100;

    [Header("Detection")]
    [SerializeField] protected float detectionRange = 10f;
    [SerializeField] protected float attackRange = 2f;
    [SerializeField] protected LayerMask playerLayer;

    [Header("Movement")]
    [SerializeField] protected bool canPatrol = true;
    [SerializeField] protected float patrolDistance = 3f;
    [SerializeField] protected float patrolWaitTime = 1f;

    // Components
    protected Rigidbody2D rb;
    protected Animator anim;
    protected SpriteRenderer sr;

    // State
    protected EnemyState currentState = EnemyState.Idle;
    protected Vector2 startPosition;
    protected Vector2 patrolTarget;
    protected Transform player;
    protected bool facingRight = true;
    protected float stateTimer;

    // Events
    public System.Action OnDeath;

    protected virtual void Awake()
    {
        rb = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        sr = GetComponent<SpriteRenderer>();

        startPosition = transform.position;
        patrolTarget = startPosition + Vector2.right * patrolDistance;
    }

    protected virtual void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player")?.transform;
    }

    protected virtual void Update()
    {
        if (GameManager.Instance?.CurrentState != GameState.Playing) return;

        UpdateState();
        UpdateAI();
    }

    protected virtual void UpdateState()
    {
        if (player == null) return;

        float distanceToPlayer = Vector2.Distance(transform.position, player.position);

        switch (currentState)
        {
            case EnemyState.Idle:
                if (distanceToPlayer < detectionRange)
                {
                    ChangeState(EnemyState.Chase);
                }
                else if (canPatrol)
                {
                    stateTimer += Time.deltaTime;
                    if (stateTimer >= patrolWaitTime)
                    {
                        ChangeState(EnemyState.Patrol);
                    }
                }
                break;

            case EnemyState.Patrol:
                if (distanceToPlayer < detectionRange)
                {
                    ChangeState(EnemyState.Chase);
                }
                break;

            case EnemyState.Chase:
                if (distanceToPlayer > detectionRange * 1.5f)
                {
                    ChangeState(EnemyState.Idle);
                }
                else if (distanceToPlayer < attackRange)
                {
                    ChangeState(EnemyState.Attack);
                }
                break;

            case EnemyState.Attack:
                if (distanceToPlayer > attackRange * 1.2f)
                {
                    ChangeState(EnemyState.Chase);
                }
                break;

            case EnemyState.Search:
                stateTimer += Time.deltaTime;
                if (stateTimer >= 3f)
                {
                    ChangeState(EnemyState.Idle);
                }
                break;

            case EnemyState.Retreat:
                if (Vector2.Distance(transform.position, startPosition) < 1f)
                {
                    ChangeState(EnemyState.Idle);
                }
                break;
        }
    }

    protected virtual void UpdateAI()
    {
        switch (currentState)
        {
            case EnemyState.Idle:
                IdleBehavior();
                break;
            case EnemyState.Patrol:
                PatrolBehavior();
                break;
            case EnemyState.Chase:
                ChaseBehavior();
                break;
            case EnemyState.Attack:
                AttackBehavior();
                break;
            case EnemyState.Search:
                SearchBehavior();
                break;
            case EnemyState.Retreat:
                RetreatBehavior();
                break;
        }
    }

    protected virtual void IdleBehavior()
    {
        rb.velocity = new Vector2(0, rb.velocity.y);
        anim?.SetBool("Moving", false);
    }

    protected virtual void PatrolBehavior()
    {
        Vector2 direction = (patrolTarget - (Vector2)transform.position).normalized;
        rb.velocity = new Vector2(direction.x * speed * 0.5f, rb.velocity.y);

        anim?.SetBool("Moving", true);

        // Check if reached patrol target
        if (Vector2.Distance(transform.position, patrolTarget) < 0.5f)
        {
            patrolTarget = patrolTarget.x > startPosition.x 
                ? startPosition - Vector2.right * patrolDistance 
                : startPosition + Vector2.right * patrolDistance;

            ChangeState(EnemyState.Idle);
        }

        FaceDirection(direction.x);
    }

    protected virtual void ChaseBehavior()
    {
        if (player == null) return;

        Vector2 direction = (player.position - transform.position).normalized;
        rb.velocity = new Vector2(direction.x * speed, rb.velocity.y);

        anim?.SetBool("Moving", true);
        anim?.SetBool("Chasing", true);

        FaceDirection(direction.x);
    }

    protected virtual void AttackBehavior()
    {
        rb.velocity = new Vector2(0, rb.velocity.y);
        anim?.SetTrigger("Attack");

        // Perform attack
        PerformAttack();
    }

    protected virtual void SearchBehavior()
    {
        // Look around
        rb.velocity = new Vector2(0, rb.velocity.y);
        anim?.SetBool("Searching", true);
    }

    protected virtual void RetreatBehavior()
    {
        Vector2 direction = (startPosition - (Vector2)transform.position).normalized;
        rb.velocity = new Vector2(direction.x * speed, rb.velocity.y);

        FaceDirection(direction.x);
    }

    protected virtual void PerformAttack()
    {
        // Override in derived classes
    }

    protected void ChangeState(EnemyState newState)
    {
        if (currentState == newState) return;

        currentState = newState;
        stateTimer = 0f;

        anim?.SetBool("Chasing", false);
        anim?.SetBool("Searching", false);

        OnStateChanged(newState);
    }

    protected virtual void OnStateChanged(EnemyState newState)
    {
        // Override in derived classes
    }

    protected void FaceDirection(float direction)
    {
        if (direction > 0 && !facingRight)
        {
            facingRight = true;
            Flip();
        }
        else if (direction < 0 && facingRight)
        {
            facingRight = false;
            Flip();
        }
    }

    void Flip()
    {
        Vector3 scale = transform.localScale;
        scale.x *= -1;
        transform.localScale = scale;
    }

    public virtual void TakeDamage(int damage)
    {
        health -= damage;

        // Flash effect
        StartCoroutine(DamageFlash());

        anim?.SetTrigger("Hit");

        if (health <= 0)
        {
            Die();
        }
    }

    IEnumerator DamageFlash()
    {
        if (sr != null)
        {
            sr.color = Color.red;
            yield return new WaitForSeconds(0.1f);
            sr.color = Color.white;
        }
    }

    protected virtual void Die()
    {
        anim?.SetTrigger("Die");

        // Award score
        GameManager.Instance?.AddScore(scoreValue);

        OnDeath?.Invoke();

        // Disable collider
        GetComponent<Collider2D>()?.enabled(false);

        // Destroy after animation
        Destroy(gameObject, 1f);
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Player"))
        {
            // Player hit enemy
            PlayerController player = other.GetComponent<PlayerController>();
            if (player != null && currentState != EnemyState.Dead)
            {
                // Player takes damage or enemy dies if player is dashing
            }
        }
    }

    void OnDrawGizmos()
    {
        Gizmos.color = Color.yellow;
        Gizmos.DrawWireSphere(transform.position, detectionRange);

        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, attackRange);

        if (canPatrol)
        {
            Gizmos.color = Color.blue;
            Gizmos.DrawLine(startPosition - Vector2.right * patrolDistance, 
                           startPosition + Vector2.right * patrolDistance);
        }
    }
}

public enum EnemyState
{
    Idle,
    Patrol,
    Chase,
    Attack,
    Search,
    Retreat,
    Dead
}

// Specific Enemy Types

public class DroneEnemy : EnemyBase
{
    [Header("Drone Settings")]
    [SerializeField] private float hoverHeight = 2f;
    [SerializeField] private float hoverSpeed = 2f;
    [SerializeField] private GameObject projectilePrefab;
    [SerializeField] private float shootCooldown = 2f;

    private float shootTimer;
    private float hoverOffset;

    protected override void Awake()
    {
        base.Awake();
        hoverOffset = Random.Range(0f, Mathf.PI * 2f);
    }

    protected override void UpdateAI()
    {
        // Hover movement
        float hoverY = Mathf.Sin(Time.time * hoverSpeed + hoverOffset) * 0.5f;
        rb.velocity = new Vector2(rb.velocity.x, hoverY);

        base.UpdateAI();

        // Shooting
        if (currentState == EnemyState.Chase || currentState == EnemyState.Attack)
        {
            shootTimer += Time.deltaTime;
            if (shootTimer >= shootCooldown)
            {
                Shoot();
                shootTimer = 0f;
            }
        }
    }

    void Shoot()
    {
        if (projectilePrefab == null || player == null) return;

        Vector2 direction = (player.position - transform.position).normalized;
        GameObject projectile = Instantiate(projectilePrefab, transform.position, Quaternion.identity);

        Rigidbody2D projRb = projectile.GetComponent<Rigidbody2D>();
        if (projRb != null)
        {
            projRb.velocity = direction * 10f;
        }

        anim?.SetTrigger("Shoot");
        AudioManager.Instance?.PlaySFX("DroneShoot");
    }
}

public class GuardEnemy : EnemyBase
{
    [Header("Guard Settings")]
    [SerializeField] private float blockChance = 0.3f;
    [SerializeField] private float chargeSpeed = 8f;
    [SerializeField] private float chargeCooldown = 3f;

    private float chargeTimer;
    private bool isCharging;

    protected override void ChaseBehavior()
    {
        if (isCharging)
        {
            // Continue charge
            return;
        }

        chargeTimer += Time.deltaTime;

        if (chargeTimer >= chargeCooldown && Random.value < 0.5f)
        {
            StartCoroutine(ChargeAttack());
        }
        else
        {
            base.ChaseBehavior();
        }
    }

    IEnumerator ChargeAttack()
    {
        isCharging = true;
        anim?.SetTrigger("Charge");

        // Wind up
        yield return new WaitForSeconds(0.5f);

        // Charge
        Vector2 chargeDirection = facingRight ? Vector2.right : Vector2.left;
        rb.velocity = chargeDirection * chargeSpeed;

        yield return new WaitForSeconds(0.5f);

        rb.velocity = Vector2.zero;
        isCharging = false;
        chargeTimer = 0f;
    }

    protected override void PerformAttack()
    {
        // Melee attack
        Collider2D[] hits = Physics2D.OverlapCircleAll(transform.position, 1.5f, playerLayer);
        foreach (var hit in hits)
        {
            if (hit.CompareTag("Player"))
            {
                // Damage player
                hit.GetComponent<PlayerController>()?.Die();
            }
        }
    }
}

public class SniperEnemy : EnemyBase
{
    [Header("Sniper Settings")]
    [SerializeField] private float aimTime = 1.5f;
    [SerializeField] private GameObject laserSight;
    [SerializeField] private GameObject bulletPrefab;
    [SerializeField] private float reloadTime = 3f;

    private float aimTimer;
    private bool isAiming;

    protected override void UpdateAI()
    {
        if (isAiming)
        {
            aimTimer += Time.deltaTime;

            // Show laser sight
            if (laserSight != null)
                laserSight.SetActive(true);

            if (aimTimer >= aimTime)
            {
                Shoot();
                isAiming = false;
                aimTimer = 0f;

                if (laserSight != null)
                    laserSight.SetActive(false);
            }
        }
        else
        {
            base.UpdateAI();
        }
    }

    protected override void AttackBehavior()
    {
        rb.velocity = Vector2.zero;

        if (!isAiming)
        {
            isAiming = true;
            aimTimer = 0f;
            anim?.SetTrigger("Aim");
        }
    }

    void Shoot()
    {
        if (bulletPrefab == null || player == null) return;

        Vector2 direction = (player.position - transform.position).normalized;
        GameObject bullet = Instantiate(bulletPrefab, transform.position, Quaternion.identity);

        Rigidbody2D bulletRb = bullet.GetComponent<Rigidbody2D>();
        if (bulletRb != null)
        {
            bulletRb.velocity = direction * 20f;
        }

        anim?.SetTrigger("Shoot");
        AudioManager.Instance?.PlaySFX("SniperShot");
    }
}

public class RoboticDogEnemy : EnemyBase
{
    [Header("Robotic Dog Settings")]
    [SerializeField] private float jumpForce = 10f;
    [SerializeField] private float jumpCooldown = 2f;
    [SerializeField] private int jumpCount = 2;

    private int currentJumps;
    private float jumpTimer;
    private bool isJumping;

    protected override void ChaseBehavior()
    {
        base.ChaseBehavior();

        // Jump over obstacles
        if (isGrounded() && !isJumping)
        {
            jumpTimer += Time.deltaTime;
            if (jumpTimer >= jumpCooldown)
            {
                Jump();
                jumpTimer = 0f;
            }
        }
    }

    void Jump()
    {
        rb.velocity = new Vector2(rb.velocity.x, jumpForce);
        anim?.SetTrigger("Jump");
        isJumping = true;

        StartCoroutine(ResetJump());
    }

    IEnumerator ResetJump()
    {
        yield return new WaitForSeconds(0.5f);
        isJumping = false;
    }

    bool isGrounded()
    {
        return Physics2D.Raycast(transform.position, Vector2.down, 0.5f, LayerMask.GetMask("Ground"));
    }
}
