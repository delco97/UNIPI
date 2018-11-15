/*
Partendo dalla definizione di ListaDiElementi data a lezione, scrivere un
programma che acquisisca da tastiera una successione di numeri interi positivi
e li inserisca in ordine di arrivo ad una lista.
La lista puo’ contenere duplicati, e l’acquisizione da tastiera termina quando
si incontra il primo valore negativo (che non va inserito in lista).
Si stampi: usando la funzione CalcoloSomma la somma dei valori contenuti
negli elementi della lista e usando la funzione CalcoloNElementi il numero
degli elementi nella lista che contengono un valore strettamente maggiore di
un quarto della somma ottenuta dalla funzione CalcoloSomma.
**Esempio***
Input
5
7
2
20
-1
Output
34 //5+7+2+20=34
1 //Solo il 20 e’ maggio*/

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

int calcolaSomma(LDE l){
	if(l==NULL) return 0;
	else return (l->info + calcolaSomma(l->next));	
}

int calcolaNElementi(LDE l,int s){
	if(l==NULL) return 0;
	else{
		if(l->info > (s/4))return 1 + calcolaNElementi(l->next,s);
		else return calcolaNElementi(l->next,s);
	}
}

int main ( ) {
	LDE list=NULL;
	int somma,nEl;
	
	list = readList();
	
	somma = calcolaSomma(list);
	nEl = calcolaNElementi(list,somma);
	
	printf("%d\n %d\n",somma,nEl);
	
	return 0 ;
}
