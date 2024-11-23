#ifndef PRODUCER_H
#define PRODUCER_H

#include <pthread.h>
#include <semaphore.h>

void *producer(void *arg);

#endif
