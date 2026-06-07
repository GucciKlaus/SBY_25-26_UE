#include <semaphore.h>

sem_t sem;

int main(int argc, char **argv)
{
    /* Create the semaphore and initialize it to 1 */
    // Falscher code von ihm sem = sem_init(&sem, 0, 1);
    sem_init(&sem,0,1);

    /* acquire the semaphore */
    sem_wait(&sem);

    /* critical section */

    /* release the semaphore */
    sem_post(&sem);
}
