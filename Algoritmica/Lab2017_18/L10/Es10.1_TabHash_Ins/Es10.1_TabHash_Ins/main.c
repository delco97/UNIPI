//
//  main.c
//  Es10.1_TabHash_Ins
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

void insertHashTab(HashTab * t,int k){
    int lenList = 0;
    int h = hash(k,t->slots,t->a,t->b,t->p);
    Node * aux = (Node *) malloc(sizeof(Node));
    aux->k = k;
    aux->next = NULL;
    if(t->tab[h] == NULL){ t->tab[h] = aux; lenList++;}
    else{//List not empty (CONFLICT), insert bottom
        t->confilcts++;
        lenList++; //At least one elmenet is inside the list
        Node * cur = t->tab[h];
        while (cur->next != NULL){
            lenList++;
            cur = cur->next;
        }
        //cur == NULL, lenList = number of elements inside the list
        cur->next = aux; //add new node
        lenList++;
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
        insertHashTab(t,k);
    }
}

int main(int argc, const char * argv[]) {
    HashTab tab;
    
    readHashTab(&tab);
    
    printf("%d\n%d",tab.max_list_size,tab.confilcts);
    
    return 0;
}
