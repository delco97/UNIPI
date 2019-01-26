
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _TNode {
	int k;
	struct _TNode * p;
	struct _TNode * l;
	struct _TNode * r;
} TNode;


TNode * insertABR(TNode * t,int k){
    if(t == NULL){
		TNode * aux = (TNode *)malloc(sizeof(TNode));
		aux->k = k;
		aux->l = NULL;
		aux->r = NULL;
		return aux;
    }
    //Tree not empty
    if(k < t->k)t->l = insertABR(t->l,k);
    else t->r = insertABR(t->r,k);
    return t;
}

TNode * readABRTree(int * dim){
	TNode * t = NULL;
	int n;
	int k;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		t = insertABR(t,k);
	}
	*dim = n;
	return t;
}

void printABR_Intermediate(TNode * t){
	if(t != NULL){
		printABR_Intermediate(t->l);
		printf("%d ",t->k);
		printABR_Intermediate(t->r);
	}
}

int max(int a,int b){
	if(a>=b) return a;
	else return b;
}

typedef struct _res {
	int maxSum;
	int min;
} Res;

Res getMaxSum(TNode * u){
	if(u == NULL){
		Res r;
		r.maxSum=0; r.min=1000000000;
		return r;
	}

	Res res; res.maxSum=u->k; res.min=u->k;
	Res sx = getMaxSum(u->l);
	Res dx = getMaxSum(u->r);
	
	if(sx.maxSum == dx.maxSum){
		res.maxSum += sx.maxSum;
		if( sx.min < res.min) res.min = sx.min; 
	}else{
		if(sx.maxSum < dx.maxSum){
			res.maxSum += dx.maxSum;
			if( dx.min < res.min) res.min = dx.min; 
		}else{//sx.maxSum > dx.maxSum
			res.maxSum += sx.maxSum;
			if( sx.min < res.min) res.min = sx.min; 
		}
	}
	
	return res;
}

int main(){
	TNode * tree;
	int n;
	
	tree = readABRTree(&n);
	
	//printABR_Intermediate(tree);
	if(n==0) printf("0\n");
	else{
		Res r = getMaxSum(tree);
		//printf("Somma massima: %d\n",r.maxSum);
		printf("%d\n",r.min);
	}
	
	return 0;
}


















