#include<stdio.h>
#include<stdlib.h>
struct Node {
	int a;
	struct Node *next;
};
struct Node *top;
void push(int data){
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->next=top;
	temp->a=data;
	top=temp;
}
void pop(){
	if(top==NULL)
		printf(" Stack Underflow\n");
	else{
		printf(" Element %d popped \n",top->a);
		top=top->next;
	}
}

int main(){
	int o;
	top=NULL;
	while(1){
		printf(" Enter Option\n\t1. Push\n\t2. Peek\n\t3. Pop\n\t4. Exit \n ");
		scanf("%d",&o);
		if(o==1){
			printf(" enter element : ");
			int temp;
			scanf("%d",&temp);
			push(temp);
		}
		else if(o==2){
			if(top!=NULL)
				printf(" Top element : %d \n ",top->a);
			else printf(" Empty stack!\n");
		}
		else if (o==3){
			pop();
		}
		
		else
		 break;
	}
}
