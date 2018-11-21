#include <stdio.h>
#define MATRICOLA 5234
#define HELLO(x,y) ( printf("Ho %d anni e sono la matricola %d!\n",x, y))

int main(void){
  int age;
  printf("Inserisci la tua eta': ");
  scanf("%d",&age);
  //printf("Ho %d anni e sono la matricola %d!\n",age, MATRICOLA);
  HELLO(age,MATRICOLA);

  return 0;

}

