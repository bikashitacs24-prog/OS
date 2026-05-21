#include<stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    int a[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];

    printf("Enter Allocation Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d", &max[i][j]);
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
            need[i][j] = max[i][j] - a[i][j];
        }
    }

    int count = 0;

    while(count < n)
    {
        for(i=0; i<n; i++)
        {
            if(finish[i] == 0)
            {
                for(j=0; j<m; j++)
                {
                    if(need[i][j] > avail[j])
                        break;
                }

                if(j == m)
                {
                    for(k=0; k<m; k++)
                    {
                        avail[k] += a[i][k];
                    }

                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    printf("Safe Sequence: ");

    for(i=0; i<n; i++)
    {
        printf("P%d ", safe[i]);
    }

    return 0;
}