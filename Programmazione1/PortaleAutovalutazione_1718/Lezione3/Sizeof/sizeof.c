#include <stdio.h>

int main(void){
    int x;
    printf("Inserisci il numero di variabili intere: ");
    scanf("%d",&x);
    printf("%d\n", (int)(x*sizeof(int)));
    
    return 0;
}
