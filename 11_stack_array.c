#include<stdio.h>
struct Stack {
	int a[100];
	int maxsize;
	int top;
}stack;
struct Stack create(int maxsize)
{
	struct Stack s;
	s.maxsize=maxsize;
	s.top=-1;
	return s;
}
void push(int n){
	if(stack.top == stack.maxsize)
			printf(" StackOverflow \n");
	else{	
		(stack.top)++;
		stack.a[stack.top]=n;
	}
}
void pop(){
	if(stack.top==-1)
		printf(" Stack Underflow\n");
	else{
	
		printf(" Element %d Popped \n",stack.a[stack.top]);
		(stack.top)--;
	}
}
	
int main(){
	stack=create(10);
	printf(" Options\n\t1. Push\n\t2. Peek\n\t3. Pop\n\t4. Exit \n ");
	int o;
	while(1){
		printf("\n Enter Option : ");
		scanf("%d",&o);
		if(o==1){
			printf(" enter element : ");
			int temp;
			scanf("%d",&temp);
			push(temp);
		}
		else if(o==2){
			if(stack.top!=-1)
				printf(" Top element : %d \n ",stack.a[stack.top]);
			else printf(" Empty stack!\n");
		}
		else if (o==3){
			pop();
		}
		
		else
		 break;
	}
}
