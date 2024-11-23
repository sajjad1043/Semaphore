#ifndef CONSUMER_H
#define CONSUMER_H

#include <pthread.h>
#include <semaphore.h>

void *consumer(void *arg);

#endif
