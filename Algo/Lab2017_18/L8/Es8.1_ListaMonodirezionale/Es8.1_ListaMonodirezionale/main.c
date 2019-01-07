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
    struct _Node * next;
} Node;

void addBottom(Node ** h,int k){
    Node * curs = NULL;
    Node * aux = malloc(sizeof(Node));
    
    aux->val = k;
    aux->next = NULL;
    if(*h == NULL){//Empty list
        *h = aux;
    }else{//At least one element in list
        //Loop list
        curs = *h;
        while(curs->next != NULL)curs=curs->next; //Loop untill the last elment (curs->next == NULL) is reached
        curs->next = aux;
    }
}

Node * readList(int * n){
    Node * head = NULL;
    int val;
    
    scanf("%d",n);//Read number of elements
    for(int i = 0;i < *n;i ++){
        scanf("%d",&val);
        addBottom(&head,val);
    }
    return head;
}

void printList(Node * h){
    if(h != NULL){
        printf("%d\n",h->val);
        printList(h->next);
    }
}

void printListInv(Node ** h){
    if(*h != NULL){
        printListInv(&((*h)->next));
        printf("%d\n",(*h)->val);
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

int main(int argc, const char * argv[]) {
    Node * head = NULL;
    int n;
    
    head  = readList(&n);
    //printf("\nNormal order:\n");printList(head); //TEST
    printListInv(&head);
    deleteList(&head);
    //printf("\nAfter erase:\n");printList(head); //TEST
    return 0;
}
