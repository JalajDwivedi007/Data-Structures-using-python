#include<stdio.h>
#define MAX 10
//Queue using arrays
void add(int *arr,int elem,int *pfront,int *prear){
	if(*prear==MAX-1){
		printf("The Queue is full!!\n");
		return;
	}
	(*prear)++;
	arr[*prear]=elem;
	
	if(*pfront==-1){
		*prear=0;
	}
}
int delq(int *arr,int *pfront,int *prear){
	if(*pfront==-1){
		printf("The Queue is empty!\n");
		return NULL;
	}
	int data=arr[*pfront];
	arr[*pfront]=0;
	if(*pfront==*prear){
		*pfront=*prear=-1;
	}
	else{
		(*pfront)++;
	}
	return data;
}
void print_queue(int *arr){
	for(int i=0;i<MAX-1;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[MAX];
	int front=-1;
	int end=-1;
	int i;
	
	add(arr,23,&front,&end);
	add(arr,2,&front,&end);
	add(arr,1,&front,&end);
	add(arr,3,&front,&end);
	add(arr,8,&front,&end);
	add(arr,7,&front,&end);
	
	print_queue(arr);
	
	i=delq(arr,&front,&end);
	if(i!=NULL){
		printf("The element deleted: %d\n",i);
	}
	i=delq(arr,&front,&end);
	if(i!=NULL){
		printf("The element deleted: %d\n",i);
	}
	
	print_queue(arr);
	
	add(arr,8,&front,&end);
	add(arr,10,&front,&end);
	
	print_queue(arr);
}
