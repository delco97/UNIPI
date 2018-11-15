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

void print(LDE l){
	if(l==NULL)printf("\n");
	else{
		printf("%d\n",l->info);
		print(l->next);
	}
}

int main(void){
	LDE l = NULL;
	int input;

	do{
		scanf("%d",&input);
		if(input >= 0){
			insertionSort(&l,input);
		}

	}while(input>=0);//Loop till first negative number
    //Print list
    print(l);
    
    return 0;
    
}
