#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

void push(LDE *l, int v){
	LDE aux = malloc(sizeof(EDL));
	aux->info = v;
	aux->next = *l;
	*l=aux;
}

void printList_Recursicve(LDE l){
	if(l==NULL)printf("NULL\n");
	else {
		printf("%d -> ",l->info);
		printList_Recursicve(l->next);
	}
}


LDE canc_rec(LDE l, int n){
	if(l==NULL){
		return l;
	}else{
		if((l->info %n)==0)return canc_rec(l->next,n);
		else{
			LDE partial = canc_rec(l->next,n);
			push(&partial,l->info);
			return partial;
		}
	}
}

void addBeforeEven(LDE *l, int x){
	if(*l != NULL){//Lista non vuota
		if( ((*l)->info) % 2 == 0){//Elemento in testa pari -> aggiungo in testa x
			push(l,x);
			addBeforeEven(&((*l)->next->next),x);//Continuo a scorrere lista
		}else
			addBeforeEven(&((*l)->next),x);//Continuo a scorrere lista
		
	}
}

int main(){
    int input;
    LDE l = NULL;

	do{
		scanf("%d",&input);
		if(input>=0){//Aggiungi elemento alla lista
			push(&l,input);
		}
	}while(input>=0);
	addBeforeEven(&l,-1);
	printList_Recursicve(l);
	return 0;
}

