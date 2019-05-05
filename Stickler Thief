/*

Stickler is a thief and wants to loot money from a society of n houses placed in a line. He is a weird person and follows a rule while looting the houses and according to the rule he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to find the maximum amount he can end up with. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains an integer n which denotes the number of elements in the array a[]. Next line contains space separated n elements in the array a[].

Output:
Print an integer which denotes the maximum amount he can take home.

Constraints:
1<=T<=200
1<=n<=1000
1<=a[i]<=10000

Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3

Output:
110
4

*/
#include <stdio.h>
#include <stdlib.h>
int main(){
  int no_of_testcases , t , array_size , i , excluded = 0 ;
  int temp_excluded = 0 , included = 0 , tempo ;
  scanf ( "%d" , &no_of_testcases ) ;
  int *output = ( int* ) malloc ( no_of_testcases * sizeof( int ) ) ;
  // Test Case Loop Starts
  for ( t = 0 ; t < no_of_testcases ; t ++ ) {
    scanf ( "%d" , &array_size ) ;
    // Input Array Loop Starts
    int *array = ( int* ) malloc ( array_size * sizeof( int ) ) ;
    excluded = 0 ; included = 0 , temp_excluded = 0 ;
    for ( i = 0 ; i < array_size ; i ++ ){
      scanf ( "%d" , &array[i] ) ;
      if ( array[i] + excluded >= included ){
        tempo = included ;
        included = array[i] + excluded ;
        excluded = tempo ;
        temp_excluded = excluded ;
          }
          else{
            temp_excluded += array[i] ;
            excluded = included ;
          }
    }
    output[t] = included ;
    // Input Array Loop Ends
    free(array);
  }
  // Test Case Loop Ends
  for ( t = 0 ; t < no_of_testcases ; t ++ ) {
    printf ( "%d\n" , output[t]);
  }
  return 0;
}
