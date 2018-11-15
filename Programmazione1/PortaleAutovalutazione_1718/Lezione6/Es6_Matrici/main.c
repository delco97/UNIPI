#include <stdio.h>
#include <stdlib.h>
#define DIM 5
#define MAX_CAR 5

void readIntArray(int *v, int dim){
    for(int i=0;i<dim;i++)scanf("%d",&v[i]);
}

//Stampa in ordine inverso i caratteri inseriti prima di un \n
void printInv(){
    char c;
    scanf("%c",&c);;
    if(c!='\n'){
        printInv();
        printf("%c",c);
    }else{
        printf("Sequenza invertita: ");
    }
}
//Somma ricorsiva degli elementi di un array
int sumVect(int *v, int dim){
    if(dim == 0)return 0;
    else return v[0] + sumVect(v+1,dim-1);
}

//Conta occorrenze di un elemento in v in modo ricorsivo
int countOcc(int *v, int dim, int target){
    if(dim==0)return 0;
    else {
        if(v[0] == target) return 1 + countOcc(v+1,dim-1,target);
        else return 0 + countOcc(v+1,dim-1,target);
    }
}

//======= LIST

struct el {
    int info;
    struct el * next;
};
typedef struct el EDL; //Elemento di lista
typedef EDL * LDE;; //Lista di elementi (puntatore a EDL)
/*
void inserisciInCoda(LDE *l, int x){
    LDE aux = malloc(sizeof(EDL));
    if(l == NULL){

    }else{

    }
}*/

//Stampa la lista in modo ricorsivo
void printLista_rec(LDE l){
    if(l==NULL)printf("\n");
    else {
        printf("%d",l->info);
        printLista_rec(l->next);
    }
}

//Inizializza lista con n valoi interi con valore default_val
void initLista(LDE *l, int n, int default_val){
    LDE aux = malloc(sizeof(EDL));
    aux->info = default_val;
    aux->next = NULL;
    *l = aux;

    for(int i=0;i<n-1;i++){
        aux->next = malloc(sizeof(EDL));
        aux = aux->next;
        aux->info = default_val;
    }
    aux->next = NULL;
}
//Aggiunge elemento in testa alla lista
void addTesta(LDE *l, int n){
    LDE aux = malloc(sizeof(EDL));
    aux->info = n;
    aux->next = *l;
    *l = aux;
}

//Aggiunge elemento in coda alla lista
void addBottom(LDE *l, int n){
    LDE aux = malloc(sizeof(EDL));
    aux->info = n;
    aux->next = NULL;
    if(*l == NULL)*l = aux;
    else{//C'è almeno un elemento nella lista
        LDE curr = *l;
        while(curr->next != NULL){//Scorro la lista finché non punto l'ultimo elemento
            curr = curr->next;
        }
        curr->next = aux;
    }
}

//Elimina elemento da lista
void cancLista(LDE *l){
    LDE aux;
    while (*l != NULL){
        aux = *l;
        *l = aux->next;
        free(aux);
    }
}

//Elimina elemento da lista (ricorsiva)
void cancLista_rec(LDE *l){
    if(*l != NULL){
        LDE aux = *l;
        free(*l);
        cancLista_rec (aux->next);
    }
}

//Cancella i primi n elemnti maggiori di 0 dalla lista
void cancMag(LDE *l,int n){
    LDE cur = *l, prec = NULL;

    while(cur!=NULL && n>0){
        if(cur->info <= 0){//elemento da NON cancellare
            //Mi limito a scorrere la lista con i due puntatori
            prec=cur;
            cur=cur->next;
        }
        else{//Cancella elemento
            n--;
            cur=cur->next;
            if(prec==NULL){//Elemento in testa
                free(*l);
                *l = cur;
            }else{//Elemento in mezzo o in fondo
                free(prec->next);
                prec->next = cur;
            }
        }
        printLista_rec(*l);
        printf("\n");
    }
}


//====== END LIST


int main()
{
    int v[DIM], target;
    LDE l;
/*
    printf("\n=====Print inversa======\n");
    printInv();

    printf("\n===Somma ricorsiva array===\n");
    printf("Inserisci %d elementi:\n ", DIM);
    readIntArray(v,DIM);
    printf("La somma degli elementi della sequenza e' di: %d",sumVect(v,DIM));

    printf("\n===Conta occorrenze di un elemento in array in modo ricorsivo===\n");
    printf("Inserisci %d elementi:\n ", DIM);
    readIntArray(v,DIM);
    printf("Inserisci elemento da cercare: ");
    scanf("%d",&target);
    printf("Sono state trovate %d",countOcc(v,DIM,target));
*/
    printf("\n===LISTE===\n");
    printf("\n===Inizializzazione lista===\n");
    initLista(&l,5,1);
    printf("Lista inizializzata: ");
    printLista_rec(l);
    printf("\n===Aggiunta di un elemento in testa===\n");
    addTesta(&l,0);
    printLista_rec(l);
    printf("\n===Aggiunta di un elemento in coda===\n");
    addBottom(&l,0);
    printLista_rec(l);
    printf("\n===Cancella elementi > 0===\n");
    cancMag(&l,10);
    printLista_rec(l);

    return 0;
}
