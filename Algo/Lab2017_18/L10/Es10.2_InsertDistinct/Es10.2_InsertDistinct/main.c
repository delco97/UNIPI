//
//  main.c
//  Es10.2_InsertDistinct
//
//  Created by Andrea Del Corto on 10/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define P 999149

typedef struct _Node{//Node of unidirectional list
    int k;
    struct _Node * next;
} Node;

typedef struct _HashTab{
    int slots;
    int usedSlots;
    int a; //Param for hash
    int b; //Param for hash
    int p; //
    int confilcts;
    int max_list_size;
    struct _Node ** tab;
} HashTab;

/*
 x: element to insert
 n: number of total solts
 a,b,p: param for hashing
 */
int hash(int x,int n,int a, int b, int p){
    return ((a*x + b) % p) % n;
}

void insertDistinctHashTab(HashTab * t,int k){
    int lenList = 0;
    int distinct = 1;
    int h = hash(k,t->slots,t->a,t->b,t->p);
    Node * aux = (Node *) malloc(sizeof(Node));
    aux->k = k;
    aux->next = NULL;
    if(t->tab[h] == NULL){ t->tab[h] = aux; lenList++; t->usedSlots++;}
    else{//List not empty, insert bottom
        lenList++;
        Node * cur = t->tab[h];
        if(cur->k == k)distinct = 0;
        while (cur->next != NULL){
            if(cur->k == k)distinct = 0;
            lenList++;
            cur = cur->next;
        }
        //cur == NULL, lenList = number of elements inside the list
        if(distinct == 1){
            cur->next = aux; //add new node ONLY if is distinct
            lenList++;
            t->usedSlots++;
            t->confilcts++;
        }
    }
    
    if(lenList > t->max_list_size) t->max_list_size = lenList; //new longest list found
}

void readHashTab(HashTab * t){
    int n,a,b;
    int k;
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    //Atributes set
    t->slots = 2*n;
    t->usedSlots = 0;
    t->a = a;
    t->b = b;
    t->p = P;
    t->confilcts = 0;
    t->max_list_size = 0;
    //Allocate space for array of pointer to Node
    t->tab = (Node **)malloc(t->slots * sizeof(Node *));
    for(int i=0;i < t->slots;i++)t->tab[i] = NULL; //Init solts
    for(int i=0;i < n;i++){//Read expected values
        scanf("%d",&k);
        insertDistinctHashTab(t,k);
    }
}

int main(int argc, const char * argv[]) {
    HashTab tab;
    
    readHashTab(&tab);
    
    printf("%d\n%d\n%d\n",tab.confilcts,tab.max_list_size,tab.usedSlots);
    
    return 0;
}
