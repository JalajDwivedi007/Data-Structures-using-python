#include<stdio.h>
struct stack{
	int top;
	int arr[10]; //Max array of size 10
};
void init_stack(struct stack *s){
	s->top=-1;
}
void push(struct stack *s,int elem){
	if(s->top==9){
		printf("The Stack is full");
		return;
	}
	s->top++;
	s->arr[s->top]=elem;
}
int pop(struct stack *s){
	if(s->top==-1){
		printf("The Stack is empty");
		return NULL;
	}
	int elem=s->arr[s->top];
	s->top--;
	return elem;
}
void print_stack(struct stack *s){
	for(int i=0;i<10;i++){
		printf("%d |",s->arr[i]);
	}
	printf("\n");
}
int main(){
	struct stack p;
	init_stack(&p);
	push(&p,9);
	push(&p,8);
	push(&p,-1);
	int i=pop(&p);
	if(i!=NULL){
		printf("The element poped out: %d\n",i);
	}
	print_stack(&p);
	push(&p,18);
	print_stack(&p);
	i=pop(&p);
	if(i!=NULL){
		printf("The element poped out: %d\n",i);
	}
	print_stack(&p);
}
