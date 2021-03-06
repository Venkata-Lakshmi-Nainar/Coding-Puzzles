/*
https://open.kattis.com/problems/tutorial
*/

import java.util.* ;

public class ICPCTutorial_0403{

  public static String factorial ( int M , int N ) {
    if ( N > M ) {
      return "TLE" ;
    }
    int fact = 1 ;
    while ( N > 0 ) {
      if ( M < ( fact * N ) ) {
        return "TLE" ;
      }
      fact *= N ;
      N -= 1 ;
    }
    return "AC" ;
  }

  public static String Program_Result ( int M, int N, int T ) {
    switch (T) {
      case 1 :
        return factorial ( M , N ) ;

      case 2 :
        if ( M >= Math.pow ( 2 , N ) ) {
          return "AC" ;
        }
        break ;

      case 3 :
        if ( M >= Math.pow ( N , 4 ) ) {
          return "AC" ;
        }
        break ;

      case 4 :
        if ( M >= Math.pow ( N , 3 ) ) {
          return "AC" ;
        }
        break ;

      case 5 :
        if ( M >= Math.pow ( N , 2 ) ) {
          return "AC" ;
        }
        break ;

      case 6 :
        if ( ( N * ( Math.log(N) / Math.log(2) ) - M ) < 0 ){
          return "AC" ;
        }
        break ;

      case 7 :
        if ( M >= N ) {
          return "AC" ;
        }
        break ;
      default:

    }
    return "TLE" ;
  }

  public static void main(String[] args) {
    Scanner input  = new Scanner ( System.in ) ;
    int M = input.nextInt() ;
    int N = input.nextInt() ;
    int T = input.nextInt() ;
    System.out.println ( Program_Result ( M , N , T ) ) ;
  }
}
/*

ACM-ICPC returns to Singapore in 2015 after a long absence. There may be new contestants from this region who are joining ACM-ICPC for the very first time. This problem serves as a tutorial for such contestants.

First, let establish the fact that the problems posed in ICPC are not research problems where nobody on earth knows how to solve them efficiently. Some people (at least the problem authors) have solved these problems before. There can be more than one possible solution to these problems. As the contest has limited time (5 hours) and each problem has an associated time penalty, it is always beneficial to pick the easiest problem to solve first2.

Some problems may look complicated but happen to have a small input size constraint n that allows even a naïve brute force solution to pass. Some other problems may look simple but standard textbook algorithm cannot be used to pass the time limit as the input size constraint n is too big and one has to figure out the special properties that simplify the problem.

In the “Competitive Programming” book3 that has been written specifically for preparing for programming contests such as ICPC, we have the following compilation of typical algorithm complexities found in programming contests:

t = 1

Algorithm complexity for input size n: O(n!)

t = 2

Algorithm complexity for input size n: O(2n)

t = 3

Algorithm complexity for input size n: O(n4)

t = 4

Algorithm complexity for input size n: O(n3)

t = 5

Algorithm complexity for input size n: O(n2)

t = 6

Algorithm complexity for input size n: O(nlog2n)

t = 7

Algorithm complexity for input size n: O(n)

For this problem, we ignore the constant factor and the lower terms hidden in the Big O notation, i.e. an O(g(n)) algorithm is assumed to perform exactly g(n) operations.

Let m be the number of operations that the computer used in the contest4 can run in one second. Suppose m=100000000 and the team is trying to solve a problem with a time limit of one second. If the team can devise an algorithm of type t=3, i.e., a rather slow O(n4) algorithm, but the largest n mentioned in the problem description is just 50, then this algorithm is actually fast enough and will get “Accepted” since 504=6250000 is less than (or equal to) m.

However, if for another problem also with one second time limit, the team can only devise an algorithm of type t=5, i.e. an O(n2) algorithm, but the largest n mentioned in the problem description is 10001, then this algorithm is likely not fast enough to pass the time limit and will get “Time Limit Exceeded”, since 100012=100020001 which is greater than m.


Formally, given three integer parameters m (1≤m≤109), n (1≤n≤109), and t∈[1..7], decide if an algorithm of type t with time complexity as described in the table above can pass the time limit of one second, that is, performs less than (or equal to) m operations. Output “AC” (that stands for “Accepted”) if that is the case, or “TLE” (that stands for “Time Limit Exceeded”) otherwise.

Input
The input consists of three integers in one line: m, n, and t as elaborated above.

Output
Output a single string “AC” or “TLE” in one line as elaborated above.

Sample Input 1
100000000 500 3

Sample Output 1
TLE

Sample Input 2
100000000 50 3

Sample Output 2
AC

Sample Input 3
100000000 10001 5

Sample Output 3
TLE

Sample Input 4
100000000 10000 5

Sample Output 4
AC

Sample Input 5
19931568 1000000 6

Sample Output 5
TLE

Sample Input 6
19931569 1000000 6

Sample Output 6
AC
*/
