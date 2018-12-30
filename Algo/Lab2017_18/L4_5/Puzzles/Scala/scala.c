#include <stdlib.h>
#include <stdio.h>
//**************** Data Types **************
typedef struct point {
   int  x;
   int  y;
} Point;

typedef Point* Points;
//**************** Prototypes **************
Points readPoints(int * n);
int partitionByY(Points a, int sx, int px, int dx);
void quicksort( Points a, int sx, int dx );
void swap(Point * a,Point * b);
void printPoints(Point a[], int n);
int stairArea(Points source,int nPoints);
//**************** Implementations **************
void printPoints(Point a[], int n){
  if(a == NULL)return;
  for(int i=0;i<n;i++)printf("(%d,%d) ",a[i].x,a[i].y);
}

Points readPoints(int * n){
  Points points = NULL;
  *n=0;
  
  scanf("%d",n);
  if(*n <= 0){
    printf("The read has not been performed becuase the number of points is lower then 0 (n = %d)",*n);
  }else{//Something to read
    points = (Points)malloc((*n) * sizeof(Point));
    if(points == NULL){//Error during allocation
      printf("Impossible to allocate space for %d points",*n);
    }else{//Good allocation, start reading
      for(int i=0;i<(*n);i++)//Reading input points
        scanf("%d %d",&points[i].x, &points[i].y);
    }
  }
  return points;
}

void swap(Points a,Points b){
  Point tmp = *a;
  *a = *b;
  *b = tmp;
}

int partitionByY(Points a, int sx, int px, int dx) {
    int i = sx - 1;
    int j;

    swap(&a[px],&a[dx]); //pivot in the rightmost position

    for(j=sx;j<=dx-1;j++){
        if(a[j].y <= a[dx].y){//a[j] needs to stay in area 1
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[dx]); //pivot in the position immediately after the biggest item of area 1
    return i+1;
}

void quicksort( Points a, int sx, int dx ) {

  int perno, pivot;
  if( sx < dx ) {
    pivot = (rand() % (dx - sx + 1)) + sx; //num = Random[lower;upper]
    perno = partitionByY(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot]
                                                da quelli maggiori o uguali */
    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);

  }

}

int stairArea(Points a,int nPoints){
    if(a == NULL) return 0;
    int xBound = 0;
    int area=0;
    //Loop through all points, from the one withe the biggest y to the one with the smaller y
    for(int i = nPoints - 1; i >= 0; i-- ){
      if(a[i].x > xBound){
        //printf("(%d , %d) ",a[i].x,a[i].y);
        area += (a[i].x - xBound) * a[i].y; 
        xBound = a[i].x ;
      }
    }
    
    return area;
}

int main(){
  int nPoints=0,area = 0;
  Points points;
  
  points = readPoints(&nPoints);
  if(nPoints > 0 && points!= NULL){//Evaluate input
    /* //######### Debug #########
    printf("\nPoints just read:\n");
    printPoints(points,nPoints);
    */
    quicksort(points,0,nPoints - 1); //Sort points by their y coordinate
    
    /* //######## #Debug #########
    printf("\nPoints after sort by y coordinate:\n");
    printPoints(points,nPoints);
    printf("\n\n");
    */
    //Return area of stair
    area = stairArea(points,nPoints);
    printf("%d\n",area);
    //return calcArea();
  }
    
  return 0;
}