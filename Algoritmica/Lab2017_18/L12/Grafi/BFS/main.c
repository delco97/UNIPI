#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const char * colors[] = {"R","B","W","G"};
typedef enum{
    R = 0, //red
    B = 1, //blue
    W = 2, //white
    G = 3 //grey
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
    //BFS attributes
    Color c; //Color
    int d; //Discovery time
    int prev; //Previous nodes discovered
} GNode;

typedef struct _Graph{
    GNode * a; //Array with graph nodes
    int n;  //Nodes number
} Graph;

void deallocateList(List * l){
	LNode * cur = l->h;
	LNode * aux;
	while(cur != NULL){
		aux = cur;
		cur = cur->next;
		free(aux);
	}
	l->h = NULL;
	l->t = NULL;
}

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
        g.a[i].prev = -1;
    }
    
    *graph = g;
    return 1;
}

void printGraph(Graph g){
    LNode * cur = NULL;
    for (int i=0; i<g.n; i++) {
        printf("%d [%s] d: %d prev: %d): ",i,colors[g.a[i].c],g.a[i].d,g.a[i].prev);
        cur = g.a[i].adj.h; //Head of the adjacency list of node i
        while(cur != NULL){
            printf("%d -> ",cur->k);
            cur = cur->next;
        }
        printf("\n");
    }
}

void tailInsert(List * q,int k){
    LNode * aux = malloc(sizeof(LNode));
    aux->k = k;
    aux->next = NULL;
    aux->prev = q->t;
    if(q->t != NULL)q->t->next = aux;
    if(q->h == NULL) q->h = aux;
    q->t = aux;
    q->n++;
}

int headRemove(List * q){
    int u = -1;
    if(q->h != NULL){
        u = q->h->k;
        LNode * aux = q->h->next;
        if(q->h == q->t) q->t = aux;
        free(q->h);
        q->h = aux;
        q->n--;
    }
    return u;
}

void BFS(Graph g,int s){
    int u;
    LNode * cur = NULL;
    List q; //Queue (FIFO)
    q.h = NULL;
    q.t = NULL;
    q.n = 0;
    //Init nodes for BFS
    for(int i=0;i<g.n;i++){
        g.a[i].c = W;
        g.a[i].d = INT_MAX;
        g.a[i].prev = -1;
    }
    g.a[s].c = G;
    g.a[s].prev = -1;
    g.a[s].d = 0;
    tailInsert(&q,s);
    while(q.n != 0){
        u = headRemove(&q);
        printf("%d ",u);
        cur = g.a[u].adj.h; //Head of the adjacency list of node u
        while(cur != NULL){
            if(g.a[cur->k].c == W){
                g.a[cur->k].c = G;
                g.a[cur->k].d = g.a[u].d + 1;
                g.a[cur->k].prev = u;
                tailInsert(&q,cur->k);
            }
            cur = cur->next;
        }
        g.a[u].c = B;
    }
    
    deallocateList(&q);
    
}

void printList(List l){
    LNode * c = l.h;
    printf("List: ");
    while(c != NULL){
        printf("%d ",c->k);
        c = c->next;
    }
}
/*
//TEST FOR LIST FIFO
int main(){
    List q;q.h = NULL;q.t=NULL;q.n=0;
    int x;
    do{
        scanf("%d",&x);
        if(x != 0){
            if(x == -1) printf("Following elememnts removed: %d\n",headRemove(&q));
            else//Add element
                tailInsert(&q,x);
            printList(q);
        }
        printf("\n");
    }while(x != 0);
    return 0;
}
*/

 int main(){
	 Graph g;
	 int s;
	 if( readGraph(&g) ){//Good graph read
		 printf("Graph read: \n");
		 printGraph(g);
		 printf("\nSelect a source node for BFS: ");
		 scanf("%d",&s);
		 BFS(g,s);
	 }
 	return 0;
 }

