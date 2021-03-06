/*
Yraglac loves number sequences. One of his favourites is the classic Fibonacci numbers. He likes to set the base case as F0=F1=1 and Fn=Fn−1+Fn−2.

Now, one can only list out the same numbers so many times before getting bored, so Yraglac came up with a new game: if he took the sequence of Fibonacci numbers modulo some k, what is the index of the first number in the new sequence that gets repeated? Yraglac only considers numbers in the sequence starting from n=2 since F0=F1 is boring.

Can you write a program to help Yraglac find the answer?

Input
The first line contains a single integer 1≤Q≤500, the number of queries to follow.

The next Q lines each contain a single integer 2≤k≤1000, the modulo to be used for the query. It is guaranteed that some number in the sequence will be repeated.

Output
For each query, output the n such that Fn is the first number in the sequence of Fibonacci numbers modulo k that has a repeat at some point in the sequence.

Sample Input 1
3
4
13
22

Sample Output 1
4
5
8
*/
import java.util.* ;

public class FibonacciCycles_0404{

  public static void main(String[] args) {
    Scanner input = new Scanner ( System.in ) ;
    int Q = input.nextInt() ;
    while ( Q-- > 0 ) {
      int prev = 1, now = 2 , index = 2 ;
      int K = input.nextInt() ;
      int arr[] = new int[K];
      Arrays.fill ( arr , -1 ) ;
      while ( arr [ now % K ] == -1 ) {
        arr [ now % K ] = index ;
        int temp = ( prev + now ) % K ;
        prev = now % K ;
        now = temp ;
        index += 1 ;
        }
      System.out.println ( arr [ now % K ] ) ;
    }
  }
}
