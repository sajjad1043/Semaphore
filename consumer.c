#include <stdio.h>
#include <unistd.h>
#include "consumer.h"

extern int buffer[];
extern int count;
extern sem_t empty_slots;
extern sem_t full_slots;
extern pthread_mutex_t mutex;

void *consumer(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&full_slots);
        pthread_mutex_lock(&mutex);

        int item = buffer[count - 1];
         printf("Consumed: %d\n", item);
        count--;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty_slots);

        sleep(10);
    }
    return NULL;
}
