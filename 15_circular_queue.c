#include<stdio.h>
int a[100];
int maxsize=3;
int front=-1,rear=-1;
void enqueue(int n){
	if(front==(rear+1)%maxsize)
			printf(" Queue Overflow \n");
	else{	
		if(front==-1)
			front=0;
		rear=(rear+1)%maxsize;
		 a[rear]=n;
	}
}
void dequeue(){
	if( rear==front&&rear==-1)
		printf(" Queue Underflow\n");
	else if(front==rear){	
		printf(" Element %d Popped \n", a[ front]);
		front=rear=-1;
	}
	else{
		printf(" Element %d Popped \n", a[ front]);
		a[front]=0;
		( front)=(front+1)%maxsize;
	}
}
void display(){
	int i;
	if( rear==front&&rear==-1)
		printf(" Empty Queue\n");
	else{
		printf(" Queue : ");
		for(i=front;;i=(i+1)%maxsize)
			{
			printf("%d ", a[i]);
			if(i==rear)
				break;
			}

		printf("\n");
	}
}
	
int main(){
	int o;
	while(1){
		printf(" Enter Option\n\t1. Enqueue\n\t2. Display\n\t3. Dequeue\n\t4. Exit \n ");
		scanf("%d",&o);
		if(o==1){
			printf(" enter element : ");
			int temp;
			scanf("%d",&temp);
			enqueue(temp);
		}
		else if(o==2){
			display();
		}
		else if (o==3){
			dequeue();
		}
		
		else
		 break;
	}
}
