#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *link;
};
void push(struct node **top,int elem){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	
	if(temp==NULL){
		printf("Stack is full!!");
	}
	temp->data=elem;
	temp->link=*top;
	*top=temp;	
}
int pop(struct node **top){
	struct node *temp;
	int elem;
	
	if(*top==NULL){
		printf("Stack is empty!");
		return NULL;
	}
	temp=*top;
	elem=temp->data;
	*top=(*top)->link;
	
	free(temp);
	return elem;
}
// The below print function does not work.
void printStack(struct node *top){
	while(top!=NULL){
		printf("%d ",top->data);
	}
	printf("\n");
}
void delStack(struct node **top){
	struct node *temp;
	if(*top==NULL){
		return;
	}
	while(*top!=NULL){
		temp=*top;
		*top=(*top)->link;
		free(temp);
	}
}
int main()
{
	struct node *s=NULL;
	int i;
	push(&s,8);
	push(&s,-2);
	push(&s,3);
//	printStack(s);
	i=pop(&s);
	if(i!=NULL){
		printf("Popped out: %d\n",i);
	}
	push(&s,10);
	i=pop(&s);
	if(i!=NULL){
		printf("Popped out: %d\n",i);
	}
//	printStack(s);
}
