#include <stdio.h>
#include <string.h>

struct Process {
    int pid;
    int burst;
    int arrival;
    int completion;
    int turnaround;
    int waiting;
};

void printGanttChart(struct Process p[], int n, char queueName[]) {
    printf("\nGantt Chart for %s Queue:\n", queueName);
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", p[i].pid);
    }
    printf("|\n-------------------------------------------------\n");
    printf("%d", p[0].arrival);
    for (int i = 0; i < n; i++) {
        printf("   %d", p[i].completion);
    }
    printf("\n");
}

int main() {
    int sysCount, userCount;
    printf("Enter number of processes in System Queue: ");
    scanf("%d", &sysCount);
    printf("Enter number of processes in User Queue: ");
    scanf("%d", &userCount);

    struct Process sysQ[20], userQ[20];

    // Input System Queue processes
    for (int i = 0; i < sysCount; i++) {
        printf("\nEnter details for System Process %d\n", i + 1);
        sysQ[i].pid = i + 1;
        printf("Burst Time: ");
        scanf("%d", &sysQ[i].burst);
        printf("Arrival Time: ");
        scanf("%d", &sysQ[i].arrival);
    }

    // Input User Queue processes
    for (int i = 0; i < userCount; i++) {
        printf("\nEnter details for User Process %d\n", i + 1);
        userQ[i].pid = i + 1;
        printf("Burst Time: ");
        scanf("%d", &userQ[i].burst);
        printf("Arrival Time: ");
        scanf("%d", &userQ[i].arrival);
    }

    // Scheduling System Queue first (FCFS)
    int time = 0;
    for (int i = 0; i < sysCount; i++) {
        if (time < sysQ[i].arrival) time = sysQ[i].arrival;
        time += sysQ[i].burst;
        sysQ[i].completion = time;
        sysQ[i].turnaround = sysQ[i].completion - sysQ[i].arrival;
        sysQ[i].waiting = sysQ[i].turnaround - sysQ[i].burst;
    }

    // Then User Queue (FCFS)
    for (int i = 0; i < userCount; i++) {
        if (time < userQ[i].arrival) time = userQ[i].arrival;
        time += userQ[i].burst;
        userQ[i].completion = time;
        userQ[i].turnaround = userQ[i].completion - userQ[i].arrival;
        userQ[i].waiting = userQ[i].turnaround - userQ[i].burst;
    }

    // Print results
    printf("\nSystem Queue Results:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < sysCount; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               sysQ[i].pid, sysQ[i].arrival, sysQ[i].burst,
               sysQ[i].completion, sysQ[i].turnaround, sysQ[i].waiting);
    }

    printf("\nUser Queue Results:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < userCount; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               userQ[i].pid, userQ[i].arrival, userQ[i].burst,
               userQ[i].completion, userQ[i].turnaround, userQ[i].waiting);
    }

    // Print separate Gantt charts
    if (sysCount > 0) printGanttChart(sysQ, sysCount, "System");
    if (userCount > 0) printGanttChart(userQ, userCount, "User");

    return 0;
}
