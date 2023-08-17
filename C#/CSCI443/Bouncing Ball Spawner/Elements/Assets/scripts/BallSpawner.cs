using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallSpawner : MonoBehaviour
{
    public Camera mainCamera;
    public GameObject ballPrefab;
    private float screenWidth;
    private float screenHeight;

    private void Start()
    {
        screenWidth = Screen.width;
        screenHeight = Screen.height;
    }

    private void Update()
    {
        float clampedX = Mathf.Clamp(Input.mousePosition.x, 0, screenWidth);
        float clampedY = Mathf.Clamp(Input.mousePosition.y, 0, screenHeight);

        Vector3 mousePosition = new Vector3(clampedX, clampedY, mainCamera.nearClipPlane);
        Vector3 spawnPosition = mainCamera.ScreenToWorldPoint(mousePosition);

        if (Input.GetMouseButtonDown(0))
        {
            Instantiate(ballPrefab, spawnPosition, Quaternion.identity);
        }
    }
}