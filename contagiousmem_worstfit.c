#include<stdio.h>

int main()
{
    int b[10],p[10],i,j,nb,np,worst;

    printf("Enter number of blocks: ");
    scanf("%d",&nb);

    printf("Enter block sizes:\n");
    for(i=0;i<nb;i++)
        scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d",&np);

    printf("Enter process sizes:\n");
    for(i=0;i<np;i++)
        scanf("%d",&p[i]);

    for(i=0;i<np;i++)
    {
        worst=-1;

        for(j=0;j<nb;j++)
        {
            if(b[j]>=p[i])
            {
                if(worst==-1 || b[j]>b[worst])
                    worst=j;
            }
        }

        if(worst!=-1)
        {
            printf("Process %d allocated to block %d\n",i+1,worst+1);
            b[worst]-=p[i];
        }
        else
            printf("Process %d not allocated\n",i+1);
    }

    return 0;
}