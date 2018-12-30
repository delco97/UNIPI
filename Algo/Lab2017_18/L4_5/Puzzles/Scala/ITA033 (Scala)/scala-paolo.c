
#include <stdio.h>

#define MAXN	100000

typedef struct { int x,y; } punto;
punto a[MAXN];
int N;

/* Confronto fra punti. Definiamo una relazione <= fra punti, ponendo p<=q se
   p.y<q.y o (p.y==q.y e p.x<q.x). Questa funzione restituisce un valore
   negativo se p<q, positivo se p>q, nullo se p==q. */
int comp( punto *p, punto *q ) {
	int c = p->y-q->y;
	if ( c ) return c;
	return p->x-q->x;
}

void heapify( int i, int up ) {
	int child;
	punto dep;
	while ( ( child = 2*i+1 ) < up ) {
		if ( child+1 < up && comp( &a[child], &a[child+1] ) < 0 ) child++;
		if ( comp( &a[i], &a[child] ) >= 0 ) break;
		dep = a[child]; a[child] = a[i]; a[i] = dep;
		i = child;
	}
}

void read() {
	int i;
	FILE *f = stdin; //fopen( "input.txt", "r" );
	
	fscanf( f, "%d", &N );
	for ( i = 0; i < N; i++ )
		fscanf( f, "%d %d", &a[i].x, &a[i].y );
	fclose( f );
}

void write( int area ) {
	FILE *f = stdout; //fopen( "output.txt", "w" );
	
	fprintf( f, "%d\n", area );
	fclose( f );
}


int main() {
	int i, lastx, area;
	
	read();
	for ( i = N/2; i >= 0; i-- )
		heapify( i, N );
		
	area = lastx = 0;
	for ( i = N-1; i >= 0; i-- ) {
		if ( a[0].x > lastx ) {
			area += ( a[0].x - lastx ) * a[0].y;
			lastx = a[0].x;
		}
		a[0] = a[i];
		heapify( 0, --N );
	}
	
	write( area );	
	return 0;
	
}

