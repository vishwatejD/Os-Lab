#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1 = fork();
    if (pid1 == 0) { 
        printf("Child 1: Happy\n");
        return 0;
    }
    wait(NULL);

    pid_t pid2 = fork();
    if (pid2 == 0) { 
        printf("Child 2: New Year\n");
        return 0;
    }
    wait(NULL);

    printf("parent: 2025\n");
    return 0;
}