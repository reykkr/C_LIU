using UnityEngine;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour
{
    public float moveSpeed = 10f;
    public Transform jetTransform;
    public GameObject bombPrefab;
    public Text healthText;
    public Image gameOverImage;

    private int health = 100;
    private int maxBombs = 3;
    private int bombs = 0;

    private void Update()
    {
        HandleJetMovement();
        HandleShooting();
    }

    private void HandleJetMovement()
    {
        Vector3 mousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
        Vector3 clampedPosition = new Vector3(
            Mathf.Clamp(mousePosition.x, -8f, 8f),
            Mathf.Clamp(mousePosition.y, -4.5f, 4.5f),
            jetTransform.position.z
        );
        jetTransform.position = clampedPosition;
    }

    private void HandleShooting()
    {
        if (Input.GetMouseButtonDown(0) && bombs > 0)
        {
            Instantiate(bombPrefab, jetTransform.position, Quaternion.identity);
            bombs--;
        }
    }

    public void TakeDamage()
    {
        health -= Mathf.CeilToInt(health * 0.1f);
        healthText.text = $"Health: {health}";
        if (health <= 0)
        {
            gameOverImage.gameObject.SetActive(true);
            this.enabled = false;
        }
    }

    public void CollectBomb()
    {
        if (bombs < maxBombs)
        {
            bombs++;
        }
    }
    private void Update()
    {
        if (health <= 0)
        {
            StopGameComponents();
            return;
        }

        HandleJetMovement();
        HandleShooting();
    }

    private void StopGameComponents()
    {
        this.enabled = false; 

        MeteorController[] meteorControllers = FindObjectsOfType<MeteorController>();
        foreach (var meteorController in meteorControllers)
        {
            meteorController.enabled = false;
        }
        BombAnimation[] bombAnimations = FindObjectsOfType<BombAnimation>();
        foreach (var bombAnimation in bombAnimations)
        {
            bombAnimation.enabled = false;
        }
    }
    private void Update()
    {
        if (health <= 0)
        {
            StopGameComponents();
            return;
        }

        HandleJetMovement();
        HandleShooting();
    }

}
