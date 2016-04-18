#include<stdio.h>
struct Queue {
	int a[100];
	int maxsize;
	int front,rear;
}queue;
struct Queue create(int maxsize)
{
	struct Queue s;
	s.maxsize=maxsize;
	s.front=0;
	s.rear =-1;
	return s;
}
void enqueue(int n){
	if(queue.rear == queue.maxsize)
			printf(" Queue Overflow \n");
	else{	
		(queue.rear)++;
		queue.a[queue.rear]=n;
	}
}
void dequeue(){
	if(queue.rear<queue.front)
		printf(" Queue Underflow\n");
	else{
		printf(" Element %d Popped \n",queue.a[queue.front]);
		(queue.front)++;
	}
}
void display(){
	int i;
	if(queue.rear<queue.front)
		printf(" Empty Queue\n");
	else
		for(i=queue.front;i<=queue.rear;i++)
			printf("%d ",queue.a[i]);
	printf("\n");
}
	
int main(){
	queue=create(10);
	int o;
	while(1){
		printf(" Enter Option\n\t1. Enqueue\n\t2. Front\n\t3. Dequeue\n\t4. Exit \n ");
		scanf("%d",&o);
		if(o==1){
			printf(" enter element : ");
			int temp;
			scanf("%d",&temp);
			enqueue(temp);
		}
		else if(o==2){
			display();			
			if(queue.front!=-1)
				printf(" Front element : %d \n ",queue.a[queue.front]);
			else printf(" Empty Queue!\n");
		}
		else if (o==3){
			dequeue();
		}
		
		else
		 break;
	}
}
