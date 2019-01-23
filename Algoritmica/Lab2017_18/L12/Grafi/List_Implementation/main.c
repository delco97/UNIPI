#include <stdio.h>
#include <stdlib.h>

const char * colors[] = {"R","B","W"};
typedef enum{
	R = 0, //red 
	B = 1, //blue
	W = 2 //white
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
		g.a[i].d = 0;
		g.a[i].f = 0;
	}

	*graph = g;
	return 1;
}

void printGraph(Graph g){
	LNode * cur = NULL;
	for (int i=0; i<g.n; i++) {
		printf("%d [%s] (%d/%d): ",i,colors[g.a[i].c],g.a[i].d,g.a[i].f);
      cur = g.a[i].adj.h; //Head of the adjacency list of node i
		while(cur != NULL){
			printf("%d -> ",cur->k);
			cur = cur->next;
		}
		printf("\n");
	}
}


int main(){
    Graph g;
    
    if( readGraph(&g) ){//Good graph read
		printf("Graph read: \n");
		printGraph(g);
    }
        
    
    return 0;
}
