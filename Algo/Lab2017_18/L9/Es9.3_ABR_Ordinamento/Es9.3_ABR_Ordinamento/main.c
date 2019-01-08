//
//  main.c
//  Es9.1_ABR_Ricerca
//
//  Created by Andrea Del Corto on 07/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{//Tree node
    int key;
    struct _node * left;
    struct _node * right;
} Node;

void printABR_Intermediate(Node * t){
    if(t != NULL){
        printABR_Intermediate(t->left);
        printf("%d\n",t->key);
        printABR_Intermediate(t->right);
    }
}

Node * insertNode_Iter(Node * t,int k){
    Node * aux = (Node *)malloc(sizeof(Node));
    aux->key = k;
    aux->left = NULL;
    aux->right = NULL;
    if(t == NULL)return aux;
    //Tree not empty
    Node * cur = t;
    Node * prev = t;
    while(cur != NULL){
        prev = cur;
        if(k < cur->key)//Insert in left tree
            cur = cur->left;
        else //Insert in right tree
            cur = cur->right;
    }
    //cur == NULL, prev == cur's father (if cur were a node)
    if(k < prev->key)//Insert in left tree
        prev->left = aux;
    else //Insert in right tree
        prev->right = aux;
    return t;
}

Node * insertNode_Rec(Node * t,int k){
    Node * aux = (Node *)malloc(sizeof(Node));
    aux->key = k;
    aux->left = NULL;
    aux->right = NULL;
    
    if(t == NULL)return aux;
    //Tree not empty
    if(k < t->key)t->left = insertNode_Rec(t->left,k);
    else t->right = insertNode_Rec(t->right,k);
    return t;
}

Node * readABR(int * dim){
    Node * tree = NULL;
    int n=0;
    int k;
    
    scanf("%d",&n);//Read number of nodes
    
    for(int i=0;i<n;i++){//Read nodes
        scanf("%d",&k);
        tree = insertNode_Rec(tree,k);
    }
    
    *dim = n;
    return tree;
}

int max(int a,int b){return (a>b)?a:b;}

int height(Node * t){
    if(t == NULL)return 0;
    return 1 + max(height(t->left),height(t->right));
}

int main(int argc, const char * argv[]) {
    Node * tree = NULL;
    int n=0;
    
    tree = readABR(&n);
    printABR_Intermediate(tree);
    
    return 0;
}
