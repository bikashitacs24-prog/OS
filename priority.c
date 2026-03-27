#include <stdio.h>

struct Process {
    int pid;        // Process ID
    int bt;         // Burst Time
    int priority;   // Priority
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input burst time and priority
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &proc[i].bt);
        printf("Enter priority for process P%d: ", i + 1);
        scanf("%d", &proc[i].priority);
    }

    // Sort processes by priority (smaller = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[j].priority < proc[i].priority) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    // Calculate waiting time
    proc[0].wt = 0;
    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].wt + proc[i - 1].bt;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }

    // Print results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].pid, proc[i].bt, proc[i].priority,
               proc[i].wt, proc[i].tat);
    }

    // Average times
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
