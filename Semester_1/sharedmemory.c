#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/mman.h>

int main(int argc, char **argv, char **envp)
{
    char message[] = "Das ist eine Nachricht\n";
    // char *mymemory = malloc(sizeof(message));
    char *mymemory = mmap(NULL, sizeof(message), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    memcpy(mymemory, message, sizeof(message));

    pid_t pid = fork();
    if (pid < 0)
    {
        printf("error\n");
        return -1;
    }
    if (pid == 0)
    {
        // sleep(2);
        mymemory[1] = 'e';
        printf("Kind(%d) : %s\n", getpid(), mymemory);
    }
    else
    {
        // wait(0);
        mymemory[2] = 'x';
        printf("Eltern(%d) : %s\n", getpid(), mymemory);
    }

    // printf("%s", message);
    // printf("%s", mymemory);
    return 0;
}