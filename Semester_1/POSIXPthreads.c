#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int sum1 = 0;
int sum2 = 0;
int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void *runner(void *args)
{
    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
    {
        printf("Runner 1 calcs %d\n", sum1);
        sum1 += values[i];
    }
    return 0;
}
void *runner2(void *args)
{
    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
    {
        printf("Runner 2 calcs %d\n", sum2);
        sum2 += values[i];
    }
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    /*
     *Szenario während while Schleife Ergebnisse sind verschieden ...
     *
     */
    pthread_t tid;
    pthread_t tid2;
    pthread_t tid3;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_t attr2;
    pthread_attr_init(&attr2);
    pthread_create(&tid, &attr, runner, 0);
    pthread_create(&tid2, &attr2, runner2, 0);
    pthread_attr_t attr3;
    pthread_attr_init(&attr3);
    pthread_create(&tid3, &attr3, runner2, 0);
    printf("Waiting for THREAD\n");
    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);
    printf("sum = %d\n", sum1);
    printf("sum = %d\n", sum2);
    return 0;
}