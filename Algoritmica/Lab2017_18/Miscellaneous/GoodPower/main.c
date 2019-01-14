#include<stdio.h> 

int power2(int n){//n>=0
  return 1 << n;
}

int main() 
{ 
    int n;
    do{
      scanf("%d",&n);
      if(n>=0)printf("Res: %d\n",power2(n));
    }while(n>=0);
    return 0; 
}