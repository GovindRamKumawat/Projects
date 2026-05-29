using UnityEngine;

[CreateAssetMenu(fileName = "NewCharacter", menuName = "Parkour Runner/Character Data")]
public class CharacterData : ScriptableObject
{
    [Header("Basic Info")]
    public string characterName = "Runner";
    public string description = "Default runner";
    public Sprite portrait;
    public Sprite fullBodySprite;
    public RuntimeAnimatorController animatorController;

    [Header("Stats")]
    public float speedMultiplier = 1f;
    public float jumpMultiplier = 1f;
    public float staminaMultiplier = 1f;
    public float dashCooldownMultiplier = 1f;
    public int maxHealth = 1;

    [Header("Abilities")]
    public bool canDoubleJump = true;
    public bool canWallRun = true;
    public bool canGrapple = false;
    public bool hasSpecialAbility = false;
    public string specialAbilityName = "";
    public float specialAbilityCooldown = 10f;

    [Header("Visual")]
    public Color trailColor = Color.white;
    public ParticleSystem runEffect;
    public ParticleSystem jumpEffect;
    public ParticleSystem landEffect;

    [Header("Audio")]
    public AudioClip[] jumpSounds;
    public AudioClip[] landSounds;
    public AudioClip[] hurtSounds;
    public AudioClip specialAbilitySound;

    [Header("Unlock")]
    public int unlockCost = 0;
    public string unlockCondition = "Default";
    public bool isUnlocked = true;
    public bool isPremium = false;

    [Header("Voice Lines")]
    public AudioClip[] startLines;
    public AudioClip[] jumpLines;
    public AudioClip[] landLines;
    public AudioClip[] hurtLines;
    public AudioClip[] deathLines;
    public AudioClip[] checkpointLines;
}

public class CharacterManager : MonoBehaviour
{
    public static CharacterManager Instance { get; private set; }

    [Header("Characters")]
    [SerializeField] private CharacterData[] characters;
    [SerializeField] private int selectedCharacterIndex = 0;

    [Header("References")]
    [SerializeField] private PlayerController player;

    // Events
    public System.Action<CharacterData> OnCharacterSelected;
    public System.Action<CharacterData> OnCharacterUnlocked;

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

        LoadCharacterProgress();
    }

    void LoadCharacterProgress()
    {
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null && data.UnlockedCharacters != null)
        {
            for (int i = 0; i < characters.Length && i < data.UnlockedCharacters.Length; i++)
            {
                characters[i].isUnlocked = data.UnlockedCharacters[i];
            }
        }
    }

    public void SelectCharacter(int index)
    {
        if (index < 0 || index >= characters.Length) return;

        CharacterData character = characters[index];

        if (!character.isUnlocked)
        {
            Debug.Log($"Character {character.characterName} is locked!");
            return;
        }

        selectedCharacterIndex = index;

        // Apply to player
        ApplyCharacterToPlayer(character);

        OnCharacterSelected?.Invoke(character);

        // Save selection
        PlayerPrefs.SetInt("SelectedCharacter", index);
    }

    void ApplyCharacterToPlayer(CharacterData character)
    {
        if (player == null) return;

        // Apply stats
        // player.SetSpeedMultiplier(character.speedMultiplier);
        // player.SetJumpMultiplier(character.jumpMultiplier);

        // Apply visuals
        // player.SetTrailColor(character.trailColor);

        // Apply animator
        Animator anim = player.GetComponent<Animator>();
        if (anim != null && character.animatorController != null)
        {
            anim.runtimeAnimatorController = character.animatorController;
        }

        // Apply abilities
        // player.SetAbilities(character.canDoubleJump, character.canWallRun, character.canGrapple);
    }

    public bool UnlockCharacter(int index)
    {
        if (index < 0 || index >= characters.Length) return false;

        CharacterData character = characters[index];

        if (character.isUnlocked) return true;

        // Check cost
        int coins = GameManager.Instance?.Coins ?? 0;

        if (coins >= character.unlockCost)
        {
            // Deduct coins
            GameManager.Instance?.AddCoins(-character.unlockCost);

            // Unlock
            character.isUnlocked = true;

            // Save
            SaveManager.Instance?.UnlockCharacter(index);

            OnCharacterUnlocked?.Invoke(character);

            AudioManager.Instance?.PlaySFX("Unlock");

            return true;
        }

        return false;
    }

    public CharacterData GetSelectedCharacter()
    {
        if (selectedCharacterIndex >= 0 && selectedCharacterIndex < characters.Length)
        {
            return characters[selectedCharacterIndex];
        }
        return characters[0];
    }

    public CharacterData GetCharacter(int index)
    {
        if (index >= 0 && index < characters.Length)
        {
            return characters[index];
        }
        return null;
    }

    public CharacterData[] GetAllCharacters()
    {
        return characters;
    }

    public CharacterData[] GetUnlockedCharacters()
    {
        System.Collections.Generic.List<CharacterData> unlocked = new System.Collections.Generic.List<CharacterData>();
        foreach (var character in characters)
        {
            if (character.isUnlocked)
                unlocked.Add(character);
        }
        return unlocked.ToArray();
    }

    public int GetSelectedIndex()
    {
        return selectedCharacterIndex;
    }
}
