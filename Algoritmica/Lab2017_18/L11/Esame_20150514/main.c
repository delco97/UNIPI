
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_NAME 101

typedef struct _Patient{
	char name[MAX_LEN_NAME];
	struct _Patient * next;
} Patient;

typedef struct _PQueue{
	Patient * h; //Head pointer
	Patient * t; //Tail pointer
	int n; //Number of patient in queue
} PQueue;

//Insert new patient in tail
void addPatient(PQueue * q){
	PQueue aux = *q;
	Patient * p = malloc(sizeof(Patient));
	scanf("%s",p->name);
	p->next = NULL;
	
	if(aux.h == NULL){
		aux.h = p;
		aux.t = p;
	}else{//At least on element in list
		aux.t->next = p;
		aux.t = p;
	}
	*q = aux;
}
//Remove patient from head
void removePatient(PQueue * q){
	PQueue aux = *q;
	
	if(aux.h != NULL){//Al least one element in list
		if(aux.h->next == NULL){//One element in list
			free(aux.h);
			aux.h = NULL;
			aux.t = NULL;
		}else{//At least two elements
			Patient * temp = aux.h->next;
			free(aux.h);
			aux.h = temp;
		}
	}
	*q = aux;
}

void printQueue(Patient * p){
	if(p != NULL){
		printf("%s -> ",p->name);
		printQueue(p->next);
	}
}

void printArray(char ** a, int n){
	//printf("\n");
	for(int i=0;i<n;i++) printf("%s\n",a[i]);
	printf("$");
}

int compStr(const void * a, const void * b){
	char * x = *((char **)a);
	char * y = *((char **)b);
	return strcmp(x,y);
}

void sortAndPrintPatients(PQueue q){
	Patient * cur = q.h;
	char ** a = malloc(q.n * sizeof(char *));
	for(int i=0;i<q.n;i++){
		a[i] = malloc(MAX_LEN_NAME * sizeof(char));
		a[i] = cur->name;
		cur=cur->next;
	}
	qsort(a,q.n,sizeof(char *),compStr);
	printArray(a,q.n);
	//Memory deallocation
	for(int i=0;i<q.n;i++) free(a[i]);
	free(a);
}

int main(){
	PQueue q;
	q.h = NULL;
	q.t = NULL;
	q.n = 0;
	int e=0; //e = {0,1,2} //possible values for e
	
	do{
		scanf("%d",&e);
		if(e == 1){//New patient
			addPatient(&q);
			q.n++;
		} else if(e == 2){
			if(q.h != NULL) q.n--;
			removePatient(&q);
		}
	} while(e != 0);
	//printQueue(q.h); printf("\n");
	//Hospital closed. Print remaining patients in alphabetical order
	sortAndPrintPatients(q);
	//Memory deallocation
	Patient * cur = q.h;
	while (cur != NULL) {
		Patient * aux = cur->next;
		free(cur);
		cur = aux;
	}
	
	return 0;
}
