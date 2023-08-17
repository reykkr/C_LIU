using UnityEngine;

public class BombEffectManager : MonoBehaviour
{
    public GameObject meteorExplosionPrefab;

    public void Explode()
    {
        GameObject[] meteors = GameObject.FindGameObjectsWithTag("Meteor");
        foreach (var meteor in meteors)
        {
            Instantiate(meteorExplosionPrefab, meteor.transform.position, Quaternion.identity);
            Destroy(meteor);
        }
    }
}
