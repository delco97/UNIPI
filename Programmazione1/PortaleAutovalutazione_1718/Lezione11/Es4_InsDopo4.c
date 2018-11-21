/*
Partendo dalla definizione di ListaDiElementi data a lezione, scrivere un
programma che acquisisca da tastiera una successione di numeri interi positivi
e li inserisca in ordine di arrivo in una lista.
Il programma legge anche dall’input un valore intero n.
Si scriva una procedura/funzione che preso una lista e un intero n inserisca
l’intero dopo il quarto elemento della lista.
Se gli elementi della lista sono meno di 4 si inserisca l’elemento in coda. Nel
main poi si stampi la lista cosi’ ottenuta.
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

void push(LDE *l,int x){
	LDE aux = malloc(sizeof(EDL));
	aux->info = x;
	aux->next = *l;
	*l=aux;
}

void printList(LDE l){
	if(l==NULL)printf("NULL\n");
	else{
		printf("%d -> ",l->info);
		printList(l->next);
	}
}

void InserisciDopo4(LDE *l, int x){
	LDE cur=*l,aux;
	int c=1;
	aux = malloc(sizeof(EDL));
	aux->info = x;
	
	if(cur==NULL){
		*l=aux;
		aux->next = NULL;
	}else{
		while(cur->next != NULL && c!=4){
			cur=cur->next;
			c++;
		}
		aux->next = cur->next;
		cur->next = aux;
	}
}


int main () {
	LDE list=NULL;
	int n;
	
	list = readList();
	scanf("%d",&n);
	InserisciDopo4(&list,n);

	printList(list);
	
	return 0 ;
}
