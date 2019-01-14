//
//  main.c
//  Es10.3_ListaMono_Canc
//
//  Created by Andrea Del Corto on 13/01/19.
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

void removeLessEqualAvg(List * l, int avg){
    Node * cur = l->h;
    Node * prev = NULL;
    
    if(cur != NULL){//At least one element in list
        while(cur != NULL){//Loop elements
            if(cur ->k <= avg){//Element to remove
                if(cur == l->h){//Remove in head
                    l->h = cur->next;
                    free(cur);
                    cur = l->h;
                    prev = NULL;
                }else{//Remove in the body or tail
                    prev->next = cur->next;
                    free(cur);
                    cur = prev->next;
                }
            }else{//No canc
                prev = cur;
                cur = cur->next;
            }
        }
    }
}

int readList(List * l){
    int n,k,avg=0;
    scanf("%d",&n);

    for(int i=0;i < n;i++){//Read expected values
        scanf("%d",&k);
        avg+=k;
        insertBottom(l,k);
    }
    return avg/n;
}

int main(int argc, const char * argv[]) {
    List l;
    int avg;
    
    l.h = NULL;
    l.t = NULL;
    
    avg = readList(&l);
    
    printf("%d\n",avg);
    printList(l);
    removeLessEqualAvg(&l,avg);
    printf("\n");
    printList(l);
    
    return 0;
}

