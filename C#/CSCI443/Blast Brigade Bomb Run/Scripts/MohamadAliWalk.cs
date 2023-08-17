using UnityEngine;

public class MohamadAliWalk : MonoBehaviour
{
    public float moveSpeed = 2f;
    public float respawnX = -10f;

    private void Update()
    {
        transform.Translate(Vector2.right * moveSpeed * Time.deltaTime);

        if (transform.position.x > respawnX)
            transform.position = new Vector2(respawnX, transform.position.y);
    }
}