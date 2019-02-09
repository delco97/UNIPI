#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const char * colors[] = {"W","G"};
typedef enum{
    W = 0, //White
    G = 1, //grey
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

int tailRemove(List * q){
    int u = -1;
    if(q->t != NULL){
        u = q->t->k;
        LNode * aux = q->t->prev;
        if(q->h == q->t) q->h = aux;
        free(q->t);
        q->t = aux;
        if(q->t != NULL) q->t->next = NULL;
        q->n--;
    }
    return u;
}
void DFS(Graph g,int s){
    int isBipartite = 1;
    int u;
    LNode * cur = NULL;
    List q; //Queue (FIFO)
    q.h = NULL;
    q.t = NULL;
    q.n = 0;
	 //Init source node
    g.a[s].c = G;
    g.a[s].prev = -1;
    g.a[s].d = 0;
    tailInsert(&q,s);
    while(q.n != 0 && isBipartite == 1){
        u = tailRemove(&q);
        //printf("%d ",u);
        cur = g.a[u].adj.h; //Head of the adjacency list of node u
        while(cur != NULL){//Loop adj nodes of u node
            if(g.a[cur->k].c == W){//White adj node
                g.a[cur->k].c = G;
                g.a[cur->k].d = g.a[u].d + 1;
                g.a[cur->k].prev = u;
                tailInsert(&q,cur->k);
            }
            cur = cur->next;
        }
    }
    deallocateList(&q);
}

int isLinked(Graph g){
	 //Init nodes for BFS
    for(int i=0;i<g.n;i++){
        g.a[i].c = W;
        g.a[i].d = INT_MAX;
        g.a[i].prev = -1;
    }
    
    for(int i=0;i<g.n;i++){
    	if(g.a[i].c == W){
    		if(i > 0) return 0; //g is not linked
    		else DFS(g,i);
    	}
    }
    return 1;
}

void printList(List l){
    LNode * c = l.h;
    printf("List: ");
    while(c != NULL){
        printf("%d ",c->k);
        c = c->next;
    }
}

void deallocateGraph(Graph * g){
	for(int i=0;i<g->n;i++){
		deallocateList(&(g->a[i].adj));
	}
	free(g->a);
	g->a = NULL;
}

int main(){
	Graph g;
	if( readGraph(&g) ){//Good graph read
		//printf("Graph read: \n");
		//printGraph(g);
		//printf("Is biartite? %s",isBipartite(g) == 1?"YES\n":"NO\n");
		printf("%d",isLinked(g));
		deallocateGraph(&g);
	}
	return 0;
}

