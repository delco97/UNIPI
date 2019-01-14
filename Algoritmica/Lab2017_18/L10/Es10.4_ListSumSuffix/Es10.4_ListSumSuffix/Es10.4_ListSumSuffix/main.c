//
//  main.c
//  Es10.4_ListSumSuffix
//
//  Created by Andrea Del Corto on 14/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define P 999149

typedef struct _Node{//Node of unidirectional list
    int k;
    struct _Node * next;
} Node;

typedef struct _List{
    Node * h; //Head pointer
    Node * t; //tail pointer
} List;

void printList(List l){
    Node * cur = l.h;
    while(cur != NULL){
        printf("%d ",cur->k);
        cur = cur->next;
    }
}

void insertBottom(List * l,int k){
    Node * aux = malloc(sizeof(Node));
    aux->k = k;
    aux->next = NULL;
    
    if(l->t == NULL){//Empty list
        l->h = aux;
        l->t = aux;
    }else{//List with at least on element
        l->t->next = aux;
        l->t = aux;
    }
}

void readList(List * l){
    int n,k;
    scanf("%d",&n);
    
    for(int i=0;i < n;i++){//Read expected values
        scanf("%d",&k);
        insertBottom(l,k);
    }
}

int getSum(Node * n){
    if(n == NULL)return 0;
    else return n->k + getSum(n->next);
}

void setSuffixSum(List l){
    while(l.h != NULL){
        l.h->k = getSum(l.h->next);
        l.h = l.h->next;
    }
}

int main(int argc, const char * argv[]) {
    List l;
    
    l.h = NULL;
    l.t = NULL;
    
    readList(&l);
    printList(l);
    printf("\n");
    setSuffixSum(l);
    printList(l);
    printf("\n");
    return 0;
}

