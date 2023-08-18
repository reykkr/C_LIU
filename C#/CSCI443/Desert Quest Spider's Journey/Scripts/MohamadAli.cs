using UnityEngine;

public class MohamadAli : MonoBehaviour
{
    public AudioClip audioClip;

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Spider"))
        {
            AudioSource.PlayClipAtPoint(audioClip, transform.position);
            Destroy(gameObject);
        }
    }
}
