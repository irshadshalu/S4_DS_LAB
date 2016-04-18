#include<stdio.h>
#include<string.h>
#define FOR(i,a,b) for(i=a;i<=b;i++)
enum {WHITE,BLACK,GRAY};
// linked list data type for adjacency list
typedef struct node 
{
  int vertex,weight;
 struct node *next;

}  List ;

// each node of graph

typedef struct {
   List *link;
   int color,distance,parent;
}  Node;

// graph data type

typedef struct {
 // array of nodes
   node nodes[100];
  //  number  of vertices
   int n_v; 
  // number of edges
   int n_e;
}  Graph;

// function to create graph

Graph create(int no_of_vertices,int no_of_edges)
{
    Graph g;
    g.n_v = no_of_vertices;
    g.n_e = no_of_edges;
    // filling first data in link, which is a sentinal element
    FOR(i,0,g.n_v-1){
        g.nodes[i].link=(List*) malloc(sizeof(List));
        g.nodes[i].link -> next = NULL;
        g.nodes[i].link -> vertex = -1;
        }
    return g;
}

void insert(List *link,int vertex,int weight){

// creating new node to insert
List *temp=(List*) sizeof(List);
temp->next= NULL ;
temp ->  vertex = vertex ;
temp -> weight = weight ;

// List won't be empty(since create function is used ) so iterating to end of list
List *cur=link;
while ( cur -> next != NULL )
  cur=cur->next;
attaching temp at end
cur -> next= temp; 

}
 int main(){
  Graph g=createGraph(5,10);
  


} 