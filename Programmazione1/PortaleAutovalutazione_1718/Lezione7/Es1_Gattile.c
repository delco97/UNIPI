#include <stdio.h>
#define DIM 4

typedef struct{
	int id;
	int age;
	float weight;
	int food_type;
	
}Cat;

float readCats(Cat * a,int dim){
	float av_weight = 0;
    for(int i=0;i<dim;i++){
        scanf("%d",&(a[i].id));
        scanf("%d",&(a[i].age));
        scanf("%f",&(a[i].weight));
        scanf("%d",&(a[i].food_type));

        av_weight+=a[i].weight;
    }
    return av_weight/dim;
}

void printCat(Cat c){
	printf("%d ",c.id);
	switch(c.food_type){
		case 0://crocchette
			printf("crocchette");
		break;
		case 1://scatolette
			printf("scatolette");
		break;
		case 2://tonno in scatola
			printf("tonno in scatola");
		break;
		default://unkown
			printf("<food type unkown>");
	}
	printf("\n");
}

void checkDiet(Cat * a,int dim, float av_weight){
    for(int i=0;i<dim;i++){
		if(a[i].age < 4 && a[i].weight > av_weight)
			printCat(a[i]);
    }
}

int main(void){
    Cat cats[DIM];
    float av_weight;

  	av_weight = readCats(cats, DIM);

	checkDiet(cats,DIM,av_weight);
	printf("\n");
    
    
    return 0;
    
}
