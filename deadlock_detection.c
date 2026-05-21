#include<stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    int alloc[10][10], req[10][10];
    int avail[10], finish[10] = {0};

    printf("Enter Allocation Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Request Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d", &req[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(i=0; i<m; i++)
    {
        scanf("%d", &avail[i]);
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(req[i][j] > avail[j])
                break;
        }

        if(j == m)
        {
            for(k=0; k<m; k++)
            {
                avail[k] += alloc[i][k];
            }

            finish[i] = 1;
        }
    }

    printf("Deadlocked Processes: ");

    for(i=0; i<n; i++)
    {
        if(finish[i] == 0)
        {
            printf("P%d ", i);
        }
    }

    return 0;
}