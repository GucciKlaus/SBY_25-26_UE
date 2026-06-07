#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/mman.h>

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    if (pipe(fd) != 0)
    {
        printf("ERROR\n");
        return -1;
    }
    // char mymemory[] = "Hallo\n";

    pid_t pid = fork();
    if (pid < 0)
    {
        printf("error\n");
        return -1;
    }
    if (pid == 0)
    {
        // sleep(5);
        char mymemory[] = "Das ist eine TestNachricht";
        write(fd[1], mymemory, sizeof(mymemory));
        printf("Kind(%d) : %s\n", getpid(), mymemory);
    }
    else
    {
        char emfpangsbuffer[20];
        wait(0);
        sleep(5);
        int len = read(fd[0], emfpangsbuffer, sizeof(emfpangsbuffer) - 1);
        if (len >= 0)
        {
            emfpangsbuffer[len] = 0;
            wait(0);
            printf("Eltern(%d) : %s\n", getpid(), emfpangsbuffer);
        }
        else
        {
            printf("ERROR\n");
        }
    }

    // printf("%s", message);
    // printf("%s", mymemory);
    return 0;
}