/* 
Given: A 2-D matrix of numbers 
        2 co-ordinates - ( top_left_row, top_left_column ) and ( bottom_right_row , bottom_right_column ) 
To do: Find the sum of all elements within the specified co-ordinate limits
*/

import java.util.* ;
import java.io.* ;

class sub_matrix_sum {
  public static int ROWS_OF_ORIGINAL = 7 ;
  public static int  COLUMNS_OF_ORIGINAL = 7 ;

  public static int matrix[][] = {
                      { 4 , 6 , 1 , 2 , 9 , 3 , 7 } ,
                      { 0 , 4 , 3 , 11 , 8 , 10 , 20 } ,
                      { 3 , 2 , 9 , 8 , 12 , 19 , 14 } ,
                      { 20 , 100 , 1 , 1 , 2 , 9 , 8 } ,
                      { 4 , 3 , 11 , 12 , 13 , 14 , 18 } ,
                      { 9 , 2 , 0 , 0 , 20 , 31 , 40 } ,
                      { 75 , 12 , 14 , 13 , 7 , 16 , 44 }
                    } ;
  public static int DP_MATRIX[][] = new int[ ROWS_OF_ORIGINAL + 1 ][ COLUMNS_OF_ORIGINAL + 1 ] ;

  public static void initialise () {
      for ( int itr = 0 ; itr <= ROWS_OF_ORIGINAL  ; itr ++ ) {
        DP_MATRIX[itr][0] = 0 ;
      }
      for ( int itr = 0 ; itr <= COLUMNS_OF_ORIGINAL ; itr ++ ) {
        DP_MATRIX[0][itr] = 0 ;
      }
      for ( int itr = 1 ; itr  <= ROWS_OF_ORIGINAL ; itr ++ ) {
        for ( int jtr = 1 ; jtr <= COLUMNS_OF_ORIGINAL ; jtr++ ) {
          DP_MATRIX[itr][jtr] = DP_MATRIX[itr][jtr - 1] + DP_MATRIX[itr - 1][jtr] - DP_MATRIX[itr - 1][jtr - 1] + matrix[itr - 1][jtr - 1] ;
        }
      }
  }

  public static int find_sum ( int top_left_row , int top_left_column , int bottom_right_row , int bottom_right_column ) {
    return  DP_MATRIX[bottom_right_row+1][bottom_right_column+1] - ( DP_MATRIX[bottom_right_row+1][top_left_column] + DP_MATRIX[top_left_row][bottom_right_column+1] - DP_MATRIX[top_left_row][top_left_column] )  ;
  }

  public static void main ( String args[] ) {
    initialise () ;
    System.out.println("Sum between ( 1 , 3 ) and ( 4 , 5 ) = " + find_sum ( 1 , 3 , 4 , 5 ) );
    System.out.println("Sum between ( 3 , 0 ) and ( 5 , 3 ) = " + find_sum ( 3 , 0 , 5 , 3 ) );
    System.out.println("Sum between ( 1 , 2 ) and ( 4 , 3 ) = " + find_sum ( 1 , 2 , 4 , 3 ) );
    System.out.println("Sum between ( 3 , 3 ) and ( 6 , 3 ) = " + find_sum ( 3 , 3 , 6 , 3 ) );
    System.out.println("Sum between ( 0 , 2 ) and ( 5 , 6 ) = " + find_sum ( 0 , 2 , 5 , 6 ) );
    System.out.println("Sum between ( 4 , 2 ) and ( 5 , 4 ) = " + find_sum ( 4 , 2 , 5 , 4 ) );
  }
}
