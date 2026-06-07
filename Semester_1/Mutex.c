#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COUNTER_MAX 100

int counter = 50;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *count_up(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&counter_mutex);

        if (counter < COUNTER_MAX)
            counter++;

        printf("Counter +: %d\n", counter);

        pthread_mutex_unlock(&counter_mutex);
        usleep(1000);
    }
    return NULL;
}

void *count_down(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&counter_mutex);

        if (counter > 0)
            counter--;

        printf("Counter -: %d\n", counter);

        pthread_mutex_unlock(&counter_mutex);
        usleep(1000);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t tid_up, tid_down1, tid_down2;

    pthread_create(&tid_up, NULL, count_up, NULL);
    pthread_create(&tid_down1, NULL, count_down, NULL);
    pthread_create(&tid_down2, NULL, count_down, NULL);

    pthread_join(tid_up, NULL);
    pthread_join(tid_down1, NULL);
    pthread_join(tid_down2, NULL);

    return 0;
}
