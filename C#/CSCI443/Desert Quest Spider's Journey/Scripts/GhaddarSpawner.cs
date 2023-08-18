using UnityEngine;

public class GhaddarSpawner : MonoBehaviour
{
    public GameObject butterflyPrefab;
    public float minSpawnTime = 3f;
    public float maxSpawnTime = 5f;

    private float nextSpawnTime;

    private void Start()
    {
        SetNextSpawnTime();
    }

    private void Update()
    {
        if (Time.time >= nextSpawnTime)
        {
            Instantiate(butterflyPrefab, transform.position, Quaternion.identity);
            SetNextSpawnTime();
        }
    }

    private void SetNextSpawnTime()
    {
        nextSpawnTime = Time.time + Random.Range(minSpawnTime, maxSpawnTime);
    }
}
