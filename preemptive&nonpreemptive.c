#include <stdio.h>

struct Process {
    int pid, at, bt, ct, tat, wt, rt, rem;
};

int main() {
    int n, choice, tq;
    printf("Choose Scheduling Algorithm:\n");
    printf("1. FCFS (Non-Preemptive)\n");
    printf("2. Round Robin (Preemptive)\n");
    scanf("%d", &choice);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for(int i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rem = p[i].bt;
        p[i].rt = -1;
    }

    float avg_tat=0, avg_wt=0, avg_rt=0;

    switch(choice) {
        case 1: { // FCFS
            int time=0;
            printf("\nGantt Chart:\n");
            for(int i=0; i<n; i++) {
                if(time < p[i].at) time = p[i].at;
                printf("| P%d (%d-%d) ", p[i].pid, time, time+p[i].bt);
                p[i].ct = time + p[i].bt;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                p[i].rt = p[i].wt; // same as WT in FCFS
                avg_tat += p[i].tat;
                avg_wt += p[i].wt;
                avg_rt += p[i].rt;
                time = p[i].ct;
            }
            printf("|\n");
            break;
        }

        case 2: { // Round Robin
            printf("Enter Time Quantum: ");
            scanf("%d", &tq);

            int time=0, completed=0;
            printf("\nGantt Chart:\n");
            while(completed < n) {
                int done=0;
                for(int i=0; i<n; i++) {
                    if(p[i].at <= time && p[i].rem > 0) {
                        done=1;
                        if(p[i].rt == -1) p[i].rt = time - p[i].at;
                        if(p[i].rem > tq) {
                            printf("| P%d (%d-%d) ", p[i].pid, time, time+tq);
                            time += tq;
                            p[i].rem -= tq;
                        } else {
                            printf("| P%d (%d-%d) ", p[i].pid, time, time+p[i].rem);
                            time += p[i].rem;
                            p[i].rem = 0;
                            p[i].ct = time;
                            p[i].tat = p[i].ct - p[i].at;
                            p[i].wt = p[i].tat - p[i].bt;
                            avg_tat += p[i].tat;
                            avg_wt += p[i].wt;
                            avg_rt += p[i].rt;
                            completed++;
                        }
                    }
                }
                if(!done) time++;
            }
            printf("|\n");
            break;
        }

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct,
               p[i].tat, p[i].wt, p[i].rt);
    }

    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT  = %.2f", avg_wt/n);
    printf("\nAverage RT  = %.2f\n", avg_rt/n);

    return 0;
}
