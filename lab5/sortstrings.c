#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to perform bubble sort on strings
void bubbleSort(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string1> <string2> ...\n", argv[0]);
        return 1;
    }
    
    pid_t pid = fork();
    
    if (pid == 0) { // Child process
        bubbleSort(argv + 1, argc - 1);
        printf("Sorted strings (Child process):\n");
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
        return 0;
    }
    
    wait(NULL); // Parent waits for child to finish
    
    printf("Unsorted strings (Parent process):\n");
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    
    return 0;
}
