#include <stdio.h>
#include <stdlib.h>

int find(int matrix[50][50], int cr, int cc, int r, int c) {
    if ( ( cr < r && cr >= 0 ) && ( cc < c && cc >= 0 ) ) {
        return matrix[cr][cc];
    }
    return 0;
}

int findmax(int matrix[50][50], int r , int c , int l, int h, int size, int buff[50][50], int maxsize ) {
    int dir[8][2] , d , i , j ;
    int newi , newj , val ;
    dir[0][0] = 0 ; dir[0][1] = 1 ;
    dir[1][0] = 1 ; dir[1][1] = 1 ;
    dir[2][0] = 1 ; dir[2][1] = 0 ;
    dir[3][0] = 1 ; dir[3][1] = -1 ;
    dir[4][0] = 0 ; dir[4][1] = -1;
    dir[5][0] = -1 ; dir[5][1] = -1 ;
    dir[6][0] = -1 ; dir[6][1] = 0 ;
    dir[7][0] = -1 ; dir[7][1] = 1 ;
    if ( r >= l || c >= h ) {
        return 0;
    }
    buff[r][c] = 1 ;

    size += 1 ;
    if ( maxsize < size ) {
        maxsize = size ;
    }
    for ( d = 0 ; d < 8 ; d ++ ) {
       newi = r + dir[d][0] ;
       newj = c + dir[d][1] ;
       val = find ( matrix , newi , newj , l , h ) ;
       if ( val > 0 ){
                if ( buff[newi][newj] != 1 ) {
           size = findmax ( matrix , newi , newj , l , h , size , buff , maxsize );
       }
       if ( maxsize < size ) {
           maxsize = size ;
       }
    }
}
    return maxsize;
}

int getmax() {
       int maxsize = 0 , size = 0 , rmax , cmax , i , j ;
       scanf("%d", &rmax );
       scanf("%d", &cmax );
       if ( ( rmax > 50 || rmax < 1 ) || ( cmax > 50 || cmax < 1 ) ) {
         exit(1) ;
       }
       int matrix[rmax][cmax] , buffer[rmax][cmax] ;
       for ( i = 0 ; i < rmax ; i ++ ) {
           for ( j = 0 ; j < cmax ; j ++ ) {
               scanf("%d",&matrix[i][j]) ;
               buffer[i][j] = 0 ;
           }
       }
       for ( i = 0 ; i < rmax ; i ++ ) {
           for ( j = 0 ; j < cmax ; j ++ ) {
             if ( matrix[i][j] > 0 ) {
               size = findmax ( matrix , i , j , rmax , cmax , 0 , buffer , maxsize ) ;
             }
             if ( maxsize < size ) {
                 maxsize = size ;
             }
           }
    }
    return maxsize ;
}

int main() {
	int no_of_testcases , t ;
	scanf ( "%d" , &no_of_testcases) ;
  if (no_of_testcases < 1 || no_of_testcases > 100 ){
     exit(1) ;
   }
    int output[no_of_testcases] ;
	for ( t = 0 ; t < no_of_testcases ; t ++ ) {
	    output[t] = getmax();
	}
	for ( t = 0 ; t < no_of_testcases ; t ++ ) {
	    printf ( "%d\n", output[t] ) ;
	}
	return 0;
}
