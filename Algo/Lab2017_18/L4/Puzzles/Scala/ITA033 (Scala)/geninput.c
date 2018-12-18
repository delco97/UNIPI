
#include <stdio.h>

#define MAXN	100000

typedef struct { int x,y; } point;
point pt[MAXN];

int comp( const void *a, const void *b ) {
	if ( ((point *)a)->y - ((point *)b)->y )
		return ((point *)a)->y - ((point *)b)->y;
	return ((point *)a)->x - ((point *)b) ->x;
}

int main( int argc, char **argv ) {
	int i, j, N, MAXV;
	point dep;
	
	srand( time( NULL ) );
	N = atoi( argv[ 1 ] );
	MAXV = atoi( argv[ 2 ] );
	if ( N < 1 || N > MAXN ) 
		fprintf( stderr, "Fuori range!\n" );
	else {
		printf( "%d\n", N );
		do {
			for ( i = 0; i < N; i++ ) {
				pt[i].x=1+rand() % MAXV;
				pt[i].y=1+rand() % MAXV;
			}
			qsort( pt, N, sizeof( point ), comp );
			for ( i = 0; i < N-1; i++ )
				if ( pt[i].x == pt[i+1].x && pt[i].y == pt[i+1].y ) break;
		} while ( i < N-1 );
		for ( i = 0; i < N; i++ ) {
			j = rand() % ( N - i );
			dep = pt[ i ]; pt[ i ] = pt[ j ]; pt[ j ] = dep;	
		}
			
		for ( i = 0; i < N; i++ )
			printf( "%d %d\n", pt[i].x, pt[i].y );
	}

	return 0;
	
}

