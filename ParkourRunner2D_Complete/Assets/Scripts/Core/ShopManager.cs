using UnityEngine;
using System.Collections.Generic;

[CreateAssetMenu(fileName = "NewShopItem", menuName = "Parkour Runner/Shop Item")]
public class ShopItem : ScriptableObject
{
    public string itemName;
    public string description;
    public Sprite icon;
    public int price;
    public CurrencyType currency;
    public ItemType itemType;
    public string unlockCondition;
    public bool isLimited;
    public int stockLimit;
    public bool isPremium;

    [HideInInspector] public bool isPurchased;
    [HideInInspector] public int currentStock;
}

public enum CurrencyType
{
    Coins,
    TechParts,
    StylePoints,
    RareTokens,
    RealMoney
}

public enum ItemType
{
    Character,
    Style,
    Skin,
    Emote,
    Gadget,
    PowerUp,
    Bundle
}

public class ShopManager : MonoBehaviour
{
    public static ShopManager Instance { get; private set; }

    [Header("Shop Items")]
    [SerializeField] private List<ShopItem> allItems;

    [Header("Daily Deals")]
    [SerializeField] private List<ShopItem> dailyDeals;
    [SerializeField] private float dailyDealDiscount = 0.5f;

    [Header("Premium Currency")]
    [SerializeField] private int rareTokenPrice = 100;

    // Events
    public System.Action<ShopItem> OnItemPurchased;
    public System.Action<ShopItem> OnItemEquipped;

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

        LoadPurchasedItems();
    }

    void LoadPurchasedItems()
    {
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null)
        {
            // Load unlocked items from save data
            for (int i = 0; i < allItems.Count && i < data.UnlockedCharacters.Length; i++)
            {
                if (allItems[i].itemType == ItemType.Character)
                {
                    allItems[i].isPurchased = data.UnlockedCharacters[i];
                }
            }
        }
    }

    public bool PurchaseItem(ShopItem item)
    {
        if (item == null || item.isPurchased) return false;

        int currency = GetCurrencyAmount(item.currency);

        if (currency >= item.price)
        {
            // Deduct currency
            DeductCurrency(item.currency, item.price);

            // Mark as purchased
            item.isPurchased = true;

            // Save
            SavePurchase(item);

            // Notify
            OnItemPurchased?.Invoke(item);

            AudioManager.Instance?.PlaySFX("Purchase");

            return true;
        }

        return false;
    }

    public bool CanAfford(ShopItem item)
    {
        if (item == null) return false;
        return GetCurrencyAmount(item.currency) >= item.price;
    }

    int GetCurrencyAmount(CurrencyType currency)
    {
        switch (currency)
        {
            case CurrencyType.Coins:
                return GameManager.Instance?.Coins ?? 0;
            case CurrencyType.TechParts:
                return 0; // Implement tech parts system
            case CurrencyType.StylePoints:
                return 0; // Implement style points system
            case CurrencyType.RareTokens:
                return 0; // Implement rare tokens system
            default:
                return 0;
        }
    }

    void DeductCurrency(CurrencyType currency, int amount)
    {
        switch (currency)
        {
            case CurrencyType.Coins:
                GameManager.Instance?.AddCoins(-amount);
                break;
            // Handle other currencies
        }
    }

    void SavePurchase(ShopItem item)
    {
        SaveManager save = SaveManager.Instance;
        if (save == null) return;

        int index = allItems.IndexOf(item);
        if (index < 0) return;

        switch (item.itemType)
        {
            case ItemType.Character:
                save.UnlockCharacter(index);
                break;
            case ItemType.Style:
                save.UnlockStyle(index);
                break;
        }
    }

    public List<ShopItem> GetItemsByType(ItemType type)
    {
        return allItems.FindAll(item => item.itemType == type);
    }

    public List<ShopItem> GetAvailableItems()
    {
        return allItems.FindAll(item => !item.isPurchased);
    }

    public List<ShopItem> GetPurchasedItems()
    {
        return allItems.FindAll(item => item.isPurchased);
    }

    public List<ShopItem> GetDailyDeals()
    {
        return dailyDeals;
    }

    public int GetDiscountedPrice(ShopItem item)
    {
        return Mathf.RoundToInt(item.price * (1f - dailyDealDiscount));
    }
}
