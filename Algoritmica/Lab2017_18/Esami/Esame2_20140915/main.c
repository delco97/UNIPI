#include <stdio.h>
#include <stdlib.h>

typedef struct _TNode{
	int k;
	int hasProp;
	struct _TNode * l;
	struct _TNode * r;
} TNode;

TNode * insertABR(TNode * u,int k){
	if(u == NULL){
		TNode * aux = malloc(sizeof(TNode));
		aux->k = k;
		aux->l = NULL;
		aux->r = NULL;
		aux->hasProp = 0;
		return aux;
	}
	//Tree not empty
	if(k <= u->k) u->l = insertABR(u->l,k);
	else u->r = insertABR(u->r,k);
	return u;
}

void printABR(TNode * u){
	if(u!=NULL){
		printABR(u->l);
		printf("%d ",u->k);
		printABR(u->r);
	}
}

void printABR_HasProp(TNode * u){
	if(u!=NULL){
		printABR_HasProp(u->l);
		if(u->hasProp == 1)printf("%d\n",u->k);
		printABR_HasProp(u->r);
	}
}

typedef struct _Res{
	int L;
	int R;
} Res;

Res numLR(TNode * u){
	Res r;
	r.L = 0;
	r.R = 0;
	if(u == NULL){
		return r;
	}
	if(u->l != NULL){//Vist left
		Res rSx = numLR(u->l);
		r.L += 1 + rSx.L;
	}
	if(u->r != NULL){//Vist right
		Res rDx = numLR(u->r);
		r.R += 1 + rDx.R;
	}
	if(r.L > r.R) u->hasProp = 1;
	return r;
}

void freeABR(TNode * u){
	if(u == NULL) return;
	if(u->l == NULL && u->r == NULL){ free(u); return;}
	if(u->l != NULL) freeABR(u->l);
	if(u->r != NULL) freeABR(u->r);
}

int main(){
	TNode * tree = NULL;
	
	int n=0;
	int k=0;
	
	//****Read ABR tree
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){//Insert nodes in tree
		scanf("%d",&k);
		tree = insertABR(tree,k);
	}
	//printABR(tree);
	//printf("Nodes that satisfy the property L(u) > R(u):\n");
	numLR(tree);
	printABR_HasProp(tree);
	//***Memory deallocation
	freeABR(tree);
	
	return 0;
}





