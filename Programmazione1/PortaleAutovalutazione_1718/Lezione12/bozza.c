#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

// Func ti on s /Procedu re t o be implemented :
// add definition of procedure/function readdList()
// add definition of procedure/function cancella Duplicates ()
// add definition of procedure/function filterLists()

// Function to print all the elements of the list :
void printList(LDE list) {
	printf("(");
	while(list != NULL){
		printf("%d",list->info);
		list = list->next;
	}
	printf(")\n");
}

int main ( ) {
	LDE firstlist, secondlist;
	//Read and print the firstlist :
	// add call to procedure / function readList()
	
	printf("Prima lista\n") ;
	printList(firstlist) ;
	// Eliminates Duplicates from the firstlist:
	//add call to procedure/function cancella Duplicates()
	printf("Prima lista senza duplicati\n" ) ;
	printList(firstlist) ;
	//Read and print the secondlist:
	//add call to procedure/function readList()
	printf("Seconda lista\n") ;
	printList(secondlist) ;
	// Eliminates Duplicates from the second list:
	// add call to procedure/function cancella Duplicates()
	printf("Seconda lista senza duplicati\n" ) ;
	printList(secondlist) ;
	// Filter the firstlist using the elements of the second list:
	// add call to procedure/function filterLists()
	//Print the filtered list:
	printf("Lista filtrata\n" ) ;
	printList(firstlist) ;
	return 0 ;
}
