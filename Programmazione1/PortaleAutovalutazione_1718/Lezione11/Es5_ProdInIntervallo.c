/*
Scrivere un programma che acquisisca da tastiera due numeri N e M (con
N < M) e una successione di numeri interi positivi e li inserisca all’interno
di una lista. La lista non pu`o contenere duplicati. L’acquisizione da tastiera
termina quando si incontra il primo valore negativo (che non va inserito in
lista).
Dopo aver memorizzato la sequenza in una lista ordinata, utilizzare una
funzione per calcolare il prodotto degli elementi della lista compresi tra N
e M. In particolare, si scriva una funzione che riceve come parametro la
testa della lista e i due interi N e M e che restituisce il prodotto dei soli
valori della lista compresi tra N e M. Se la lista `e vuota, la funzione deve
restituire il valore –1. Ad esempio passando come parametro la testa della
lista 1 → 2 → 3 → 4 → 5 → 7 → 8 → 9 → NULL e i valori N = 3, M = 7,
la funzione deve restituire 20, dato che 4*5=20.
*/

#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;


int isMember(LDE l, int x){
	if(l==NULL)return 0;
	else if(l->info == x) return 1;
		 else return isMember(l->next,x);
}

LDE readList(){
	LDE head=NULL,tail=NULL;
	int x;
	do{
		scanf("%d",&x);
		if(x>=0 && !isMember(head,x)){//Aggiungi elemento in coda
			LDE aux = malloc(sizeof(EDL));
			aux->info = x;	
			aux->next = NULL;		
			if(head==NULL){//Primo el
				head=aux;
				tail = head;
			}else{//El n-essimo
				tail->next = aux;
				tail = tail->next;
			}
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

int prodFra(LDE l,int n, int m){
	int ris = -1;
	if(l!=NULL){//C'è almeno un elmento
		ris = 1;
		while(l!=NULL){
			ris *= (l->info>n && l->info < m)?l->info:1;
			l=l->next;	
		}
	}
	return ris;
}

int main () {
	LDE list=NULL;
	int n,m,prod;
	
	scanf("%d\n%d",&n,&m);
	list = readList();
	//printList(list);
	prod = prodFra(list,n,m);

	printf("%d\n",prod);
	
	return 0 ;
}
