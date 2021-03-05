/*

Above Average

It is said that 90% of frosh expect to be above average in their class. You are to provide a reality check.
Input
The first line of standard input contains an integer 1≤C≤50, the number of test cases. C data sets follow. Each data set begins with an integer, N, the number of people in the class (1≤N≤1000). N integers follow, separated by spaces or newlines, each giving the final grade (an integer between 0 and 100) of a student in the class.

Output
For each case you are to output a line giving the percentage of students whose grade is above average, rounded to exactly 3 decimal places.

Sample Input 1
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

Sample Output 1
40.000%
57.143%
33.333%
66.667%
55.556%

*/
#include<bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[]) {
  unsigned int C, N ;
  cin >> C ;
  while ( C -- ) {
    cin >> N ;
    unsigned int sum = 0 ;
    unsigned int count = 0 ;
    unsigned int arr[N] ;
    for ( unsigned int itr = 0 ; itr < N ; itr += 1 ) {
      cin >> arr[itr] ;
      sum += arr[itr] ;
    }
    float average = ( float )( sum / N ) ;

    for ( unsigned int itr = 0 ; itr < N ; itr += 1 ) {
      if ( arr[itr] > average ) {
        count += 1 ;
      }
    }
    float temp = ( ( float )count* 100 ) / N ;
    cout << fixed << setprecision(3) << temp << "%" << endl ;
  }
  return 0;
}
