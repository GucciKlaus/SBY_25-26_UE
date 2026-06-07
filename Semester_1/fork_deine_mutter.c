#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    printf("Hallo von prog1 mit PID =%d\n", getpid());
    execve("prog2", 0, 0);
    pid_t pid = fork();
    printf("BABA von prog1 mit PID=%d", getpid());
}