#include<stdio.h>

int main()
{
    int pages[20],frame[10];
    int n,f,i,j,k,pos,far,flag,pf=0;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter pages:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        frame[i]=-1;

    for(i=0;i<n;i++)
    {
        flag=0;

        for(j=0;j<f;j++)
        {
            if(frame[j]==pages[i])
                flag=1;
        }

        if(flag==0)
        {
            far=-1;
            pos=0;

            for(j=0;j<f;j++)
            {
                for(k=i+1;k<n;k++)
                {
                    if(frame[j]==pages[k])
                        break;
                }

                if(k==n)
                {
                    pos=j;
                    break;
                }

                if(k>far)
                {
                    far=k;
                    pos=j;
                }
            }

            frame[pos]=pages[i];
            pf++;
        }
    }

    printf("Page Faults=%d",pf);

    return 0;
}