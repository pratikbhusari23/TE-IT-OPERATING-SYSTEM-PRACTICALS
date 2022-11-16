#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
void bubble_dsc(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];

				arr[j+1]=temp;
			}
		}
	}
	printf("\nArray in dscending order: ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",arr[i]);
	}
	printf("\n");
}
int main(int argc,char *argv[])
	{
		int i,j=1,l;
		int n=argc-1;
		int a[n];
		char *args[n+1];
		printf("\nPid of the 2nd program is:%d\n",getpid()); 
		for(i=0;i<=n;i++,j++)
		{
			args[i]=argv[j];
		}
		args[i]=(char*)0;
		for(l=0,i=0;i<n;i++,l++)
		{
			a[l]=atoi(args[i]);
		}
		bubble_dsc(a,n);
		return 0;
	}
