using UnityEngine;
using System;

[Serializable]
public class UpgradeData
{
    public string upgradeName;
    public string description;
    public Sprite icon;
    public int maxLevel = 5;
    public int baseCost = 100;
    public float costMultiplier = 1.5f;
    public float baseValue = 1f;
    public float valueMultiplier = 0.2f;
    public UpgradeType type;

    [HideInInspector] public int currentLevel = 0;

    public int GetCurrentCost()
    {
        return Mathf.RoundToInt(baseCost * Mathf.Pow(costMultiplier, currentLevel));
    }

    public float GetCurrentValue()
    {
        return baseValue + (baseValue * valueMultiplier * currentLevel);
    }

    public bool IsMaxLevel()
    {
        return currentLevel >= maxLevel;
    }

    public bool CanUpgrade(int availableCoins)
    {
        return !IsMaxLevel() && availableCoins >= GetCurrentCost();
    }

    public void Upgrade()
    {
        if (!IsMaxLevel())
        {
            currentLevel++;
        }
    }
}

public enum UpgradeType
{
    Speed,
    Jump,
    Stamina,
    Combo,
    Dash,
    Magnet,
    Shield,
    ScoreMultiplier,
    CoinMultiplier
}

public class UpgradeManager : MonoBehaviour
{
    public static UpgradeManager Instance { get; private set; }

    [Header("Upgrades")]
    [SerializeField] private UpgradeData[] upgrades;

    [Header("References")]
    [SerializeField] private UIManager uiManager;

    // Events
    public event Action<UpgradeData> OnUpgradePurchased;
    public event Action<UpgradeType, float> OnUpgradeApplied;

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

        LoadUpgrades();
    }

    void LoadUpgrades()
    {
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null)
        {
            // Load saved upgrade levels
            foreach (var upgrade in upgrades)
            {
                switch (upgrade.type)
                {
                    case UpgradeType.Speed: upgrade.currentLevel = data.SpeedLevel; break;
                    case UpgradeType.Jump: upgrade.currentLevel = data.JumpLevel; break;
                    case UpgradeType.Stamina: upgrade.currentLevel = data.StaminaLevel; break;
                    case UpgradeType.Combo: upgrade.currentLevel = data.ComboLevel; break;
                    case UpgradeType.Dash: upgrade.currentLevel = data.DashLevel; break;
                }
            }
        }
    }

    public bool PurchaseUpgrade(string upgradeName)
    {
        UpgradeData upgrade = GetUpgrade(upgradeName);
        if (upgrade == null) return false;

        int coins = GameManager.Instance?.Coins ?? 0;

        if (upgrade.CanUpgrade(coins))
        {
            int cost = upgrade.GetCurrentCost();

            // Deduct coins
            GameManager.Instance?.AddCoins(-cost);

            // Apply upgrade
            upgrade.Upgrade();

            // Save
            SaveUpgrade(upgrade);

            // Notify
            OnUpgradePurchased?.Invoke(upgrade);
            OnUpgradeApplied?.Invoke(upgrade.type, upgrade.GetCurrentValue());

            AudioManager.Instance?.PlaySFX("Upgrade");

            return true;
        }

        return false;
    }

    public bool PurchaseUpgrade(UpgradeType type)
    {
        UpgradeData upgrade = GetUpgrade(type);
        if (upgrade == null) return false;

        return PurchaseUpgrade(upgrade.upgradeName);
    }

    void SaveUpgrade(UpgradeData upgrade)
    {
        SaveManager.Instance?.UpgradeAbility(upgrade.type.ToString(), upgrade.currentLevel);
    }

    public UpgradeData GetUpgrade(string name)
    {
        foreach (var upgrade in upgrades)
        {
            if (upgrade.upgradeName == name)
                return upgrade;
        }
        return null;
    }

    public UpgradeData GetUpgrade(UpgradeType type)
    {
        foreach (var upgrade in upgrades)
        {
            if (upgrade.type == type)
                return upgrade;
        }
        return null;
    }

    public float GetUpgradeValue(UpgradeType type)
    {
        UpgradeData upgrade = GetUpgrade(type);
        if (upgrade != null)
        {
            return upgrade.GetCurrentValue();
        }
        return 1f;
    }

    public int GetUpgradeLevel(UpgradeType type)
    {
        UpgradeData upgrade = GetUpgrade(type);
        if (upgrade != null)
        {
            return upgrade.currentLevel;
        }
        return 0;
    }

    public UpgradeData[] GetAllUpgrades()
    {
        return upgrades;
    }

    public void ResetAllUpgrades()
    {
        foreach (var upgrade in upgrades)
        {
            upgrade.currentLevel = 0;
            SaveUpgrade(upgrade);
        }
    }

    // Apply upgrades to player
    public void ApplyUpgradesToPlayer(PlayerController player)
    {
        if (player == null) return;

        // These would modify player stats
        // player.SetSpeedMultiplier(GetUpgradeValue(UpgradeType.Speed));
        // player.SetJumpMultiplier(GetUpgradeValue(UpgradeType.Jump));
        // etc.
    }
}
