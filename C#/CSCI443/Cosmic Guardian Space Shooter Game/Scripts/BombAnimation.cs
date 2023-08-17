using UnityEngine;

public class BombAnimation : MonoBehaviour
{
    public GameObject explosionPrefab;

    public void Explode()
    {
        Instantiate(explosionPrefab, transform.position, Quaternion.identity);
        Destroy(gameObject);
    }
}
