#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];
    pipe(fd1); // Pipe for first child
    pipe(fd2); // Pipe for second child

    pid_t pid1 = fork();

    if (pid1 == 0) { // First child process
        close(fd1[0]); // Close read end
        int num1;
        printf("Child 1: Enter a number: ");
        scanf("%d", &num1);
        write(fd1[1], &num1, sizeof(num1));
        close(fd1[1]);
        return 0;
    }
wait(NULL);    
    pid_t pid2 = fork();
    
    if (pid2 == 0) { // Second child process
        close(fd2[0]); // Close read end
        int num2;
        printf("Child 2: Enter a number: ");
        scanf("%d", &num2);
        write(fd2[1], &num2, sizeof(num2));
        close(fd2[1]);
        return 0;
    }
    
    // Parent process
    close(fd1[1]); // Close write end of first pipe
    close(fd2[1]); // Close write end of second pipe
    
    int num1, num2;
    read(fd1[0], &num1, sizeof(num1));
    read(fd2[0], &num2, sizeof(num2));
    
    close(fd1[0]);
    close(fd2[0]);
    
   
    wait(NULL); // Wait for second child
    
    printf("Parent: Sum = %d\n", num1 + num2);
    
    return 0;
}
