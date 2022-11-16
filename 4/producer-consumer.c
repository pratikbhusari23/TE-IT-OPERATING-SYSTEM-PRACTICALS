#include<stdio.h>
#include<sys/syscall.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void *producer();
void *consumer();

typedef struct {

	int buffer[20];
	sem_t full,empty;

}
shared;

shared sh;
int item;
int in=0 , out=0;
sem_t mutex;

int main() {
	
	pthread_t ptid1, ptid2, ctid1;
	sem_init(&sh.empty,0,20);
	sem_init(&sh.full,0,0);
	sem_init(&mutex,0,1);

	pthread_create(&ptid1 ,NULL ,producer ,NULL);
	pthread_create(&ptid2 ,NULL ,producer ,NULL);
	pthread_create(&ctid1 ,NULL ,consumer ,NULL);

	pthread_join(ptid1 , NULL);
	pthread_join(ptid2 , NULL);
	pthread_join(ctid1 , NULL);
	
	return 0;
}

void *producer() {

//	pthread_t item;
	int ptid;
	while(1)
	{
		item=in;
		sem_wait(&sh.empty);
		sem_wait(&mutex);

		sh.buffer[in++]=item;
		
		printf("PRODUCER Thread id = %ld and Producer Item = %d \n",pthread_self(),item);

		sem_post(&mutex);
		sem_post(&sh.full);
		sleep(3);	
	}



}
void *consumer() {

	int ctid;
	while(out<=19 && in<=19) {
		sem_wait(&sh.full);
		sem_wait(&mutex);

		item=sh.buffer[out++];
		printf("\tCONSUMER Thread id = %ld and Consumer Item = %d \n",syscall(SYS_gettid,ctid),item);
		
		sem_post(&mutex);
		sem_post(&sh.empty);
		sleep(1);
		}
}

