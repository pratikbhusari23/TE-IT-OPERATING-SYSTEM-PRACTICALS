
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>

#define SZ 4096

int main(){
	
	int shm_id;
	int *shm_ptr;
	int data,ret_val;
	int read_data;
	int pid;
	
	shm_id=shmget( IPC_PRIVATE , SZ , IPC_CREAT | 0666 );
	if(shm_id<0){
		printf("\n ERROR at adressing ,memory\n");
	}
	else{
		printf("Shared memo is created\n");
		printf("shared memory id  %d\n",shm_id);
		
		shm_ptr=(int*) shmat(shm_id,NULL,0);
			if((int) shm_ptr!=-1){
				printf("\nSHARED MEMORY IS ATTACHED TO \t%d\n",shm_ptr);
			}
			printf("\nENTER THE DATA\n");
			scanf("%d",&data);
			*shm_ptr = data;
		
			pid=fork();
			if(pid==0){
			
				if((int) shm_ptr!=-1){
				printf("\nSHARED MEMORY IS ATTACHED TO \t%d\n",shm_ptr);
				read_data=*shm_ptr;
				printf("data from shared memory \t %d",*shm_ptr);
			}

		}
		ret_val =shmdt((void *)shm_ptr);
		if(ret_val==0){
				printf("\n shared memory is sucessfully detached\n");
			}
			else{
				printf("shmdt srror");
			}
	}
return 0;
}
