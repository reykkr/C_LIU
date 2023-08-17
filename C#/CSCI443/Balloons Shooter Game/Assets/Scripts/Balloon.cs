using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveBallon : MonoBehaviour
{
    private float time = 10;
    private float Timer;
    void Start()
    {
        
    }


    void Update()
    {
        Timer += Time.deltaTime;

        Vector2 speed = new Vector2(Random.Range(-2, 2), Random.Range(1, 4));

        transform.position += new Vector3(speed.x*Time.deltaTime, speed.y*Time.deltaTime, 0);


        if (Timer >= time)
        {
            Destroy(gameObject);
        }
    }
}
