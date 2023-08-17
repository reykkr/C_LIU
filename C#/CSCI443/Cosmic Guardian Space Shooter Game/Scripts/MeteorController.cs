using UnityEngine;

public class MeteorController : MonoBehaviour
{
    public float downwardSpeed = 5f;
    public float diagonalSpeed = 8f;

    private bool isDiagonal = false;

    private void Start()
    {
        isDiagonal = Random.Range(0, 2) == 1;
        if (isDiagonal)
        {
            Rigidbody2D rb = GetComponent<Rigidbody2D>();
            rb.velocity = new Vector2(-diagonalSpeed, -downwardSpeed);
        }
        else
        {
            Rigidbody2D rb = GetComponent<Rigidbody2D>();
            rb.velocity = new Vector2(0f, -downwardSpeed);
        }
    }

    public void DestroyMeteor()
    {
        Destroy(gameObject);
    }
}
