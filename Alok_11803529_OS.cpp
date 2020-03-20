/*Consider that a system has P resources of same type. These resources are shared by Q processes time to time. All processes 
request and release the resources one at a time. Generate a solution to demonstrate that, the system is in safe state when 
following conditions are satisfied. Conditions:
 1.  Maximum resource need of each process is between 1 and P.
 2. Summation of all maximum needs is less than P+Q*/
 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	system("COLOR 0A");
	int i,p,q,resource,max_need=0,count=0;
	printf("Enter Number of Resources available : \n");
	scanf("%d",&p);
	printf("Enter Number of Processes available : \n");
	scanf("%d",&q);
	resource=p;
	int process[q],finish[q],allot[q];
	for(i=0;i<q;i++)
	{
		printf("Enter number of resources required by Process %d\n",i+1);
		scanf("%d",&process[i]);
		finish[i]=0;
		allot[i]=0;
	}
	printf("\n\n");
	printf("*******************************************");
	printf("\n\n");
	printf("\tProcess \tResources\n");
	for(i=0;i<q;i++)
	{
		printf("\tP%d \t\t%d\n",i+1,process[i]);
		max_need=max_need+process[i];
		if(process[i]<1||process[i]>p)
		{
			count++;
		}
	}
	if(max_need<p+q&&count==0)
	{		
		printf("\n\n");
		printf("*******************************************");
		printf("\n\n");
		printf("  Both Condition : \n 1) Resource need of each process is between 1 and P \n 2) Max need is less than P+Q\n\nwhere Q is no. of process and P is no. of resource is satisfied.\nSo surely system is in safe state there is no chance of DeadLock.\n\n");
	}
	else
	{
		printf("Conditions are not satisfied so system is in unsafe state,there are chances of dead lock\n\n");
	}
		while(1)
		{
			count=0;
			for(i=0;i<q;i++)
			{
				if(finish[i]==0)
				{
					if(resource>0)
					{
					allot[i]=allot[i]+1;
					resource=resource-1;
					printf("Process %d + 1\n",i+1);
					}
					if(allot[i]==process[i])
					{
						printf("Process %d completed it execution\n",i+1);
						finish[i]=1;
						resource=resource+process[i];
						printf("Process %d - %d \n",i+1,process[i]);
					}
				}
			}
			for(i=0;i<q;i++)
			{
				if(finish[i]==1)
				count++;
			}
			if(count==q)
			break;
		}
			printf("\n\n");
			printf("*******************************************");
			printf("\n\n");
			printf("No Dead Lock");
}
