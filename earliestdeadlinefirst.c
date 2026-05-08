#include <stdio.h>
#include <stdlib.h>

struct Task {
    int id;
    int deadline;
    int execution_time;
};

void earliestDeadlineFirst(struct Task tasks[], int n) {
    // Sort tasks by deadline
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].deadline > tasks[j].deadline) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("Execution order (Earliest Deadline First):\n");
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        printf("Task %d runs at time %d to %d\n",
               tasks[i].id,
               current_time,
               current_time + tasks[i].execution_time);
        current_time += tasks[i].execution_time;
    }
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task tasks[n];
    for (int i = 0; i < n; i++) {
        printf("Enter deadline and execution time for Task %d: ", i + 1);
        scanf("%d %d", &tasks[i].deadline, &tasks[i].execution_time);
        tasks[i].id = i + 1;
    }

    earliestDeadlineFirst(tasks, n);
    return 0;
}
