#include <stdio.h>
void main()
{
	int t1,t2,t3,n,i,j,ts,t=0,min,pos;
    int flag=1;
    float timewait=0;
    float timeta=0;
	int arrival_time[50];int execution_time[50];int process_name[50],remaining_time[50],waiting_time[50] ;
	printf("Enter number of processes");
	scanf("%d",&n);
	//P0 to Pn-1 are the processes
	printf("Enter arrival time of all processes");
	for(i=0;i<n;i++)
	{	
		scanf("%d",&arrival_time[i]);
		process_name[i]=i;
	}
	printf("Enter burst time of all processes");
	for( i=0;i<n;i++)
	{	
		scanf("%d",&execution_time[i]);
	}
    printf("Enter time slice");
	scanf("%d",&ts);

    for ( i = 0; i < n; i++)
    {
        remaining_time[i]=execution_time[i];
    
    }

    while (1)
    { 
        flag=1;
        for ( i = 0; i < n; i++)
        {
            /* code */
            if (remaining_time[i]>0)
            {
                /* code */
				flag=0;
                if (remaining_time[i]>ts)
                {
                    /* code */
                    remaining_time[i]-=ts;//3
                    t+=ts;//2
                }
                else
                {
                    t+=remaining_time[i];
                    waiting_time[i]=t-execution_time[i]-arrival_time[i];
                    remaining_time[i]=0;
                    timewait=waiting_time[i]+timewait;
                }
            } 
        }
        if(flag==1)
        {
			break;
         }
    }
	for ( i = 0; i < n; i++)
    {
        printf("Waiting Time of process P%d is %d\n",process_name[i],waiting_time[i]);
    }
	for ( i = 0; i < n; i++)
    {
        timeta=timeta+(waiting_time[i]+execution_time[i]);
        printf("TurnAround Time of process P%d is %d\n",process_name[i],waiting_time[i]+execution_time[i]);
    }
    printf("\nAverage Waiting Time:%f",timewait/n);
	printf("\nAverage turnaround Time:%f",timeta/n);
}