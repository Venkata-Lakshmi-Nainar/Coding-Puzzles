#include <stdio.h>
#include <stdlib.h>

void check_consecutive ( int input[] , int size ) {
  int i , j , max = 0 , count , flag , next_index, start_max ;
  int plus_one[size] , minus_one[size] ;
  for ( i = 0 ; i < size ; i ++ ) {
    plus_one[i] = size ;
    minus_one[i] = -1 ;
  }
  for ( i = 0 ; i < size ; i ++ ) {
    for ( j = i + 1 ; j < size ; j++ ) {
      flag = 0 ;
      if ( input[j] == input[i] + 1 ) {
        plus_one[i] = j ;
        flag = 1 ;
        break ;
      }
    }
    if ( flag == 0 ) {
      for ( j = i - 1 ; j >= 0 ; j --){
        if ( input[j] == input[i] + 1 ) {
          plus_one[i] = j ;
          break;
        }
      }
    }
    flag = 0 ;
    for ( j = i + 1 ; j < size ; j ++ ) {
      if ( input[j] == input[i] - 1 ) {
        minus_one[i] = j ;
        flag = 1 ;
      }
    }
    if ( flag == 0 ) {
      for ( j = i - 1 ; j >= 0 ; j -- ) {
        if ( input[j] == input[i] - 1 ) {
          minus_one[i] = j ;
          break ;
        }
      }
    }
  }
  for ( i = 0 ; i < size ; i++ ) {
    if ( minus_one[i] < 0 ) {
      next_index = plus_one[i];
      count = 1 ;
      while ( next_index < size ) {
        next_index = plus_one[next_index] ;
        count += 1 ;
      }
      if ( max < count ) {
        max = count ;
        start_max = i ;
      }
    }
  }
  next_index = start_max ;
  while ( next_index < size ) {
    printf("%d ", input [ next_index ] );
    next_index = plus_one [ next_index ] ;
  }
}

int main(int argc, char const *argv[]) {
  int input[] = { 87, 42 , 100 , 38 , 7 , 1 , 29 , 45 , 90 , 39 , 67, 30 , 44 , 51 , 41 , 8 , 67 , 40  , 89 , 38 , 43 } ;
  int size = sizeof(input) / sizeof(input[0]) ;
  check_consecutive ( input , size ) ;
  return 0;
}
