#include<stdio.h>
#include<stdlib.h>
struct node
{
 int num;
 struct node *next;
}*rear,*front; 
void insert(int num)
{
     if(front==NULL)
       {
        front=(struct node*)malloc(sizeof(struct node));
        front->num=num;
        front->next=NULL;
        rear=front;
       }
     else
      {
        struct node *new=(struct node*)malloc(sizeof(struct node));   
        new->num=num;
        new->next=NULL;
        rear->next=new;
        rear=new;
      }
}
       
void delete()
{
 if(front==NULL)
   printf("\nQueue underflow!!!\n");
 else
   front=front->next;
}
 
int main()
{
  int i,n,a;
  do
{
printf(" Enter Option\n\t1. Enqueue\n\t2. Front\n\t3. Dequeue\n\t4. Exit \n ");
		
 scanf("%d",&n);
 if(n==1)
   {
     printf("\nEnter number ");
     scanf("%d",&a);
     insert(a);
   }  
 else if(n==2)
 {
	 if(front!=NULL)
		printf(" Front element : %d \n ",front->num);
	else printf(" Empty Queue!\n");
 }
 else if(n==3)
   delete();
 else if(n==4)
  break;
 }while(n!=4);
  return 0;
}


