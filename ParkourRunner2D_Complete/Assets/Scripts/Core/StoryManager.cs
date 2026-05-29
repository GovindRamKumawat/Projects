using UnityEngine;
using System.Collections.Generic;

[CreateAssetMenu(fileName = "NewStoryChapter", menuName = "Parkour Runner/Story Chapter")]
public class StoryChapter : ScriptableObject
{
    public int chapterNumber;
    public string chapterTitle;
    public string description;
    public Sprite chapterImage;
    public List<DialogueSequence> dialogues;
    public string missionObjective;
    public string biomeName;
    public bool isUnlocked;
    public bool isCompleted;
    public int requiredScore;
}

[System.Serializable]
public class DialogueSequence
{
    public string speakerName;
    public Sprite speakerPortrait;
    public string dialogueText;
    public AudioClip voiceClip;
    public float typingSpeed = 0.05f;
    public DialogueEffect effect;
}

public enum DialogueEffect
{
    None,
    Shake,
    Flash,
    FadeIn,
    Typewriter
}

public class StoryManager : MonoBehaviour
{
    public static StoryManager Instance { get; private set; }

    [Header("Story Data")]
    [SerializeField] private List<StoryChapter> chapters;
    [SerializeField] private int currentChapter = 0;

    [Header("Dialogue UI")]
    [SerializeField] private GameObject dialoguePanel;
    [SerializeField] private UnityEngine.UI.Text speakerText;
    [SerializeField] private UnityEngine.UI.Text dialogueText;
    [SerializeField] private UnityEngine.UI.Image speakerPortrait;

    // Events
    public System.Action<StoryChapter> OnChapterStarted;
    public System.Action<StoryChapter> OnChapterCompleted;
    public System.Action OnDialogueStarted;
    public System.Action OnDialogueEnded;

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

        LoadProgress();
    }

    void LoadProgress()
    {
        SaveData data = SaveManager.Instance?.GetCurrentData();
        if (data != null)
        {
            // Load chapter progress
        }
    }

    public void StartChapter(int chapterIndex)
    {
        if (chapterIndex < 0 || chapterIndex >= chapters.Count) return;

        StoryChapter chapter = chapters[chapterIndex];

        if (!chapter.isUnlocked)
        {
            Debug.Log($"Chapter {chapterIndex} is locked!");
            return;
        }

        currentChapter = chapterIndex;
        OnChapterStarted?.Invoke(chapter);

        // Start dialogues
        if (chapter.dialogues != null && chapter.dialogues.Count > 0)
        {
            StartCoroutine(PlayDialogues(chapter.dialogues));
        }
    }

    System.Collections.IEnumerator PlayDialogues(List<DialogueSequence> dialogues)
    {
        OnDialogueStarted?.Invoke();

        foreach (var dialogue in dialogues)
        {
            yield return StartCoroutine(ShowDialogue(dialogue));

            // Wait for player input to continue
            yield return new WaitUntil(() => Input.GetMouseButtonDown(0) || Input.touchCount > 0);
            yield return null; // Wait one frame to avoid skipping
        }

        OnDialogueEnded?.Invoke();
    }

    System.Collections.IEnumerator ShowDialogue(DialogueSequence dialogue)
    {
        // Update UI
        if (speakerText != null)
            speakerText.text = dialogue.speakerName;

        if (speakerPortrait != null)
            speakerPortrait.sprite = dialogue.speakerPortrait;

        // Typewriter effect
        if (dialogueText != null)
        {
            dialogueText.text = "";

            for (int i = 0; i < dialogue.dialogueText.Length; i++)
            {
                dialogueText.text += dialogue.dialogueText[i];

                // Play voice if available
                if (dialogue.voiceClip != null && i % 3 == 0)
                {
                    AudioManager.Instance?.PlaySFX(dialogue.voiceClip);
                }

                yield return new WaitForSeconds(dialogue.typingSpeed);
            }
        }

        // Apply effects
        ApplyDialogueEffect(dialogue.effect);
    }

    void ApplyDialogueEffect(DialogueEffect effect)
    {
        switch (effect)
        {
            case DialogueEffect.Shake:
                Camera.main?.GetComponent<CameraController>()?.ShakeCamera(0.2f, 0.3f);
                break;
            case DialogueEffect.Flash:
                // Flash screen
                break;
            case DialogueEffect.FadeIn:
                // Fade in dialogue
                break;
        }
    }

    public void CompleteChapter(int chapterIndex)
    {
        if (chapterIndex < 0 || chapterIndex >= chapters.Count) return;

        chapters[chapterIndex].isCompleted = true;

        // Unlock next chapter
        if (chapterIndex + 1 < chapters.Count)
        {
            chapters[chapterIndex + 1].isUnlocked = true;
        }

        OnChapterCompleted?.Invoke(chapters[chapterIndex]);

        SaveProgress();
    }

    void SaveProgress()
    {
        // Save chapter progress
    }

    public StoryChapter GetCurrentChapter()
    {
        if (currentChapter >= 0 && currentChapter < chapters.Count)
        {
            return chapters[currentChapter];
        }
        return null;
    }

    public List<StoryChapter> GetAllChapters()
    {
        return chapters;
    }

    public bool IsChapterUnlocked(int index)
    {
        if (index >= 0 && index < chapters.Count)
        {
            return chapters[index].isUnlocked;
        }
        return false;
    }
}
