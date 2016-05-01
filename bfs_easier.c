#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct listnode 
{
	int vertex,weight;
	struct listnode *next;

};

struct graphnode
{
	int visited,distance,parent;
	struct listnode head;
}graph[100];
int v,e;

void bfs(int s);
void insert (int from,int to,int w);
int main()
{
	int i;
	printf(" Enter number of vertices : ");
	scanf("%d",&v);
	printf(" Enter number of edges : ");
	scanf("%d",&e);
	printf(" Enter edges in from , to  format :\n");
	for(i=0;i<e;i++)
	{
		int from, to;
		scanf("%d%d",&from,&to);
		insert(from,to,1);
	}
	printf(" Enter start node : ");
	int s;
	scanf("%d",&s);
	bfs(s);
		
	
	
}
int queue[100],front=0,rear=-1;
void enque(int data)
{
	rear++;
	queue[rear]=data;
}
int deque()
{
	front++;
	return queue[front-1];
}
int isempty()
{
	if(front>rear)
		return 1;
	else
		return 0;	
}
void bfs(int s)
{
	int i;
	printf(" | vertex | parent | distance |\n");
	for(i=1;i<=v;i++)
	{
		graph[i].visited=0;
		graph[i].distance=0;
		graph[i].parent=0;
	}
	graph[s].visited=1;
	graph[s].distance=0;
	graph[s].parent=0;
	enque(s);
	while(isempty()==0)
	{
		int u = deque();
		printf(" %d %d %d \n",u,graph[u].parent,graph[u].distance);
		struct listnode *cur= graph[u].head.next;
		while( cur != NULL )
		{
			if(graph[cur -> vertex].visited ==0 )
			{
				graph[cur -> vertex].visited =1;
				graph[cur -> vertex].distance = graph[u].distance +1;
				graph[cur -> vertex].parent =u;
				enque(cur->vertex);
			}	
			cur =cur->next;	
		}
	}
	

}
void insert(int from,int to,int w)
{
	struct listnode *new = (struct listnode *) malloc(sizeof(struct listnode));
	new -> vertex = to;
	new -> weight = w;
	new -> next = graph[from].head.next ;
	graph[from].head.next = new;
}

