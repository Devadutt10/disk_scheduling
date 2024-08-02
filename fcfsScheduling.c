#include<stdio.h>
#include<stdlib.h>

void main(){

	int num_request;
	printf("Enter the number of requests:");
	scanf("%d",&num_request);
	
	int request[num_request],initial,total_head_mov=0;
	printf("Start entering the requests...\n");
	for(int i=0;i<num_request;i++){
		scanf("%d",&request[i]);
	}
	
	printf("Enter the initial position of the head:");
	scanf("%d",&initial);
	
	for(int i=0;i<num_request;i++){
		total_head_mov = total_head_mov + abs(initial - request[i]);
		initial = request[i];
	}
	
	printf("Total head movements in FCFS disk scheduling fashion is: %d\n",total_head_mov);



}
