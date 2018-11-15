#include <stdio.h>

void diff_abs(float *a, float *b){
	float temp_1 = *a-*b, temp_2 = *b-*a;
	*a = temp_1;
	*b = temp_2;
}

int main(void){
    float a,b;
    
    scanf("%f",&a);
    scanf("%f",&b);
    diff_abs(&a, &b);
    
    printf("%.2f\n %.2f\n",a,b);
    
    return 0;
    
}
