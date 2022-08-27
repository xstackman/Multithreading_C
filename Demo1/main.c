#include <stdio.h>
#include <pthread.h>
void *task1(){
	for(int x=0;x<100;x++){
		printf("[i] Task 1: Value: %i\n",x);
	}
}


void *task2(){
	for(int x=0;x<100;x++){
		printf("[i] Task 2: Value: %i\n",x);
	}
}

int main(){
	pthread_t task1_controller,task2_controller;
	pthread_create(&task1_controller,NULL,task1,NULL);
	pthread_create(&task2_controller,NULL,task2,NULL);
	pthread_join(task1_controller,NULL);
	pthread_join(task2_controller,NULL);
	printf("End main.\n");
	return 0;
}
