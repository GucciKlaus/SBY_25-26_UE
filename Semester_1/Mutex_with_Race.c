#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COUNTER_MAX 100

int counter = 50;

void *count_up(void *args)
{
    while (1)
    {
        if (counter != COUNTER_MAX)
            usleep(10);
            counter++;

        printf("Counter +: %d\n", counter);
        //usleep(1000);
        //Änderung um die Race Condition eher zu provozieren
        usleep(300);
    }
    return NULL;
}

void *count_down(void *args)
{
    while (1)
    {
        if (counter > 0)
            counter--;

        printf("Counter -: %d\n", counter);
        usleep(1000);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t tid, tid2, tid3;

    pthread_create(&tid, NULL, count_up, NULL);
    pthread_create(&tid2, NULL, count_down, NULL);
    pthread_create(&tid3, NULL, count_down, NULL);

    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    return 0;
}
