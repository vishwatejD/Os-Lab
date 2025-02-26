#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Process {
    int pid;
    int bt; 
    int at; 
    int ct; 
    int wt; 
    int tat; 
    int priority;
};

void calculateTimes(struct Process processes[], int n) {
    int total_wt = 0, total_tat = 0;
    
   
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        total_wt += processes[i].wt;
        total_tat += processes[i].tat;
    }

    printf("\nPID\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].bt, processes[i].at, processes[i].ct, processes[i].wt, processes[i].tat);
    }
    
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}

void preemptiveSJF(struct Process processes[], int n) {
    int total_time = 0;
    int completed = 0;
    int shortest = 0;
    int min_bt = 9999;
    int is_completed[MAX] = {0};
    int last_completed_time = 0;

    printf("\nPreemptive SJF Scheduling:\n");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].at <= total_time && !is_completed[i] && processes[i].bt < min_bt) {
                min_bt = processes[i].bt;
                shortest = i;
            }
        }

        processes[shortest].bt--;
        if (processes[shortest].bt == 0) {
            is_completed[shortest] = 1;
            completed++;
            processes[shortest].ct = total_time + 1;
            min_bt = 9999;  
        }

        total_time++;
    }

    calculateTimes(processes, n);
}

void roundRobin(struct Process processes[], int n, int quantum) {
    int total_time = 0;
    int remaining_bt[MAX];
    int completed = 0;

    for (int i = 0; i < n; i++) {
        remaining_bt[i] = processes[i].bt;
    }

    printf("\nRound Robin Scheduling:\n");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                if (remaining_bt[i] > quantum) {
                    remaining_bt[i] -= quantum;
                    total_time += quantum;
                } else {
                    total_time += remaining_bt[i];
                    processes[i].ct = total_time;
                    remaining_bt[i] = 0;
                    completed++;
                }
            }
        }
    }

    calculateTimes(processes, n);
}

void priorityScheduling(struct Process processes[], int n) {
    int total_time = 0;
    int completed = 0;
    int highest_priority = 9999;
    int process_index = -1;
    int is_completed[MAX] = {0};

    printf("\nNon-Preemptive Priority Scheduling:\n");

    while (completed < n) {
        highest_priority = 9999;
        for (int i = 0; i < n; i++) {
            if (processes[i].at <= total_time && !is_completed[i] && processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                process_index = i;
            }
        }

        if (process_index != -1) {
            processes[process_index].ct = total_time + processes[process_index].bt;
            total_time += processes[process_index].bt;
            is_completed[process_index] = 1;
            completed++;
        }
    }

    calculateTimes(processes, n);

        printf("Arrival Time: ");
        scanf("%d", &processes[i].at);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Preemptive SJF Scheduling\n");
        printf("2. Round Robin Scheduling\n");
        printf("3. Non-preemptive Priority Scheduling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                preemptiveSJF(processes, n);
                break;
            case 2:
                printf("Enter Time Quantum: ");
                scanf("%d", &quantum);
                roundRobin(processes, n, quantum);
                break;
            case 3:
                priorityScheduling(processes, n);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
