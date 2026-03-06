#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};
int main() {
    int n, i, j;
    float avg_wt = 0, avg_tat = 0, avg_rt = 0;
    struct process p[10], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    // Sorting by Arrival Time (Bubble Sort)
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(p[j].at > p[j+1].at) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    int time = 0;

    for(i = 0; i < n; i++) {
        if(time < p[i].at)
            time = p[i].at;

        p[i].rt = time - p[i].at;  // Response Time
        time += p[i].bt;
        p[i].ct = time;

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
        avg_rt += p[i].rt;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    printf("\nAverage Response Time = %.2f\n", avg_rt/n);

    return 0;
}
