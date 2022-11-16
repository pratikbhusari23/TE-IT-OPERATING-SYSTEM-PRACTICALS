#include<stdio.h>

struct process{
	int max[10],allocate[10],need[10];
}p[10];

int n,m;
void input(int[]);
void display();
int isSafestate(int[],int[]);
int safetyalgorithm(int[],int[]);

int main(){
	int i;
	printf("\nEnter No of processes: ");
	scanf("%d",&n);
	printf("Enter no of resources: ");
	scanf("%d",&m);
	int available[m];
	int safesequence[n];
	printf("\n*****Enter details of process*****");
	input(available);
	display();
	if(isSafestate(available,safesequence))
	{
		printf("\n\tSYSTEM IS IN SAFE STATE...");
		printf("\nsafesequence is: ");
		for(i=0;i<n;i++)
		  printf("P%d -> ",safesequence[i]);
	}
	else
	    printf("\nSYSTEM IS IN UNSAFE STATE!!!");
	return 0;
}

void input (int available[m]){

	int i,j;
	for(i=0;i<n;i++){
		
		printf("\nEnter the details of process P%d: ",i);
		printf("\n\tEnter the allocates resources: ");
		for(j=0;j<m;j++)
		{
			scanf("%d",&p[i].allocate[j]);
		}
		printf("\tEnter the max resourcess: ");
		for(j=0;j<m;j++)
		{
			scanf("%d",&p[i].max[j]);
			p[i].need[j]=p[i].max[j]-p[i].allocate[j];
		}
	}
	printf("\nEnter the allvailable resources: ");
	for(j=0;j<m;j++)
	{
		scanf("%d",&available[j]);
	}
}
void display()
{
	int i,j;
	printf("\n\tPID\tALLOCATE\tMAX\t\tNEED\n");
	for(i=0;i<n;i++)
	{
		printf("\tP%d\t",i);
		for(j=0;j<m;j++)
		  printf("%d ",p[i].allocate[j]);
		printf("\t\t");
		for(j=0;j<m;j++)
		  printf("%d ",p[i].max[j]);
		printf("\t\t");
		for(j=0;j<m;j++)
		  printf("%d ",p[i].need[j]);
		printf("\n");
	}
}

int isSafestate(int available[m],int safesequence[n])
{
	if(safetyalgorithm(available,safesequence)==1)
	   return 1;
	return 0;
}

int safetyalgorithm(int available[m],int safesequence[n])
{
    int i,j;
    
    int work[m],finish[n];
    for(j=0;j<m;j++)
	    work[j]=available[j];
		
	for(i=0;i<n;i++)
	    finish[i]=0;
		
	int proceed=1,k=0;
	while(proceed)
	{
		proceed=0;
		for(i=0;i<n;i++)
		{
			int flag=1;
			if(finish[i]==0)
			{
				for(j=0;j<m;j++)
				{
					if(p[i].need[j]<=work[j])
					{
					    continue;
					}
					else
					{
						flag=0;
						break;
					}
				}
			if(flag==0)
			   continue;  
			   
			for(j=0;j<m;j++)
			{
				work[j]+=p[i].allocate[j];
			}
			finish[i]=1;
			safesequence[k++]=i;
			proceed=1;
			}
		}
	}
	

	for(i=0;i<n&&finish[i]==1;i++)
	    continue;
	if(i==n)
	    return 1;
    return 0;
}


