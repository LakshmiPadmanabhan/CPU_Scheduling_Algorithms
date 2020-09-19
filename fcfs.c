#include <stdio.h>
void find(int n,int a[],int b[],int c[]){
	int i,s;
	int wt[n];
	float timewait=0;
	float timeta=(float)b[0];
	wt[0]=0;
	s=0;
	printf("Waiting Time of process P%d is %d",c[0],wt[0]);
	printf("\nTurn Around Time of process P%d is %d",c[0],b[0]);
	for(i=1;i<n;i++)
	{
	    s=s+b[i-1];
		wt[i]=s-a[i];
		timewait=timewait+wt[i];
		timeta=timeta+wt[i]+b[i];
		printf("\nWaiting Time of process P%d is %d",c[i],wt[i]);
		printf("\nTurn Around Time of process P%d is %d",c[i],wt[i]+b[i]);
	}
	printf("\nAverage Waiting Time:%f",timewait/n);
	printf("\nAverage Turnaround Time:%f",timeta/n);
}
void main()
{
	int t1,t2,t3,n,i,j;
	int arrival_time[50];int execution_time[50];int process_name[50];
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arrival_time[j]>arrival_time[j+1])
			{
				//sort arrival time array
				t1=arrival_time[j];
				arrival_time[j]=arrival_time[j+1];
				arrival_time[j+1]=t1;
				//sort execution time array
				t2=execution_time[j];
				execution_time[j]=execution_time[j+1];
				execution_time[j+1]=t2;
				//sort process names array
				t3=process_name[j];
				process_name[j]=process_name[j+1];
				process_name[j+1]=t3;
			}
		}	
	}
	find(n,arrival_time,execution_time,process_name);
}
