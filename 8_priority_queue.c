#include<stdio.h>
struct element{
	int priority;
	char name[1000];
};
void swap(struct element *x,struct element *y)
{
	struct element t=*x;
	*x=*y;
	*y=t;
}
void max_heapify(struct element a[],int i,int n)
{
	int l=2*i,r=2*i+1,largest=i;
	if(l<=n && a[l].priority>a[largest].priority)
		largest=l;
	if(r<=n && a[r].priority>a[largest].priority)
		largest=r;
	if(largest!=i)
	{
		swap(a+i,a+largest);
		max_heapify(a,largest,n);
	}
}
void build_max_heap(struct element a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
		max_heapify(a,i,n);
}
void insert_with_priority(struct element a[],int n,struct element temp)
{
	int i=n;
	a[n]=temp;
	while(i>1&&a[i/2].priority<a[i].priority)
	{
		swap(a+i/2,a+i);
		i=i/2;
	}
}

int main()
{
	int i,n;
	struct element a[1010];
	printf(" Enter initial Number of elements of queue : ");
	scanf("%d",&n);
	printf(" Enter n elements ( priority followed by name ) : \n");
	for(i=1;i<=n;i++)
	{
		scanf("%d %s",&(a[i].priority),a[i].name);
	}
	build_max_heap(a,n);
	printf(" Constructed Priority Queue : \n");
	for(i=1;i<=n;i++)
	{
		printf("%d %s \n",a[i].priority,a[i].name);
	}
	int option=0;
	while(1){
		printf(" Options :\n\t1. InsertWithPriority\n\t2. RemoveTop\n\t3. Display Queue\n\t4. Exit\n Enter Option : ");
		scanf("%d",&option);
		if(option==1)
		{
			n++;
			printf(" Enter priority and name : ");
			struct element temp;
			scanf("%d %s",&(temp.priority),temp.name);
			insert_with_priority(a,n,temp);
			//build_max_heap(a,n);
			printf(" Inserted to queue \n");	
		}
		else if(option==2)
		{
			
			printf(" Removed element : %d %s\n",a[1].priority,a[1].name);
			a[1].priority=-1;
			swap(a+1,a+n);
			n--;
			max_heapify(a,1,n);
		}
		else if(option==3)
		{
			printf(" Current Priority Queue : \n");
			for(i=1;i<=n;i++)
			{
				printf("%d %s \n",a[i].priority,a[i].name);
			}
		}
		else
			break;
		
	}
}
	
