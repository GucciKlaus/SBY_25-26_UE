#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
// Mit wait könnte man auch auf prozesse warten

int main(int argc, char **argv, char **envp)
{
    printf("Hallo von prog1 PID=%d \n", getpid());
    int pid2 = getpid();
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Kind mit ID %d von ElternPID=%d\n", getpid(),pid2);
        char *argv2[] = {"irgendwas", 0};
        if (execve("prog2", argv2, envp) == -1)
        {
            printf("Error starting prog2\n");
            return -1;
        }
        //sleep(5);
       
    }
    else
    {
        //sleep(10);
        wait(0);
        printf("Eltern: Baba von prog1 mit PID=%d\n", getpid());
    }
    sleep(5);
    printf("BABA prog1 PID=%d \n", getpid());
    return 0;
}
