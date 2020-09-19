#include <stdio.h>
void find(int n,int a[],int b[],int c[]){
	int i,s;
	int wt[n];
	float timewait=0;
	float timeta=(float)b[i];
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
void swap(int i,int j,int arrival_time[],int execution_time[],int process_name[]){
	int t1,t2,t3;
	//sort arrival time array
	t1=arrival_time[i];
	arrival_time[i]=arrival_time[j];
	arrival_time[j]=t1;
	//sort execution time array
	t2=execution_time[i];
	execution_time[i]=execution_time[j];
	execution_time[j]=t2;
	//sort process names array
	t3=process_name[i];
	process_name[i]=process_name[j];
	process_name[j]=t3;
}
void main()
{
	int t1,t2,t3,n,i,j,k=0,min,pos;
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
	//sort process details on the basis of burst time or execution time and arrival time
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(execution_time[j]>execution_time[j+1])
			{
				swap(j,j+1,arrival_time,execution_time,process_name);
			}
		}	
	}
	
	find(n,arrival_time,execution_time,process_name);
}
  