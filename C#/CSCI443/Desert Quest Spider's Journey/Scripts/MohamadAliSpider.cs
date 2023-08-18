using UnityEngine;

public class MohamadAliSpider : MonoBehaviour
{
    public float moveSpeed = 5f;
    public int scoreIncrement = 1;

    private int score = 0;

    private void Update()
    {
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(horizontalInput, verticalInput, 0f) * moveSpeed * Time.deltaTime;
        transform.Translate(movement);

        if (Input.GetKeyDown(KeyCode.Space))
        {
            score += scoreIncrement;
        }
    }
}
