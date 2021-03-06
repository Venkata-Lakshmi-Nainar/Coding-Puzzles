#include <bits/stdc++.h>
using namespace std ;

bool check_if_unique ( char array[] , unsigned int len ) {
  if ( len < 1 )
      return false  ;
  unsigned int i = 0 , status = 0x00 ;
  cout << array <<"\n" ;
  while ( i < len ) {
    cout << status << "\n" ;
    cout << array[i] <<"\n" ;
    if ( ( ( 0x01 << ( array[i] - 'a' ) ) & status ) > 0 )
        return false ;
    status |= 0x01 << ( array[i] - 'a' ) ;
    i += 1 ;
  }
  return true ;
}

int main(int argc, char const *argv[]) {
  char word[] = "uncopyrightable" ;
  check_if_unique ( word , strlen(word) ) ? cout << "Unique" :
                                            cout << "Not Unique" ;
  return 0;
}
