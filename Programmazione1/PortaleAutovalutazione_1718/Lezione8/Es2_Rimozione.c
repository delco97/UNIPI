#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

void addHead(LDE *l,int v){
	LDE aux = malloc(sizeof(EDL));
	aux->info = v;
	
	if(*l==NULL){//Lista vuota
		*l = aux;
		aux->next = NULL;
	}else{//Lista con almeno un elemento
		aux->next = *l;
		*l = aux;
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

void canc(LDE *l,int v){
	LDE prec = NULL;
	LDE cur = *l;
	if(cur != NULL){//Lista NON vuota
		//Cerco elemento da cancellare
		while(cur!=NULL && cur->info != v){//Scorro lista finché non trovo elemnto da cancellare
			  prec = cur;
			  cur=cur->next;
		}
			
		if(cur != NULL){//Elemento da cancellare trovato
			if(prec == NULL){//Elemento da cancellare in testa
				*l=cur->next;
				free(cur);
				
			}else{//Elemento da cancellare nel mezzo o in fondo alla lista
				if(cur->next == NULL){//Elemento in fondo alla lista
					prec->next=NULL;
					free(cur);
				}else{//Elemento in mezzo alla lista
					prec->next=cur->next;
					free(cur);
				}

			}
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
		if(input != 0){//End
			if(input<0)//input <0 -> Canc abs(input)
				canc(&l,abs(input));
			else{//input>0
				if(input%2 == 0)//Pari -> AddHead
					addHead(&l,input);
				else//numero dispari >=0
					addBottom(&l,input);
			}
		}

	}while(input!=0);//Loop till first 0
    //Print list
    print(l);
    
    return 0;
    
}
