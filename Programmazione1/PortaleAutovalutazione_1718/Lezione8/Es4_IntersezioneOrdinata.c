#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

void insertionSort(LDE *l,int v){
	LDE cur=*l, prec=NULL;
	LDE aux = malloc(sizeof(EDL));
	aux->info = v;

	while(cur!=NULL && cur->info < v){//Scorro lista finché incontro elementi più piccoli di v
		prec = cur;
		cur = cur->next;
	}
	//Inserimento di aux
	if(prec==NULL){//Inserimento in testa
		*l = aux;
		aux->next = cur;
	}else{//Inserimento nel mezzo o in coda
		if(cur==NULL){//Aggiunta in coda
			prec->next = aux;
			aux->next = cur;
		}else{//Aggiunta in mezzo
			prec->next = aux;
			aux->next = cur;
		}
    }
}

void addBottom(LDE *l,int v){
	LDE prec = NULL;
	LDE cur = *l;
	LDE aux = malloc(sizeof(EDL));
	aux->info = v;
	aux->next = NULL;
	if(cur==NULL){//Lista vuota
		*l = aux;
	}else{//Lista con almeno un elemento
		while(cur!=NULL){//Scorro lista fino in fondo
			prec = cur;
			cur = cur->next;
		}
		//cur == NULL e prec punta ultimo elemento della lista
		prec->next = aux;
	}
}

int isMember(LDE l, int v){
	int found = 0;
	while(l!=NULL && !found){//Scorro lista finché incontro elementi più piccoli di v
		if(l->info == v)found = 1;
		else l = l->next;
	}
	return found;
}

LDE intersection(LDE l1, LDE l2){
	LDE res = NULL;
	while(l1!=NULL){//Scorro l1
		if(isMember(l2,l1->info) && !isMember(res,l1->info))addBottom(&res,l1->info);
		l1 = l1->next;
	}
	return res;
}


void print(LDE l){
	if(l==NULL)printf("\n");
	else{
		printf("%d\n",l->info);
		print(l->next);
	}
}

int main(void){
	LDE l1 = NULL,l2 = NULL,l3 = NULL;
	int input,readIndex=0;//redaIndex=0 -> reading list 1, otherwise list 2.

	while(readIndex<2){//Read two list keeping their values in order (from the smallest to the biggest)
		scanf("%d",&input);
		if(input < 0)//End read of list
			readIndex++;
		else{//Insert value in on of two list
			if(readIndex==0)insertionSort(&l1,input);
			else insertionSort(&l2,input);
		}		
	}
	//Lists intersection
	l3 = intersection(l1,l2);
    //Print list
    print(l3);
    return 0;
    
}
