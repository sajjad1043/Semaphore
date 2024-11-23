#include <stdio.h>
#include <unistd.h>
#include "producer.h"

extern int buffer[];
extern int count;
extern sem_t empty_slots;
extern sem_t full_slots;
extern pthread_mutex_t mutex;

void *producer(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&empty_slots);
        pthread_mutex_lock(&mutex);

        buffer[count] = i;
        printf("Produced: %d\n", i);
        count++;

        pthread_mutex_unlock(&mutex);
        sem_post(&full_slots);

        sleep(10);
    }
    return NULL;
}
