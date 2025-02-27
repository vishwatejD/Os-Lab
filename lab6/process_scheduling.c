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

// Function to calculate waiting and turnaround times
void calculateTimes(struct Process processes[], int n) {
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        total_wt += processes[i].wt;
        total_tat += processes[i].tat;
    }

    printf("\nPID\tBT\tAT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].bt, processes[i].at, processes[i].ct, processes[i].wt, processes[i].tat);
    }

    printf("\nAvg Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAvg Turnaround Time: %.2f\n", (float)total_tat / n);
}


void preemptiveSJF(struct Process processes[], int n) {
    int remaining_bt[MAX], total_time = 0, completed = 0;
    int shortest, min_bt;
    int is_completed[MAX] = {0};

    for (int i = 0; i < n; i++)
        remaining_bt[i] = processes[i].bt;

    printf("\nPreemptive SJF Scheduling:\n");

    while (completed < n) {
        shortest = -1;
        min_bt = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].at <= total_time && !is_completed[i] && remaining_bt[i] < min_bt) {
                min_bt = remaining_bt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            total_time++;
            continue;
        }

        remaining_bt[shortest]--;

        if (remaining_bt[shortest] == 0) {
            processes[shortest].ct = total_time + 1;
            is_completed[shortest] = 1;
            completed++;
        }

        total_time++;
    }

    calculateTimes(processes, n);
}


void roundRobin(struct Process processes[], int n, int quantum) {
    int total_time = 0, completed = 0;
    int remaining_bt[MAX];

    for (int i = 0; i < n; i++)
        remaining_bt[i] = processes[i].bt;

    printf("\nRound Robin Scheduling:\n");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                if (remaining_bt[i] > quantum) {
                    total_time += quantum;
                    remaining_bt[i] -= quantum;
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
    int total_time = 0, completed = 0;
    int is_completed[MAX] = {0};

    printf("\nNon-Preemptive Priority Scheduling:\n");

    while (completed < n) {
        int highest_priority = 9999;
        int process_index = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].at <= total_time && !is_completed[i] && processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                process_index = i;
            }
        }

        if (process_index == -1) {
            total_time++;
            continue;
        }

        processes[process_index].ct = total_time + processes[process_index].bt;
        total_time += processes[process_index].bt;
        is_completed[process_index] = 1;
        completed++;
    }

    calculateTimes(processes, n);
}


int main() {
    int n, choice, quantum;
    struct Process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details (PID, AT, BT, Priority):\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].at);
        printf("Burst Time: ");
        scanf("%d", &processes[i].bt);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Preemptive SJF Scheduling\n");
        printf("2. Round Robin Scheduling\n");
        printf("3. Non-Preemptive Priority Scheduling\n");
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
