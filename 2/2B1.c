#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
void bubble_asc(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];

				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nArray in ascending order: ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",arr[i]);
	}
}
int main(int argc,char *argv[]) //5 2 7 9 4
{
	int i,j=2,l,k;
	int n=argc-2;
	int a[n];
	char *args[n+1];
	args[0]=argv[1];
	for(i=1;i<=n;i++,j++)
	{
		args[i]=argv[j];
	}
	args[i]=(char*)0;//0 1 2 3 4 5 6
	//second 5 2 7 9 4 '0'
	for(l=0,i=1;i<=n;i++,l++)
	{
	a[l]=atoi(args[i]);
	}
	bubble_asc(a,n);
	for(l=0,i=1;i<=n;i++,l++)
	{
	sprintf(args[i],"%d",a[l]);
	}
	pid_t pid;
	
	pid=fork();
	if(pid==0)
	{
	printf("\nI am Child Process,my pid is %d \n",getpid());
	printf("I am Parent Process,my pid is %d \n",getppid());
	execve(argv[1],args,NULL);
	}
	else
	{
	k=wait(0);
	printf("\nI am Parent Process,my pid is %d \n",getpid());
	printf("I am Parent's Parent Process,my pid is %d\n\n",getppid());
	}
	return 0;
	}
