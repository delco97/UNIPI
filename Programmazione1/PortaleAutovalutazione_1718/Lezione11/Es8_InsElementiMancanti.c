/*
Scrivere un programma che acquisisca da tastiera una successione di numeri
interi positivi e li inserica in maniera ordinata in ordine non crescente
all’interno di una lista. La lista pu`o contenere duplicati. L’acquisizione da
tastiera termina quando si incontra il primo valore negativo (che non va inserito
in lista).
Dopo aver memorizzato la sequenza in una lista, utilizzare una funzione per
inserire nella posizione corretta all’interno della lista, tutti i numeri mancanti.
Stampare in output la lista ottenuta.
Non devono essere usate altre liste o array di appoggio.
Esempio: supponiamo che sia fornita in input la sequenza 7, 3, 6, 7, 10.
Dopo aver memorizzato gli elementi nella lista 10 → 7 → 7 → 6 → 3 →
NULL, vengono inseriti i numeri mancanti, ottenendo la lista composta dagli
elementi
10 → 9 → 8 → 7 → 7 → 6 → 5 → 4 → 3 → NULL.
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

void insOrdNonCres(LDE *l,int x){
	LDE prec=NULL,cur=*l;
	LDE aux = malloc(sizeof(EDL));
	aux->info = x;
	
	//Scorro lista fino a posizione di inserimento
	while(cur!=NULL && x < cur->info){
		prec = cur;
		cur = cur->next;
	}
	//Inserimento
	if(prec == NULL){//Ins in testa
		aux->next = *l;
		*l=aux;
	}else{//Ins nel resto della lista
		aux->next = prec->next;
		prec->next = aux;
	}
	
}

LDE readList(){
	LDE ris=NULL;
	int x;
	do{
		scanf("%d",&x);
		if(x>=0)//Ins elemento
			insOrdNonCres(&ris,x);
	}while(x>=0);
	return ris;
}

LDE insMancanti(LDE l){
	LDE h=l, cur=h;
	
	while(cur!=NULL){//Scorro lista
		if(cur->next !=NULL && cur->info != (cur->next)->info && cur->info-1 != ((cur->next)->info) ){//Ins
			LDE aux = malloc(sizeof(EDL));
			aux->info = cur->info-1;
			aux->next = cur->next;
			cur->next=aux;
		}
		cur = cur->next;
	}
	return h;
}

int main(){
	LDE l=NULL;
	
	l = readList();
	l = insMancanti(l);
	
	printList(l);

}
