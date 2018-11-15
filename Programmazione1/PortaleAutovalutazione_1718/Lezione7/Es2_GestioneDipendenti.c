#include <stdio.h>
#define DIM 2

typedef struct{
	int id;
	float salary;
	int moth;
	int year;
}Employee;

void readEmployee(Employee * a,int dim){
    for(int i=0;i<dim;i++){
        scanf("%d",&(a[i].id));
        scanf("%d",&(a[i].moth));
        scanf("%d",&(a[i].year));
        scanf("%f",&(a[i].salary));
    }
}

void printEmployee(Employee c){
	printf("%d %.0f\n",c.id, c.salary);
}

void salaryIncrease(Employee * a,int dim, float salary_increase){
    for(int i=0;i<dim;i++){
		if(a[i].year < 2000 || (a[i].year = 2000  && a[i].moth < 5))
			a[i].salary += a[i].salary * salary_increase;
		
		if(a[i].salary>1200)printEmployee(a[i]);
		
    }
}

int main(void){
    Employee employees[DIM];
    float salary_increase;

	readEmployee(employees, DIM);	
	
	scanf("%f",&salary_increase);
	salary_increase /= 100;
	salaryIncrease(employees, DIM, salary_increase);
	
	printf("\n");
    
    
    return 0;
    
}
