using UnityEngine;
using System.Collections.Generic;

public class BalloonSpawner : MonoBehaviour
{
    public GameObject BalloonPrefab;
    public int MaxBalloonCount = 8;
    public float SpawnInterval = 1.2f;

    private float[] xPositions;
    private List<GameObject> balloons = new List<GameObject>();
    private float time;

    void Start()
    {
        float width = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, 0, 0)).x;
        float dx = BalloonPrefab.GetComponent<SpriteRenderer>().sprite.bounds.extents.x;
        float x = -width + 3 * dx;
        int n = (int)((width - x) / dx);
        xPositions = new float[n];

        for (int i = 0; i < n; i++)
        {
            xPositions[i] = x;
            x += dx;
        }
    }

    void Update()
    {
        Flush();

        time += Time.deltaTime;
        if (time > SpawnInterval && balloons.Count < MaxBalloonCount)
        {
            time = 0;
            float x = xPositions[Random.Range(0, xPositions.Length)];
            GameObject b = Instantiate(BalloonPrefab);
            b.transform.position = new Vector3(x, -Camera.main.orthographicSize, 0);
            balloons.Add(b);
        }
    }

    void Flush()
    {
        balloons.RemoveAll(b => b == null);
    }
}
