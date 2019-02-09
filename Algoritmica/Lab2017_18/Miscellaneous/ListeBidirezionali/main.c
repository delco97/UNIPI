#include <stdio.h>
#include <stdlib.h>

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

void printList(List l){
    LNode * c = l.h;
    printf("List: ");
    while(c != NULL){
        printf("%d ",c->k);
        c = c->next;
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

void deallocateList(List * l){
	LNode * cur = l->h;
	LNode * aux;
	while(cur != NULL){
		aux = cur;
		cur = cur->next;
		free(aux);
	}
	l->h = NULL;
}

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
    
    deallocateList(&q);
    printf("\nList after deallocation:\n");
    printList(q);
    return 0;
}
