#include <semaphore.h>
#include <fcntl.h>     // O_CREAT
#include <sys/stat.h>  // mode constants
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t *sem;

int main(int argc, char **argv)
{
    /* Create (or open) a named semaphore, initial value = 1 */
    sem = sem_open("/SBY1Sem", O_CREAT, 0644, 1);
    if (sem == SEM_FAILED)
    {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    /* acquire the semaphore */
    sem_wait(sem);

    /* critical section */
    printf("In critical section\n");
    sleep(1);

    /* release the semaphore */
    sem_post(sem);

    /* cleanup */
    sem_close(sem);
    sem_unlink("/SBY1Sem");

    return 0;
}
