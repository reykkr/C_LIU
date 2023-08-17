using UnityEngine;

public class AudioManager : MonoBehaviour
{
    public AudioClip bombExplosionSound;
    public AudioClip playerHitSound;

    private AudioSource audioSource;

    private void Start()
    {
        audioSource = GetComponent<AudioSource>();
    }

    public void PlayBombExplosionSound()
    {
        audioSource.PlayOneShot(bombExplosionSound);
    }

    public void PlayPlayerHitSound()
    {
        audioSource.PlayOneShot(playerHitSound);
    }
}


