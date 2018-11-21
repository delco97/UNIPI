#include <stdio.h>
#include <malloc.h>

/* struttura elementi della lista */
struct el{
	int info;
	struct el *next;
};

/* prototipi delle funzioni */
struct el *crea_lista(int, int);
void visualizza_lista(struct el *);
void addTop(struct el **,int );

/*Implementazione funzioni e procedure*/
struct el *crea_lista(int n, int val){
	struct el *head, *cur;
		
	if(n<=0){
		head = NULL;
	}else{
		head = (struct el *)malloc(sizeof(struct el));
		cur = head;
		cur->info  = val;
		while(n>1){
			cur->next = (struct el *)malloc(sizeof(struct el));
			cur = cur->next;
			cur->info = val;
			n--;
		}
		cur->next = NULL;
	}
	
	return head;
}

void visualizza_lista(struct el *p){
	printf("Lista -> ");
	while(p != NULL){
		printf("%d -> ", p->info);//Print elemento corrente
		p = p->next;//Scorro lista di un elemento
	}
	printf("NULL");
}

void addTop(struct el **p,int val){
	struct el *aux;
	aux = (struct el *)malloc(sizeof(struct el));
	aux->info = val;
	
	if(*p == NULL){//Lista non inizialzzata, aggiunta del primo elemento
		aux->next = NULL;
		*p = aux;
	}else{//Lista con almeno un elmento, aggiunta in testa
		aux->next = *p;
		*p = aux;
	}
}

void addBottom(struct el **p,int val){
	struct el *aux, *cur, *prec;
	aux = (struct el *)malloc(sizeof(struct el));
	aux->info = val;
	aux->next = NULL;
	if(*p == NULL){//Lista non inizialzzata, aggiunta del primo elemento
		*p = aux;
	}else{//Lista con almeno un elmento, aggiunta in testa
		//Devo raggiungere il penultimo e ultimo elemento per aggiungere in coda
		cur = *p;//Punto al primo elemento
		prec = NULL;
		while(cur->next != NULL){
			prec = cur;
			cur = cur->next; 
		}
		cur->next = aux;
	}
}

int main(void){
	struct el *listHead;
	int n, val;
	
	//Numero di elementi da inizializzare
	printf("Inserisci numero di elementi: ");
	scanf("%d",&n);
	printf("Inserisci valore d'inizializzazione: ");
	scanf("%d",&val);
	
  	listHead = crea_lista(n, val); // crea la lista
  	printf("Lista inizializzata: \n");
  	visualizza_lista(listHead); // stampa la lista
  	
  	addBottom(&listHead, 6);
  	printf("\nLista dopo aggiunta di un elemento in coda: \n");
  	visualizza_lista(listHead); // stampa la lista
  	
  	addTop(&listHead, 5);
  	printf("\nLista dopo aggiunta di un elemento in testa: \n");
  	visualizza_lista(listHead); // stampa la lista
  	
   	
	return 0;
}
