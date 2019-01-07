//
//  main.c
//  Es8.1_ListaMonodirezionale
//
//  Created by Andrea Del Corto on 07/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{//Nodo per lista unidirezionale
    int val;
    int cont_search;
    struct _Node * next;
    struct _Node * prev;
} Node;

void addBottom(Node ** h,Node ** t,int k){
    Node * aux = malloc(sizeof(Node));
    
    aux->val = k;
    aux->next = NULL;
    aux->cont_search = 0;
    if(*t == NULL){//Empty list
        *h = aux;
        *t = aux;
        aux->prev = NULL;
    }else{//At least one element in list
        (*t)->next = aux;
        aux->prev = *t;
        *t = aux;
    }
}

void readList(Node ** h,Node **t,int * n){
    Node * head = NULL;
    Node * tail = NULL;
    int val;
    
    scanf("%d",n);//Read number of elements
    for(int i = 0;i < *n;i ++){
        scanf("%d",&val);
        addBottom(&head,&tail,val);
    }
    *h = head;
    *t = tail;
}


void printList(Node * h){
    if(h != NULL){
        printf("%d\n",h->val);
        printList(h->next);
    }
}

void deleteList(Node ** h){
    if(*h != NULL){
        Node * p = *h;
        while(p != NULL){//Loop through all nodes
            p = p->next;
            free(p);
        }
        *h = NULL;
    }
}

void swap(Node * a,Node * b){
    Node tmp = *a;
    a->cont_search = b->cont_search;
    a->val = b->val;
    b->cont_search = tmp.cont_search;
    b->val = tmp.val;
}

int find(Node ** h,int k){//MTF = Move to front
    Node * cur = *h;
    Node * prev = NULL;
    int pos = 0;
    
    if(*h == NULL)return -1;
    else{//At least one element in list
        while(cur != NULL && cur->val != k){
            prev = cur;
            cur = cur->next;
            pos++;
        }
        if(cur == NULL)pos = -1; //k not found
        else{//k found in pos position => its counter must be increesed
            cur->cont_search++;
            while( cur != *h && cur->prev->cont_search < cur->cont_search ){
                swap(cur->prev,cur);
                cur = cur->prev;
            }
        }
    }
    
    return pos;
}


int main(int argc, const char * argv[]) {
    Node * input_h = NULL;
    Node * input_t = NULL;
    Node * res_h = NULL;
    Node * res_t = NULL;
    
    int target;
    int res = -1;
    int n;
    
    readList(&input_h,&input_t,&n);
    //printList(head);
    do{
        scanf("%d",&target);
        res = find(&input_h,target);
        addBottom(&res_h, &res_t, res);
        //printf("%d\n",res);
    }while(res!=-1);
    
    //printf("\nSearch results: \n");
    printList(res_h);
    
    //printf("\nList after search: \n"); //DEBUG
    //printList(input_h); //DEBUG
    
    deleteList(&input_h);
    deleteList(&res_h);
    return 0;
}
