using UnityEngine;

public class YourFirstNameSpawner : MonoBehaviour
{
    public GameObject bombPrefab;
    public float spawnInterval = 0.2f;
    public float spawnPosX = -3f;
    public float spawnPosY = -4f;

    private float spawnTimer = 0f;

    private void Update()
    {
        spawnTimer += Time.deltaTime;

        if (spawnTimer >= spawnInterval)
        {
            SpawnBomb();
            spawnTimer = 0f;
        }
    }

    private void SpawnBomb()
    {
        Instantiate(bombPrefab, new Vector2(spawnPosX, spawnPosY), Quaternion.identity);
    }
}
