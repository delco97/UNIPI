/*
Scrivere un programma che acquisisca da tastiera due successioni ordinate
di interi positivi, entrambe terminate da un numero negativo (che non va
inserito in lista), e le inserisca in due liste distinte. Le liste possono contenere
duplicati. Scrivere una funzione che, prese in input le due liste, crei
una terza lista di numeri interi ordinata, ottenuta mediante la “fusione” delle
prime due. Si stampi il contenuto della lista ottenuta.
*/

#include <stdlib.h>
#include <stdio.h>

struct el{
	int info;
	struct el * next;
};

typedef struct el EDL;
typedef EDL* LDE;

void printList(LDE l){
	if(l==NULL)printf("NULL\n");
	else{
		printf("%d --> ",l->info);
		printList(l->next);
	}
}


LDE readList(){
	LDE h=NULL,t=NULL;
	int x;
	do{
		scanf("%d",&x);
		if(x>=0){//Elemento da inserire in coda
			LDE aux = malloc(sizeof(EDL));
			aux->info = x;
			aux->next = NULL;
			if(h==NULL){//Primo elemento
				h=aux;
				t=h;
			}else{//Elemento i-esimo
				t->next = aux;
				t=t->next;
			}
		}
	}while(x>=0);
	return h;
}

void insOrdNonDec(LDE *l, int x){
	LDE cur=*l,prec=NULL;
	LDE aux = malloc(sizeof(EDL));
	aux->info = x;
	
	if(*l == NULL){//Lista vuota
		*l=aux;
		aux->next = NULL;
	}else{//Almeno un elemento
		while(cur!=NULL && cur->info <= x){
			prec=cur;
			cur=cur->next;
		}
		//Inserimento
		if(prec==NULL){//In testa
			aux->next = *l;
			*l=aux;
		}else{//Nel resto della lista
			aux->next = prec->next;
			prec->next = aux;
		}
	}
}

LDE mergeLists(LDE l1,LDE l2){
	LDE ris = NULL;
	while(l1!=NULL){
		insOrdNonDec(&ris,l1->info);
		l1 = l1->next;
	}
	while(l2!=NULL){
		insOrdNonDec(&ris,l2->info);
		l2 = l2->next;
	}
	return ris;
}

int main(){
	LDE l1=NULL,l2=NULL,l3=NULL;
	
	l1 = readList();
	l2 = readList();
	l3 = mergeLists(l1,l2);
	
	printList(l3);
	
	
	
}
