#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int w[10], p[10];
    int k[10][10];
    int n,m,i,j;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter profits:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);

    printf("Enter weights:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d",&m);

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                k[i][j]=0;

            else if(w[i]<=j)
                k[i][j]=max(
                    p[i]+k[i-1][j-w[i]],
                    k[i-1][j]
                );

            else
                k[i][j]=k[i-1][j];
        }
    }

    printf("Maximum Profit = %d",k[n][m]);

    return 0;
}
