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

Node * readABR(int n){
    Node * tree = NULL;
    int k;
    
    for(int i=0;i<n;i++){//Read nodes
        scanf("%d",&k);
        tree = insertNode_Rec(tree,k);
    }
    
    return tree;
}

int isSameRoot(Node * a,Node * b,int k){
    if(a == NULL && b == NULL)return 1; //Both tree are empty
    if( (a == NULL && b != NULL) || (a != NULL && b == NULL) ) return 0; //One is empty the other is not
    //Both tree are not empty
    if(a->key == k && b->key == k)return 1; //Both nodes contain k
    if( (a->key == k && b->key != k) || (a->key != k && b->key == k) ) return 0; //Only one node contain k
    //Both nodes doesn't contain k
    if(a->key != b->key)return 0; //Both nodes must have the same key. If not the root is different
    //Continue search
    if(k < a->key)//Search in left tree
        return isSameRoot(a->left,b->left,k);
    else //Search in right tree
        return isSameRoot(a->right,b->right,k);
}

int main(int argc, const char * argv[]) {
    Node * t1 = NULL;
    Node * t2 = NULL;
    int n=0;
    int k;//target element to be searched in t1 and t2. I can ASSUME that k is contained in both tree
    
    scanf("%d",&n);
    scanf("%d",&k);
    
    t1 = readABR(n);
    t2 = readABR(n);
    
    printf("%d\n",isSameRoot(t1,t2,k));
    
    //printABR_Intermediate(tree);
    
    return 0;
}
