using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine;

public class Arrow : MonoBehaviour
{
    public float Speed = 5.0f;

    void Update()
    {
        transform.Translate(Vector3.right * Speed * Time.deltaTime);
        
        float width = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, 0, 0)).x;
        if (transform.position.x > width)
        {
            Destroy(gameObject);
        }
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        Destroy(other.gameObject);
        Destroy(gameObject);
    }
}
