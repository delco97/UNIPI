#include <stdlib.h>
#include <stdio.h>

typedef struct _ABRNode{
	int k;
	int c; //0=red | 1=black
	struct _ABRNode * l;
	struct _ABRNode * r;
} ABRNode;


ABRNode * insertABR(ABRNode * u, int k, int c){
	if(u == NULL){
		ABRNode * aux = malloc(sizeof(ABRNode));
		aux->k = k;
		aux->c = c;
		aux->l = NULL;
		aux->r = NULL;
		return aux;
	}
	if(k < u->k) //Insert in left branch
		u->l = insertABR(u->l,k,c);
	else //Insert in right branch 
		u->r = insertABR(u->r,k,c);
	return u;
}

ABRNode * readABR(int n){
	ABRNode * t = NULL;
	int k;
	int c;
	for(int i=0;i<n;i++){
		scanf("%d %d",&k,&c);
		t = insertABR(t,k,c);
	}
	
	return t;
}


void printTree(ABRNode * u){
	if(u != NULL){
		printf("%d\n",u->k);
		printTree(u->l);
		printTree(u->r);
	}
}

int max(int a,int b){
	if(a>=b) return a;
	else return b;
}

int getDimMaxRed(ABRNode * u, int d){
	if(u == NULL) return d; //Empty tree
	int dimSx;
	int dimDx;
	if(u->c == 0){//red node
		dimSx = getDimMaxRed(u->l,d+1);
		dimDx = getDimMaxRed(u->r,d+1);
	}else{//balck node
		d = 0;
		dimSx = getDimMaxRed(u->l,d);
		dimDx = getDimMaxRed(u->r,d);
	}
	
	return max(dimSx,dimDx);
}


int main(){
	ABRNode * tree = NULL;
	int n; //num nodes
	scanf("%d",&n);
	tree = readABR(n);
	//printTree(tree); //DEBUG
	printf("%d",getDimMaxRed(tree,0));
	return 0;
}
