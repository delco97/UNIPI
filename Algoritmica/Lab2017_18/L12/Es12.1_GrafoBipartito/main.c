#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


const char * colors[] = {"R","B","W","G"};
typedef enum{
	R = 0, //red 
	B = 1, //blue
	W = 2, //white
	G = 3  //grey
} Color;

typedef struct _LNode{
	int k;
   struct _LNode * next;
	struct _LNode * prev;
} LNode;

typedef struct _List{
	LNode * h; //Head pointer
	LNode * t; //Tail pointer
	int n; //Number of item in list
} List;

typedef struct _GNode{
	List adj; //Adjacency list
   Color c; //Color
   int id;
   int prev; //Id node visited before
	int d; //Discovery time
	int f; //End visit time
} GNode;

typedef struct _Graph{
    GNode * a; //Array with graph nodes
    int n;  //Nodes number
} Graph;


void readGNode(List * list){
	List l;
   int k; 
	//Initialization
	l.h = NULL; 
	l.t = NULL;
	//Read number of arches/nodes expected
	scanf("%d",&l.n);// Number of departing arches to read	
	for(int i=0;i<l.n;i++){
		LNode * aux;
		scanf("%d",&k);
		aux = (LNode *) malloc(sizeof(LNode));
		aux->k = k;
		aux->next = NULL;
		aux->prev = l.t;
		//Bottom insert in list
		if(l.t == NULL){//Empty list
			l.h = aux;
			l.t = aux;
		}else{//At least one element in list
			l.t->next = aux;
			l.t = aux;
		}
   }
	*list = l;
}

int readGraph(Graph * graph){
	Graph g;

	scanf("%d",&g.n); //Read number of nodes
	g.a = (GNode *) malloc(g.n * sizeof(GNode));
	//Read arches for each node
   for(int i=0;i<g.n;i++){
		readGNode(&(g.a[i].adj)); //Read adjacency list
		g.a[i].c = W;
		g.a[i].d = -1;
		g.a[i].f = -1;
		g.a[i].prev = -1;
		g.a[i].id = i;
	}

	*graph = g;
	return 1;
}

void printGraph(Graph g){
	LNode * cur = NULL;
	for (int i=0; i<g.n; i++) {
		printf("%d - [%s] [prev: %d] (%d/%d): ",g.a[i].id,colors[g.a[i].c],g.a[i].prev,g.a[i].d,g.a[i].f);
      cur = g.a[i].adj.h; //Head of the adjacency list of node i
		while(cur != NULL){
			printf("%d -> ",cur->k);
			cur = cur->next;
		}
		printf("\n");
	}
}

int DFSbipartite(Graph g,GNode u,int * time){
	LNode * cur = u.adj.h;
	Color prevCol;
	 
	(*time)++;
	u.d = *time;
	u.c = R;
	prevCol = R;
	while(cur != NULL){
		if(g.a[cur->k].c == W){
			g.a[cur->k].prev = u.id;
			DFSbipartite(g,g.a[cur->k],time);
		}
		cur=cur->next;
	}
	(*time)++;
	u.f = *time;
}

int isBipartite(Graph g){
	int time;
	int s;
	//rand() % (max_number + 1 - minimum_number) + minimum_number
	s = rand() % ((g.n-1) + 1 - 0) + 0; //[0,g.n)
	//Init nodes
	for (int i=0; i<g.n; i++) {
		g.a[i].c = W;
		g.a[i].d = -1;
		g.a[i].f = -1;
		g.a[i].prev = -1;
	}
	time = 0;
	for (int i=0; i<g.n; i++) 
		if(g.a[i].c == W && DFSbipartite(g,g.a[i],&time) == 0) return 0;;
	
	return 1;
}

int main(){
    Graph g;
    
    if( readGraph(&g) ){//Good graph read
		printf("Graph read: \n");
		printGraph(g);
		printf("Is bipartite?");
		printf("%d\n",isBipartite(g));
		
    }
        
    
    return 0;
}
