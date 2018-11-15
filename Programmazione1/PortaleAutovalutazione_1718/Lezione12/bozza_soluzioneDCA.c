#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

// Functions /Procedure to be implemented :
// add definition of procedure/function readdList()

LDE readList(){
	int input,good = 1;
	LDE head = NULL;
	LDE tail = NULL;
	do{
		scanf("%d",&input);
		if(head == NULL){//Nessun el ancora inserito
			LDE aux = malloc(sizeof(EDL));
			aux->info = input;
			aux->next = NULL;
			head = aux;
			tail = head;
		}else{//Almeno un elmento inserito
			if(tail->info <= input){//Aggiungi el in coda
				LDE aux = malloc(sizeof(EDL));
				aux->info = input;
				aux->next = NULL;
				tail->next = aux;
				tail=aux;
			}else//Termina lettura
				good = 0;
		}
		
	}while(good);
	return head;
}
// add definition of procedure/function cancella Duplicates ()

int isMember(LDE l, int a){
	if(l==NULL)return 0;
	else{
		if(l->info == a)return 1;
		else return isMember(l->next,a);
	}
}

void push(LDE *l, int v){
	LDE aux = malloc(sizeof(EDL));
	aux->info = v;
	aux->next = *l;
	*l=aux;
}

LDE cancellaDuplicates(LDE l){
	if(l == NULL)return l;
	else{
		if(isMember(l->next,l->info))return cancellaDuplicates(l->next);
		else{
			LDE partial = cancellaDuplicates(l->next);
			push(&partial,l->info);
			return partial;
		}
	}
}
// add definition of procedure/function filterLists()
void filterLists(LDE *l1,LDE l2){
	LDE prec=NULL,cur=*l1;
	while(cur!=NULL){
		if(!isMember(l2,(*l1)->info)){
			prec = cur;
			cur = cur->next;
		}else{//El da cancellare
			LDE aux = cur;
			if(prec==NULL){//In testa
				(*l1) = cur->next;
				cur = *l1;
			}else{//In mezzo o ultimo
				prec->next = cur->next;
				cur = cur->next;
			}
			free(aux);		
		}
	}	
}
// Function to print all the elements of the list :
void printList(LDE list) {
	printf("(");
	while(list != NULL){
		printf("%d ",list->info);
		list = list->next;
	}
	printf(")\n");
}

int main ( ) {
	LDE firstlist, secondlist;
	//Read and print the firstlist :
	// add call to procedure / function readList()
	firstlist = readList();
	printf("Prima lista\n") ;
	printList(firstlist) ;
	// Eliminates Duplicates from the firstlist:
	//add call to procedure/function cancellaDuplicates()
	firstlist = cancellaDuplicates(firstlist);
	printf("Prima lista senza duplicati\n" ) ;
	printList(firstlist) ;
	//Read and print the secondlist:
	//add call to procedure/function readList()
	secondlist = readList();
	printf("Seconda lista\n") ;
	printList(secondlist) ;
	// Eliminates Duplicates from the second list:
	// add call to procedure/function cancella Duplicates()
	secondlist = cancellaDuplicates(secondlist);
	printf("Seconda lista senza duplicati\n" ) ;
	printList(secondlist) ;
	// Filter the firstlist using the elements of the second list:
	// add call to procedure/function filterLists()
	filterLists(&firstlist, secondlist);
	//Print the filtered list:
	printf("Lista filtrata\n" ) ;
	printList(firstlist) ;
	return 0 ;
}
