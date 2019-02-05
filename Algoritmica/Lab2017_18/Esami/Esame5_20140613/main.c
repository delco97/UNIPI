
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 101

typedef struct _Exam{
	char name[MAX_NAME];
	int cred;
	int dif;
} Exam;

Exam * readExams(int n){
	Exam * aux = NULL;
	if(n>0){
		aux = (Exam *) malloc(n * sizeof(Exam));
		for(int i=0;i<n;i++){
			scanf("%s",aux[i].name);
			scanf("%d",&(aux[i].cred));
			scanf("%d",&(aux[i].dif));
		}
	}
	return aux;
}

void printExams(Exam * a,int n){
	for(int i=0;i<n;i++)
		printf("%s %d %d\n",a[i].name,a[i].cred,a[i].dif);
	
}

int compExam(const void * a,const void * b){
	Exam x = *((Exam *)a);
	Exam y = *((Exam *)b);
	if(x.cred != y.cred) return y.cred - x.cred;
	else{
		if(x.dif != y.dif) return x.dif - y.dif;
		else return strcmp(x.name,y.name);
	}
}

int compExamName(const void * a,const void * b){
	Exam x = *((Exam *)a);
	Exam y = *((Exam *)b);
	return strcmp(x.name,y.name);
}

void printRes(Exam * a, int n, int k){
	int i=0;
	int sumCred = 0;
	int count=0;
	Exam * selected = malloc(n * sizeof(Exam));
	while(i < n && sumCred < k){
		if(sumCred + a[i].cred <= k){
			sumCred+=a[i].cred;
			strcpy(selected[count].name,a[i].name);
			count++;
		}
		i++;
	}
	qsort(selected,count,sizeof(Exam),compExamName);
	for(int i=0;i<count;i++)
		printf("%s\n",selected[i].name);
	
	free(selected);
}

int main(){
	int k; //Target number of credits (k>0)
	int n; //Number of exams available (n>0)
	Exam * exams;
	scanf("%d",&k);
	scanf("%d",&n);
	exams = readExams(n);
	//printf("\nExams read before sort:\n");printExams(exams, n);
	qsort(exams,n,sizeof(Exam),compExam);
	//printf("\nExams read after sort:\n");printExams(exams, n);
	printRes(exams,n,k);
	//Deallocation
	free(exams);
	return 0;
}







