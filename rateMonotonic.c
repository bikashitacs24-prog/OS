#include <stdio.h>
#include <stdlib.h>

struct Task {
    int id;
    int period;          // Task period
    int execution_time;  // Task execution time
};

// Sort tasks by period (shorter period = higher priority)
void rateMonotonic(struct Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].period > tasks[j].period) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("\nExecution order (Rate-Monotonic Scheduling):\n");
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        printf("Task %d runs at time %d to %d (Period=%d)\n",
               tasks[i].id,
               current_time,
               current_time + tasks[i].execution_time,
               tasks[i].period);
        current_time += tasks[i].execution_time;
    }
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task tasks[n];
    for (int i = 0; i < n; i++) {
        printf("Enter period and execution time for Task %d: ", i + 1);
        scanf("%d %d", &tasks[i].period, &tasks[i].execution_time);
        tasks[i].id = i + 1;
    }

    rateMonotonic(tasks, n);
    return 0;
}
