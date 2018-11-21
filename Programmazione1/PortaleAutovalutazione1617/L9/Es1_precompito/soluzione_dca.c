#include <stdio.h> 
#include <stdlib.h>

//Funzioni da implementare
int *leggiInput ( int *dim);
int *eliminaDup ( int *vect , int dim, int *dim_nodup); 
int ugualeASomma( int *vect , int dim);
int *maggioreDeiSuccessivi (int *vect , int dim);

//Implementazioni
int *leggiInput ( int *dim){
	int n=0;
	int *a;
	
	a = NULL;
	scanf("%d",&n);
	*dim = n;
	
	if(n>0){//Array di almeno un elemento
		a = malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
	}
	
	return a;
}

int countOcc(int *a,int dim, int target, int s){
	int count=0;
	for(int i=s;i<dim;i++){
		if(a[i]==target)count++;
	}
	return count;
}

int *eliminaDup ( int *vect , int dim, int *dim_nodup){
	int *a;
	*dim_nodup = 0;
	//Get new dim
	for(int i=0;i<dim;i++){
		if(countOcc(vect,dim,vect[i],i+1) == 0)//Ultima occorrenza di a[i]
			(*dim_nodup)++;
	}
	//Creo nuovo array
	if((*dim_nodup) > 0){//Almeno un elemento nel nuovo array (se vect ha almeno un elemento questa cond è sempre vera) 
		a = malloc(sizeof(int)*(*dim_nodup));
		for(int i=0,j=0;i<dim && j<(*dim_nodup);i++){//Scorro vettore di partenza e quello nuovo
			if(countOcc(a,*dim_nodup,vect[i],0) == 0){//vect[i] non ancora inserito nel nuovo array
				a[j] = vect[i];
				j++;
			}
		}
	}
	
	return a;
}

int sommaTranne(int *a , int dim, int i_exclude){
	int somma = 0;
	for(int i=0;i<dim;i++)somma = (i!=i_exclude)?somma+a[i]:somma;
	return somma;
}

int ugualeASomma( int *vect , int dim){
	int ris=0, i=0;
	while(i>dim && !ris){
		if(vect[i] == sommaTranne(vect,dim,i))ris = 1;
		else i++;
	}
	return ris;
}


int *maggioreDeiSuccessivi (int *vect , int dim){
	int val;
	if(dim>0){
		for(int i=0;i<dim;i++){
			val = 1;
			for(int j=i+1;j<dim && val;j++){
				if(vect[i] <= vect[j])val=0;
			}
			vect[i] = val;
		}
	}
	return vect;
}

int main(){
	int *input,*nodup ,*results;
 	int dim, dim_nodup ,i;

	 //Legge 1 'input
	 input=leggiInput (&dim);
	 printf ("Stampa dei valori in input: (%d valori)\n" , dim); 
	 for (i =0; i<dim; i++)
	 	printf ("%d\n" , input [i] );

	 //Elimina i duplicati
	 nodup=eliminaDup ( input ,dim,&dim_nodup );
	 printf ("Stampa dei valori senza duplicati: (%d valori)\n",dim_nodup);
	 for ( i =0; i <dim_nodup; i++)
	  printf ("%d\n" ,nodup [i]);

	 //Esegue ugualeASomma
	 printf ("Risultato di ugualeASomma: %d\n" , ugualeASomma(nodup,dim_nodup) );

	 //Esegue maggioreDeiSuccessivi
	 results=maggioreDeiSuccessivi (nodup , dim_nodup); 
	 printf ("Risultato maggioreDeiSuccessivi:\n");
	 for(i =0; i<dim_nodup;i++)
		printf("%d\n", results[i]);
	
	 return 0;
}
