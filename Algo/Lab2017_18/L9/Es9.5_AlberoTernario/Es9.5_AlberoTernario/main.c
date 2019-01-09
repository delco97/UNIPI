
#include <stdlib.h>
#include <stdio.h>

typedef struct _Node{
    int key;
    struct _Node * c1;//child 1
    struct _Node * c2;//child 2
    struct _Node * c3;//child 3
} Node;

Node * insertNode_Iter(Node * t,int k){
    Node * aux;
    Node * cur;
    Node * prev;
    //Create new leaf to insert
    aux = (Node *)malloc(sizeof(Node));
    aux->key = k;
    aux->c1 = NULL;
    aux->c2 = NULL;
    aux->c3 = NULL;
    if(t == NULL) return aux; //tree empty
    //Find insert position
    cur = t;
    prev =  t;
    while(cur != NULL){
        prev = cur;
        if(k < cur->key)cur = cur->c1;
        else{
            if((cur->key) % k == 0)cur = cur->c2;
            else cur = cur->c3;
        }
    }
    //cur != NULL, prev point to cur's father (if cur was an existing node)
    //INSERT
    if(k < prev->key)prev->c1 = aux;
    else{
        if((prev->key) % k == 0)prev->c2 = aux;
        else prev->c3 = aux;
    }
    return t;
}

Node * insertNode(Node * t,int k){
    Node * aux = (Node *)malloc(sizeof(Node)); //Create new leaf to insert
    aux->key = k;
    aux->c1 = NULL;
    aux->c2 = NULL;
    aux->c3 = NULL;
    if(t == NULL) return aux;
    //Tree not empty
    if(k < t->key)//insert aux in c1 child
        t->c1 = insertNode(t->c1,k);
    else{
        if(k % (t->key) == 0) //insert aux in c2 child
            t->c2 = insertNode(t->c2,k);
        else //insert aux in c3 child
            t->c3 = insertNode(t->c3,k);
    }
    return t;
}

int completeNodes(Node * t){
    if(t == NULL)return 0;
    if(t->c1 != NULL && t->c2 != NULL && t->c3 != NULL) //is a node with three childreen
        return 1 + completeNodes(t->c1) + completeNodes(t->c2) + completeNodes(t->c3);
    //One or more child are not empty
    if(t->c1 == NULL && t->c2 == NULL && t->c3 == NULL)//all childreen are empty => is a leaf
        return 0;
    //A least one child must be NO empty now
    return completeNodes(t->c1) + completeNodes(t->c2) + completeNodes(t->c3);
}

Node * readNodes(int *dim){
    Node * t = NULL;
    int n,aux;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){//Insert nodes
        scanf("%d",&aux);
        t = insertNode(t,aux);
    }
    *dim = n;
    return t;
}


int main(){
    Node * t;
    int n;
    
    t = readNodes(&n);
    printf("%d\n",completeNodes(t));
    
    return 0;
}
