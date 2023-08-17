#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int sharedValue = 0;

void* increment(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        pthread_mutex_lock(&mutex);
        sharedValue++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value: %d\n", sharedValue);

    pthread_mutex_destroy(&mutex);

    return 0;
}
