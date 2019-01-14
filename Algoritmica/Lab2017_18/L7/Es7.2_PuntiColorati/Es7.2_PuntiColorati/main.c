//
//  main.c
//  Es7.2_PuntiColorati
//
//  Created by Andrea Del Corto on 04/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _ColoredPoint{
    int x;
    int y;
    int c; // Color
} ColoredPoint;

typedef struct _Query{
    int x1;
    int x2;
    int y1;
    int y2;
} Query;

void printPoints(ColoredPoint * a,int n){
    for(int i=0;i<n;i++) printf("%d %d %d\n",a[i].x,a[i].y,a[i].c);
}

ColoredPoint * readPoints(int n){
    ColoredPoint * a = NULL;
    a = (ColoredPoint *)malloc(n * sizeof(ColoredPoint));
    if(a == NULL)printf("\nBad allocation.");
    else{//Good allocation
        for(int i=0;i<n;i++){
            //fscanf(fp,"%d %d %d",&a[i].x,&a[i].y,&a[i].c); //DEBUG
            scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].c);
        }
    }
    return a;
}

void printQueries(Query * a,int n){
    for(int i=0;i<n;i++) printf("%d %d %d %d\n",a[i].x1,a[i].y1,a[i].x2,a[i].y2);
}

Query * readQueries(int n){
    Query * a = NULL;
    a = (Query *)malloc(n * sizeof(Query));
    if(a == NULL)printf("\nBad allocation.");
    else{//Good allocation
        for(int i=0;i<n;i++){
            //fscanf(fp,"%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2); //DEBUG
            scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        }
    }
    return a;
}

int comparePoints(const void * a,const void *b){
    ColoredPoint p1 = *((ColoredPoint *)a);
    ColoredPoint p2 = *((ColoredPoint *)b);
    return p1.c - p2.c;
}

int isPointInsideQuery(Query q,ColoredPoint p){
    return (q.x1 <= p.x && p.x <= q.x2) && (q.y1 <= p.y && p.y <= q.y2);
}

int countPointMatches(Query q,ColoredPoint * inputPoints,int n){
    int nMatch = 0; //number of DISTINCT points inside query q
    int lastPoint = -1; //position last point counted in inputPoints
    
    for(int i=0;i<n;i++){//Loop through inputPoints
        if(isPointInsideQuery(q,inputPoints[i])){//Current point match query
            if(lastPoint == -1){//First loop
                nMatch++;
                lastPoint++;
            }else{//Other points have been counted, is current point new ?
                if(inputPoints[i].c != inputPoints[lastPoint].c){//Current point is not the last one counted
                    lastPoint = i;
                    nMatch++;
                }
            }
        }
    }
    
    
    return nMatch;
}

int main(int argc, const char * argv[]) {
    ColoredPoint * points;
    Query * queries;
    int n; //Number of colored points
    int m; //Number of queries
    
    //****DEBUG
    //char ch;
    //fp = fopen("/Users/Andrea/Desktop/input10.txt", "r"); // read mode
    //while((ch = fgetc(fp)) != EOF)
    //  printf("%c", ch);
    //****END_DEBUG
    //rewind(fp); //****DEBUG
    //fscanf(fp,"%d",&n); //****DEBUG
    //fscanf(fp,"%d",&m); //****DEBUG
    scanf("%d %d\n",&n ,&m);
    //ASSUMPTION: n > 0 && m > 0
    points = readPoints(n);
    queries = readQueries(m);
    if(points != NULL && queries != NULL){//Good read and allocation
        //printf("\nPoints after read: \n");printPoints(points, n); //TEST
        //printf("\nQueries: \n"); printQueries(queries, m); //TEST
        qsort(points, n, sizeof(ColoredPoint), comparePoints); //Sort by color O(nlog(n))
        //printf("\nPoints after sort: \n");printPoints(points, n); //TEST
        //Result
        for(int i=0;i<m;i++){//Loop queries
            printf("%d\n",countPointMatches(queries[i],points,n));
        }
    }
    
    //Deallocation
    if(points != NULL)free(points);
    if(queries != NULL)free(queries);
    //fclose(fp);//****DEBUG
    return 0;
}
