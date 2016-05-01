#include<stdio.h>
#include<stdlib.h>
#define INF 9999
// linked list data type for adjacency list
typedef struct node 
{
  int vertex,weight;
 struct node *next;

}  List ;

// each node of graph

typedef struct {
   List *link;
   int key,parent,visited;
}  Node;

// graph data type

typedef struct {
   Node nodes[100]; // Array of nodes
   int n_v; // number  of vertices
   int n_e; // number of edges
}  Graph;

// function to create graph

void insert(List *link,int vertex,int weight){
// creating new node to insert
List *new=(List*) malloc(sizeof(List));
new->next= NULL ;
new ->  vertex = vertex ;
new -> weight = weight ;

// List won't be empty(since create function is used ) so iterating to end of list
List *cur=link;
while ( cur -> next != NULL )
  cur=cur->next;
// attaching new at end
cur -> next = new; 

}


Graph inputGraph()
{
    int i;
    Graph g;
    // filling first data in link, which is a sentinal element
    
    printf("Enter no of vertices \n");
    scanf("%d",&(g.n_v));

    for(i=0;i<g.n_v;i++)
    {
        g.nodes[i].link = (List*) malloc(sizeof(List));
        g.nodes[i].link -> next = NULL;
        g.nodes[i].link -> vertex = -1;
    }
    printf("Enter no of edges \n");
    scanf("%d",&(g.n_e));
    printf("Enter  %d edges each as from, to and weight ( 0 indexed ) : \n",g.n_e );
    for(i=0;i<g.n_e;i++)
    {
      int x,y,w;
      scanf("%d%d%d",&x,&y,&w);
      insert(g.nodes[x].link,y,w);
    }
    return g;
}

// Algo as in clrs
void prims(Graph *g){
  int i;
  for(i=0;i < g -> n_v ;i++)
    {
      g -> nodes[i] . key = INF;
      g -> nodes[i] . parent = -1;
      g -> nodes[i] . visited = 0;
      
    }
    g -> nodes[0] . key =0;
    int min,minnode;
    while(1)
    {
    min=INF;
      // extracting min
    for(i=0;i < g -> n_v ;i++)
    {
      if(g -> nodes[i].visited==0 && g -> nodes[i].key < min )
      {
        min= g -> nodes[i].key ;
        minnode=i;
      }
    }
    if(min==INF) // empty qqueue
      break;
    g -> nodes[minnode].visited=1;
    int u=minnode;
    List *cur= g -> nodes[u].link -> next; // first one is sentinel, so next
    while(cur != NULL)
    {
      if(g -> nodes[cur -> vertex].visited == 0 && ( cur -> weight ) < ( g -> nodes[cur -> vertex].key ))
      {
        g -> nodes[cur -> vertex].key = cur -> weight ;
        g -> nodes[cur -> vertex].parent = u;
      }
      cur=cur->next;
    }


  }
  for(i=0;i< (g->n_v);i++)
    printf("%3d %3d %3d\n",i,g -> nodes[i].key, g -> nodes[i].parent);

}

 int main(){
  int i,j;
  Graph g=inputGraph();
  prims(&g);

} 