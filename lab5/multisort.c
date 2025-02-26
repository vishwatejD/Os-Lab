#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Bubble Sort Function
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

// Selection Sort Function
void selectionSort(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIdx]) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            char *temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); // Consume newline

    char *arr[n];
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
        fgets(arr[i], 100, stdin);
        arr[i][strcspn(arr[i], "\n")] = 0; // Remove newline
    }
    
    pid_t pid1 = fork();
    if (pid1 == 0) { // Child 1 (Bubble Sort)
        bubbleSort(arr, n);
        printf("\nChild 1 (Bubble Sort) Output:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", arr[i]);
        }
        return 0;
    }
    
    pid_t pid2 = fork();
    if (pid2 == 0) { // Child 2 (Selection Sort)
        selectionSort(arr, n);
        printf("\nChild 2 (Selection Sort) Output:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", arr[i]);
        }
        return 0;
    }
    
    // Parent waits for any one child to terminate
    wait(NULL);
    printf("\nParent: One child has terminated. Parent exiting.\n");
    
    return 0;
}
