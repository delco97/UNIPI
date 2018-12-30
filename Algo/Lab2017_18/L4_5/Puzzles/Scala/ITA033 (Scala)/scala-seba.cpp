#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#define MAXN 10000

int p[MAXN][2];

int cmp( const void *a, const void *b ) {
  const int *A = (const int *)a;
  const int *B = (const int *)b;

  int d = B[ 1 ] - A[ 1 ];
  if ( d ) return d;
  return B[ 0 ] - A[ 0 ];
}

int main() {

  int N, i, last, A = 0;

  cin >> N;

  for( i = 0; i < N; i++ ) cin >> p[ i ][ 0 ] >> p[ i ][ 1 ];

  qsort( p, N, sizeof *p, cmp );

  i = last = 0;
  A = p[ 0 ][ 0 ] * p[ 0 ][ 1 ];

  for(;;) {
    while( p[ i ][ 0 ] <= p[ last ][ 0 ] && i < N ) i++;
    if ( i == N ) break;
    A += ( p[ i ][ 0 ] - p[ last ][ 0 ] ) * p[ i ][ 1 ];
    last = i;
  }

  cout << A << endl;
  return 0;
}
