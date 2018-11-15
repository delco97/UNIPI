#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

void push(LDE *l,int v){
	LDE aux = malloc(sizeof(EDL));
	aux->info = v;
	aux->next = *l;
	*l = aux;
}

void pop(LDE *l){
	LDE aux;

	if(*l!=NULL){
		aux = *l;
		*l = (*l)->next;
		free(aux);
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
		if(input>0)//Push
			push(&l,input);
		else{
			if(input==0)//Pop
				pop(&l);
		}
	}while(input>=0);//Loop till first negative number
    //Print list
    print(l);
    
    return 0;
    
}
