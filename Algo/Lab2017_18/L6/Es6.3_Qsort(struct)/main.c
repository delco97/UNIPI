#include <stdio.h>
#include <stdlib.h>

typedef struct _point{
	int x;
	int y;
}Point;


void printPoints(Point * a,int n){
	for(int i=0;i<n;i++)printf("%d %d\n",a[i].x,a[i].y);
}

int readPoints(Point ** a, int * n){
	scanf("%d",n);
	if(*n <= 0){
		printf("No points to read.");
		return -1;
	}else{//n > 0
		 *a = (Point *)malloc((*n) * sizeof(Point));
		 if(a == NULL){
		 		printf("An error occurred during memory allocation.");
				return -2;
		 }else{//Good allocation
		 		for(int i=0;i<(*n);i++)//Allocate and read n points
					scanf("%d %d",&((*a)[i].x),&((*a)[i].y));
		 }
	}
	return 0;
}

/*
Return values:
	<0: a < b
	>0: a > b
	=0: a = b
In this case the order relationship is the following:
  - a and b are to Point struct
	- (a.x == b.x) ==> b.y < a.y => a > b (drecreasing order for y coordinate)
	- (a.x != b.x) ==> a.x < b.x => a < b (increasing order for x coordinate)
*/
int compare(const void * a,const void * b){
	Point p1 = *((Point *)a);
	Point p2 = *((Point *)b);
	if(p1.x == p2.x)return p2.y - p1.y;
	else return p1.x - p2.x;
}

int main(){
	Point * a;
	int n;
	
	if(readPoints(&a,&n) == 0){//Good allocation and read
		//qsort(void *base, size_t nel, size_t width,int (*compar)(const void *, const void *));
		qsort(a,n,sizeof(Point),compare);
		printPoints(a,n);
		//Deallocation
		free(a);
	}
	
	return 0;
}