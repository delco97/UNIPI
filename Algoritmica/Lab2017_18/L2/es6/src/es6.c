
#include <stdio.h>
#include <stdlib.h>

//Prototypes
char* my_strcat1(char *s1, char *s2, int dim1, int dim2);
//Implementations
char* my_strcat1(char *s1, char *s2, int dim1, int dim2){
	int i=0,j=0,dim_cat = dim1+dim2+1;

	char *cat = malloc(dim_cat * sizeof(char));


	while(s1[j]!='\0' && i<dim_cat){cat[i]=s1[j];i++;j++;}
	j=0;
	while(s2[j]!='\0' && i<dim_cat){cat[i]=s2[j];i++;j++;}
	return cat;
}

int main(void) {
	char *s1;
	char *s2;
	char *cat;
	int dim1,dim2;

	scanf("%d",&dim1);
	s1 = malloc(sizeof(char)*(dim1+1));
	scanf("%s",s1);
	scanf("%d",&dim2);
	s2 = malloc(sizeof(char)*(dim2+1));
	scanf("%s",s2);

	cat = my_strcat1(s1,s2,dim1,dim2);
	printf("%s\n",cat);
	free(s1);
	free(s2);
	free(cat);

	return EXIT_SUCCESS;
}
