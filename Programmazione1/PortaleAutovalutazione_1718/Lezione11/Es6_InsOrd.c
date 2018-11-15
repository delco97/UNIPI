/*
Partendo dalla definizione di ListaDiElementi data a lezione, scrivere una
procedura/funzione InserOrd che presa una lista ordinata in maniera non decrescente
inserisca un elemento nella giusta posizione rispetto all’ordinamento.
Si scriva poi un programma che acquisisca da tastiera una sequenza di numeri
postivi che possono contenere duplicati e li inserisca, usando InserOrd,
in una lista (ordinata in maniera non decrescente).
Nel main si stampi la lista ottenuta.
N.B. Non devono essere usate altre liste o array di appoggio.
*/

#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;


void insOrd(LDE *l,int x){
	LDE aux = malloc(sizeof(EDL)),cur=*l,prec=NULL;
	aux->info=x;
	while(cur!=NULL && cur->info <= x){//Scorro lista fino a punto di inserimento
		prec = cur;
		cur = cur->next;
	}
	//Inserimento
	if(prec == NULL){//In testa
		aux->next=*l;
		*l=aux;
	}else{//Nel resto della lsista
		aux->next = prec->next;
		prec->next = aux;
	}
}

LDE readList(){
	LDE head=NULL;
	int x;
	do{
		scanf("%d",&x);
		if(x>=0 ){//Aggiungi elemento
			insOrd(&head,x);
		}
	}while(x>=0);
	return head;
}

void printList(LDE l){
	if(l==NULL)printf("NULL\n");
	else{
		printf("%d -> ",l->info);
		printList(l->next);
	}
}

int main () {
	LDE list=NULL;
	
	list = readList();
	printList(list);

	
	return 0 ;
}
