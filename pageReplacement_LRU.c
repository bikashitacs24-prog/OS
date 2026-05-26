#include<stdio.h>

int main()
{
    int pages[20],frame[10],time[10];
    int n,f,i,j,pos,least,flag,pf=0,counter=0;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter pages:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
    {
        frame[i]=-1;
        time[i]=0;
    }

    for(i=0;i<n;i++)
    {
        flag=0;

        for(j=0;j<f;j++)
        {
            if(frame[j]==pages[i])
            {
                counter++;
                time[j]=counter;
                flag=1;
            }
        }

        if(flag==0)
        {
            least=time[0];
            pos=0;

            for(j=1;j<f;j++)
            {
                if(time[j]<least)
                {
                    least=time[j];
                    pos=j;
                }
            }

            counter++;
            frame[pos]=pages[i];
            time[pos]=counter;

            pf++;
        }
    }

    printf("Page Faults=%d",pf);

    return 0;
}