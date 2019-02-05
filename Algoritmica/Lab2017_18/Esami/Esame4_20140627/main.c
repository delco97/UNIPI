
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 101
#define MAX_NUM 21

typedef struct _Node{
	char name[MAX_NAME];
	char num[MAX_NUM];
	struct _Node * next;
} Node;

typedef struct _List{
	int n; //Number elements inside list
	Node * h; //Head of list
} List;

typedef struct _HashTab{
	int n; //Number of all tab cell
	int m; //Number of effective items inside tab
	List * tab; //Array of list
} HashTab;

int hash(char * str, int n){
	unsigned int sum = 0;
	int i = 0;
	while(str[i] != '\0'){
		sum += str[i];
		i++;
	}
	return sum % n;
}

void insertHash(HashTab * t,char * name, char * num){
	int h = hash(name, t->n);
	Node * aux = malloc(sizeof(Node));
	strcpy(aux->name,name);
	strcpy(aux->num,num);
	aux->next = NULL;

	Node * cur = (t->tab[h]).h;
	Node * prec = NULL;
	//Loop if name >= cur->name
	while(cur != NULL && strcmp(name,cur->name) >= 0){
		prec = cur;
		cur = cur->next;
	}
	if(prec == NULL){//Head insert
		aux->next = (t->tab[h]).h;
		(t->tab[h]).h = aux;
	}else{//Body and tail insert
		aux->next = cur;
		prec->next = aux;
	}
	
}

HashTab readHashTab(){
	HashTab t;
	int n;
	char auxName[MAX_NAME];
	char auxNum[MAX_NUM];
	scanf("%d",&n);
	t.n = n * 2;
	t.m = 0;
	t. tab = malloc(t.n * sizeof(List));
	for(int i=0;i<t.n;i++){
		t.tab[i].n = 0;
		t.tab[i].h = NULL;
	}
	//Read data
	for(int i=0;i<n;i++){
		scanf("%s",auxName);
		scanf("%s",auxNum);
		insertHash(&t,auxName,auxNum);
	}
	
	return t;
}

void printHashList(HashTab t,int k){
	if(k<0 || k>=t.n) return;
	Node * cur = t.tab[k].h;
	while(cur != NULL){
		printf("%s %s\n",cur->name,cur->num);
		cur = cur->next;
	}
} 

int main(){
	HashTab tab;
	int k;
	tab = readHashTab();
	scanf("%d",&k);
	printHashList(tab,k);
	//Deallocation
	Node * cur;
	Node * aux;
	for(int i=0;i<tab.n;i++){
		cur = tab.tab[i].h;
		aux = NULL;
		while(cur != NULL){//Destroy list
			aux = cur->next;
			free(cur);
			cur = aux;
		}
	}
	free(tab.tab);
	return 0;
}







