#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void insert(struct node *link,int pos,int num){
	int i;
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=link;
	struct node *cur=link;
	for(i=0;i<pos-1&&(cur->next)!=link;i++)
		cur=cur->next;
 	if(cur->next!=link)
		temp->next=(cur->next);
	cur->next=temp;
}
void delete(struct node *link,int pos){
	int i;
	struct node *cur=link,*prev=link;
	for(i=0;i<pos&&cur!=link;i++){
		prev=cur;
		cur=cur->next;
		
		}
	if(cur==link)
		printf(" Invalid Position \n");
	else{
		prev->next=cur->next;
		printf(" Deleted \n");
	}
return;
}
void display(struct node *link){
	struct node *cur=link;
	cur=cur->next;
	while(cur!=link){
		printf("%d ",cur->data);
		cur=cur->next;
	}
}	


int main(){
	struct node *list=(struct node *) malloc(sizeof(struct node)),*temp;
	temp=list;
	temp->next=list;
	printf(" Options \n\t1. Insert\n\t2. Display\n\t3. Delete\n\t4. Exit \n ");
	int o,temp,pos;
	while(1){
		printf("\n\n Enter Option : ");
		scanf("%d",&o);
		if(o==1){
			printf(" enter element : ");
			scanf("%d",&temp);
			printf(" enter position : ");
			scanf("%d",&pos);
			insert(temp,pos,temp);		
		}
		else if(o==2){
			display(list);
		}
		else if (o==3){
		
			printf(" enter position : ");
			scanf("%d",&pos);
			delete(list,pos);
		}
		
		else
		 break;
	}
}
