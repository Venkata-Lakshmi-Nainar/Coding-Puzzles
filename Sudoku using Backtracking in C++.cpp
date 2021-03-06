#include <bits/stdc++.h>
using namespace std ;
#define GRID_SIZE 9

/* Function to print the Grid */
void print( int puzzle[GRID_SIZE][GRID_SIZE]) {
  for ( unsigned int i = 0 ; i < GRID_SIZE ; i++ ){
    for ( unsigned int j = 0 ; j < GRID_SIZE ; j++ ) {
      cout << puzzle[i][j] << " " ;
    }
    cout << "\n" ;
  }
}

/*Function to check if Sudoku is complete */

bool Is_Sudoku_Full ( int sudoku[GRID_SIZE][GRID_SIZE] ) {
  for ( int i = 0 ; i < GRID_SIZE ; i++ ) {
    for ( int j = 0 ; j < GRID_SIZE ; j ++ ) {
      if ( sudoku[i][j] < 1 ) {
        return false ;
      }
    }
  }
  return true ;
}

/*Function to check if the given Sudoku is valid */

bool check_sudoku ( int sudoku[GRID_SIZE][GRID_SIZE] ) {
  unsigned int r , c , temp , count , status ;

  /* Block to check for duplicates in individual rows */
  for ( r = 0 ; r < GRID_SIZE ; r ++ ) {
    status = 0x00 ;
    for ( c = 0 ; c < GRID_SIZE ; c++ ) {
      if ( sudoku[r][c] <= 0 ) {
        continue ;
      }
      if ( ( status & ( 0x01 << ( GRID_SIZE - sudoku[r][c] ) ) ) > 0  ) {
        return false ;
      }
      status |= 0x01 << ( GRID_SIZE - sudoku[r][c] ) ;

    } //end for
  } //end for

  /* Block to check for duplicates in individual columns */
  for ( c = 0 ; c < GRID_SIZE ; c ++ ) {
    status = 0x00 ;
    for ( r = 0 ; r < GRID_SIZE ; r ++ ) {
      if ( sudoku[r][c] <= 0 ) {
        continue ;
      }
      if ( ( status & ( 0x01 << ( GRID_SIZE - sudoku[r][c] ) ) ) > 0  ) {
        return false ;
      }
      status |= 0x01 << ( GRID_SIZE - sudoku[r][c] ) ;

    } //end for
  } //end for

  /* Block to check for duplicates in individual 3x3 grid */
  for ( count = 0 ; count < GRID_SIZE ; count = count + 3 ) {
    for ( temp = 0 ; temp < GRID_SIZE ; temp = temp + 3 ) {
      status = 0x00 ;
      for ( r = count ; r < count + 3 ; r ++ ) {
        for ( c = temp ; c < temp + 3 ; c ++ ) {
          if ( sudoku[r][c] <= 0 ) {
            continue ;
          }
          if ( ( status & ( 0x01 << ( GRID_SIZE - sudoku[r][c] ) ) ) > 0  ) {
            return false ;
          }
          status |= 0x01 << ( GRID_SIZE - sudoku[r][c] ) ;
        } // end for c
      } //end for r
    }// end for temp
  } //end for count
  return true ;
} // end check_sudoku

bool solve_sudoku ( int sudoku[GRID_SIZE][GRID_SIZE] , int row_bound , int column_bound ) {
  /* To check if incoming sudoku is valid */
  if ( !check_sudoku ( sudoku ) ) {
    return false ;
  }
  if ( Is_Sudoku_Full ( sudoku ) ) {
    return true ;
  }
  /* To find the vacant space ( indicated by 0 ) */
  unsigned int r ,c ;
  unsigned int row_pos , col_pos ;
  for ( r = row_bound ; r < GRID_SIZE ; r ++ ) {
    for ( c = column_bound ; c < GRID_SIZE ; c++ ) {
      if ( sudoku[r][c] < 1 ) {
        row_pos = r ; col_pos = c ;
        r = GRID_SIZE ; c = GRID_SIZE ;
      }
    }
    column_bound = 0 ;
  } // end for r

  // To represent all elements in corresponding column and row of the found vacant space using bits
  unsigned int status_row = 0x00 , status_column = 0x00 ;

  /* Code to set all bits */

  for ( c = 0 ; c < GRID_SIZE ; c ++ ) {
    if ( sudoku[row_pos][c] > 0 ) {
    status_row |= ( 0x01 << ( GRID_SIZE - sudoku[row_pos][c] ) ) ;
    }
  }
  for ( r = 0 ; r < GRID_SIZE ; r ++ ) {
    if ( sudoku[r][col_pos] > 0 ) {
    status_column |= ( 0x01 << ( GRID_SIZE - sudoku[r][col_pos] ) ) ;
    }
  }
  /* To find the unused numbers and build new Sudoku grid */

  for ( int k = 1 ; k <= GRID_SIZE ; k++ ) {
    if ( ( ( status_row | status_column ) & ( 01 << ( GRID_SIZE - k ) ) ) > 0 ) {
      continue ;
    }
    sudoku[row_pos][col_pos] = k ;
    if ( solve_sudoku ( sudoku , row_pos , col_pos ) ) {
      return true ;
    }
  } //end for
  sudoku[row_pos][col_pos] = 0 ;
  return false ;
} //end solve_sudoku()

int main(int argc, char const *argv[]) {
  int grid[GRID_SIZE][GRID_SIZE] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
if ( solve_sudoku ( grid , 0 , 0 ) == true ) {
  cout << "Puzzle Solved\n" ;
    print(grid) ;
  }else {
  cout << "Not Solvable\n" ;
 }
  return 0;
}
