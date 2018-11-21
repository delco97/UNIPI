/*
Partendo dalla definizione di ListaDiElementi data a lezione, scrivere un
programma che legga una successione di numeri interi positivi e li inserisca
in ordine di arrivo ad una lista. L’acquisizione da tastiera termina quando si
incontra il primo valore negativo (che non va inserito in lista).
Si scriva un programma che usando opportune procedure o funzioni individui
il primo numero dispari (se esiste altrimenti -1) e il primo numero pari
(se esiste altrimenti -1) degli elementi della lista.
Le funzioni/procedure non devono necessariamente scorrere tutta la lista
ma si devono fermare appena possibile.
Le funzioni/procedure non devono stampare nulla ma passare al main i
valori trovati.
Nel main poi si stampino i valori ottenuti.
N.B E’ possibile scrivere una procedura che trovi entrambi i valori.
Esempio
Input
5
7
2
20
-6
Output
5
2
*/

#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

//Legge gli elementi mettendoli in coda alla lista.
//In questo modo l'ordine di inserimento è uguale all'ordine in lista
LDE readList(){
	int x;
	LDE head = NULL,tail=head;
	do{
		scanf("%d",&x);
		if(x>=0){//Elemento da aggiungere nella lista
			LDE aux = malloc(sizeof(EDL));
			aux->info = x;
			aux->next = NULL;
			if(head==NULL){//Primo elemento
				head=aux;
				tail=head;
			}else{//n-esimo elemento
				tail->next = aux;
				tail=tail->next;
			}
		}
	}while(x>=0);

	return head;
}

void findPD(LDE l, int *p,int *d){
	if(l!=NULL){
		
		//Pari trovato?
		if(*p == -1 && ((l->info)%2)==0)*p = l->info;
		//Dispari trovato?
		if(*d == -1 && ((l->info)%2)==1)*d = l->info;
		//E' rimasto qualcosa da trovare?
		if(*p==-1 || *d==-1)findPD(l->next,p,d); 
	}
}


int main ( ) {
	LDE list=NULL;
	int p=-1,d=-1;
	
	list = readList();
	findPD(list,&p,&d);

	printf("%d\n%d\n",d,p);
	
	return 0 ;
}
