#include <stdio.h>
#include <stdlib.h>

typedef enum{false,true} boolean;

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

void addBottom(LDE *l,int val){
	if(*l == NULL){
		LDE aux = malloc(sizeof(EDL));
		aux->info = val;
		aux->next = NULL;
		*l = aux;
	}else addBottom(&((*l)->next),val);
}

boolean checckOrder(LDE l){
	if(l == NULL){//Vuota
		return true;
	}else{//Almeno un elemento
		if(l->next == NULL){//Un solo elemento
			return true;
		}else{//Almeno due elementi
			if(l->info >= (l->next)->info) return false;
			else return checckOrder(l->next);
		}
	}
}

void printB(boolean b){
	if(b == true) printf("True\n");
	else printf("False\n");
}

void printList_Rec(LDE l){
	if(l==NULL)printf("NULL\n");
	else {
		printf("%d -> ",l->info);
		printList_Rec(l->next);
	}
}

int main(){
    int input;
    boolean ris;
    LDE l = NULL;

	do{
		scanf("%d",&input);
		if(input>=0){//Aggiungi elemento alla lista
			addBottom(&l,input);
		}
	}while(input>=0);

	//printList_Rec(l);
	
	ris = checckOrder(l);
	printB(ris);

	return 0;
}

