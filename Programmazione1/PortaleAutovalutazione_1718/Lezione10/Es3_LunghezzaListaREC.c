#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

void push(LDE *l, int v){
	LDE aux = malloc(sizeof(EDL));
	aux->info = v;
	aux->next = *l;
	*l=aux;
}

int listLen_Recursicve(LDE l){
	if(l==NULL)return 0;
	else return 1 + listLen_Recursicve(l->next);
}

int main(){
    int input;
    LDE l = NULL;
    
	do{
		scanf("%d",&input);
		if(input>=0){//Aggiungi elemento alla lista
			push(&l,input);
		}
	}while(input>=0);
	printf("%d\n",listLen_Recursicve(l));
	return 0;
}

