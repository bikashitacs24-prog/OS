#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], weight[n];
    float share[n], totalWeight = 0;

    for(i = 0; i < n; i++) {
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &burst[i]);
        printf("Enter weight of P%d: ", i+1);
        scanf("%d", &weight[i]);
        totalWeight += weight[i];
    }

    printf("\nProportional Scheduling Result:\n");
    for(i = 0; i < n; i++) {
        share[i] = (weight[i] / totalWeight) * burst[i];
        printf("P%d gets %.2f units of CPU time\n", i+1, share[i]);
    }

    return 0;
}
