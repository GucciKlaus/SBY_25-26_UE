#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
// Mit wait könnte man auch auf prozesse warten

int main(int argc, char **argv, char **envp)
{
    printf("Hallo von prog2 PID=%d \n", getpid());
    return 0;
}
