#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *link;
};
struct queue{
	struct node *front;
	struct node *rear;
};
void initqueue(struct queue *q){
	q->front=q->rear=NULL;
}
void addq(struct queue *q,int item){
	struct node *temp;
	
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Queue is full!\n");
	}
	temp->data=item;
	temp->link=NULL;
	
	if(q->front==NULL){
		q->rear=q->front=temp;
		return;
	}
	q->rear->link=temp;
	q->rear=q->rear->link;
}
int delq(struct queue *q){
	struct node *temp;
	int item;
	
	if(q->front==NULL){
		printf("The Queue is empty!!");
		return NULL;
	}
	
	item=q->front->data;
	temp=q->front;
	q->front=q->front->link;
	
	free(temp);
	return item;
}
void delqueue(struct queue *q){
	struct node *temp;
	
	if(q->front==NULL){
		return;
	}
	while(q->front!=NULL){
		temp=q->front;
		q->front=q->front->link;
		free(temp);
	}
}
int main()
{
	struct queue q;
	int i;
	
	initqueue(&q);
	
	addq(&q,9);
	
}
