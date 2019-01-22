#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int k;
   struct _Node * next;
	struct _Node * prev;
} Node;

typedef struct _List{
	Node * h; //Head pointer
	Node * t; //Tail pointer
   int n; //Number of elements in list
} List;

typedef struct _Graph{
    List * a; //Adjacency list
    int n;  //Nodes number
} Graph;


void readList(List * list){
	List l;
   int k; 
	//Initialization
	l.h = NULL; 
	l.t = NULL;
	//Read number of arches/nodes expected
	scanf("%d",&l.n);// Number of arches to read	
	for(int i=0;i<l.n;i++){
		Node * aux;
		scanf("%d",&k);
		aux = (Node *) malloc(sizeof(Node));
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
	g.a = (List *) malloc(g.n * sizeof(List));
	//Read arches for each node
   for(int i=0;i<g.n;i++)
		readList(&(g.a[i]));

	*graph = g;
	return 1;
}

void printGraph(Graph g){
	Node * cur = NULL;
	for (int i=0; i<g.n; i++) {
		printf("%d: ",i);
      cur = g.a[i].h; 
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
