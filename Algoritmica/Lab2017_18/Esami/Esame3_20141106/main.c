#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 101

typedef struct _Item {
	char txt[MAX_LEN];
	int val;
	struct _Item * next;
} Item;

typedef struct _HashTab {
	int n; //Number of slots
	Item ** tab;
} HashTab;

int hash(char * s, int n){
	unsigned int x=0;
	int i=0;
	while(s[i]!='\0'){
		x+=s[i];
		i++;
	}
	return (x % n);
}

int compare(const void * a, const void * b){
	Item x = *((Item *)a);
	Item y = *((Item *)b);
	if(x.val != y.val) return y.val - x.val;
	else return strcmp(x.txt,y.txt);
}

void printTab(HashTab t){
	Item * cur = NULL;
	for(int i=0;i<t.n;i++){
		cur = t.tab[i];
		printf("\ni = %d: ",i);
		while(cur != NULL){
			printf("%s[%d]",cur->txt,cur->val);
			cur = cur->next;
		}
	}
}

void printSortedTab(HashTab t){
	Item * cur = NULL;
	int count;
	Item * a;
	count = 0;
	if(t.tab == NULL) return;
	for(int i=0;i<t.n;i++){
		cur = t.tab[i];
		while(cur != NULL){
			count++;
			cur = cur->next;
		}
	}
	if(count > 0){
		a = malloc(count * sizeof(Item));
		int j = 0;
		for(int i=0;i<t.n && j < count;i++){
			cur = t.tab[i];
			while(cur != NULL){
				a[j].val = cur->val;
				strcpy(a[j].txt,cur->txt);
				cur = cur->next; 
				j++;
			}
		}
		qsort(a,count,sizeof(Item),compare);
		for(int i=0;i<15;i++) printf("%s\n",a[i].txt);
		//Deallocation
		free(a);
	}
	
}

HashTab insertItem(HashTab t,char * str, int val){
	int h = hash(str,t.n);
	
	Item * cur = t.tab[h];
	while(cur != NULL){
		if( strcmp(str,cur->txt) == 0 ){
			if(val <= cur->val){
				return t;
			}else{//val > cur->val
				cur->val = val;
				return t;
			}
		}
		cur = cur->next;
	}
	//str not found, insert new item in head
	Item * aux = malloc(sizeof(Item));
	strcpy(aux->txt,str);
	aux->val=val;
	aux->next = t.tab[h];
	t.tab[h] = aux;
	
	return t;
}

HashTab readHashTab(HashTab t){
	char str[MAX_LEN];
	int val;
	int n;
	scanf("%d",&n);
	t.n  = 2*n;
	
	//Memory allocation
	t.tab = (Item **) malloc(t.n * sizeof(Item *));
	//Init slots
	for(int i=0;i<t.n;i++) t.tab[i] = NULL;
	//Insert items
	for(int i=0;i<n;i++){
		scanf("%s",str);
		scanf("%d",&val);
		t = insertItem(t,str,val);
		//printTab(t);
	}
	
	return t;
}

void deallocationHashTab(HashTab * t){
	Item * cur;
	Item * tmp;
	for(int i=0;i<t->n;i++){//Deallocate list memory
		cur = t->tab[i];
		while(cur != NULL){
			tmp = cur->next;
			free(cur);
			cur = tmp;
		}
		t->tab[i] = NULL;
	}
	free(t->tab);
	t->tab = NULL;
}

int main(){
	HashTab tab;
	
	tab = readHashTab(tab);
	//printTab(tab);
	//printf("\n***Print SORTED****\n");
	printSortedTab(tab);
	deallocationHashTab(&tab);
	//printf("\n***Print DEALLOCATED****\n");
	//printSortedTab(tab);
	return 0;
}

