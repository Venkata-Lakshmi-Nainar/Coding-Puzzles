#include<bits/stdc++.h>
using namespace std;
/* Return the length of largest bitonic sequence */

unsigned int maximum ( unsigned int A , unsigned int B ) {
    return A > B ? A : B ;
}

unsigned int LongestBitonicSequence ( unsigned int A[] , unsigned int N ) {
    unsigned int *Increasing = new unsigned int [N] ;
    unsigned int *Decreasing = new unsigned int [N] ;
    unsigned int length = 1 ;
    for ( unsigned int itr = 0 ; itr < N ; itr += 1 ) {
        Increasing[itr] = 1 ;
        Decreasing[itr] = 1 ;
    }
    /* Find the longest Increasing Subsequence and Longest Decreasing Sequences*/
    for ( unsigned int itr = 1 ; itr < N ; itr += 1 ) {
        for ( unsigned int jtr = 0 ; jtr < itr ; jtr += 1 ) {
            if ( A[jtr] < A[itr] ) {
                Increasing[itr] = maximum ( Increasing[itr] , Increasing[jtr] + 1 ) ;
            }
            if ( A[N-1-itr] > A[N-1-jtr] ) {
                Decreasing[N-1-itr] = maximum ( Decreasing[N-1-itr] , Decreasing[N-1-jtr] + 1 ) ;
            }
        }
    }
    for ( unsigned int itr = 0 ; itr < N ; itr += 1 ) {
        length = maximum ( length , Increasing[itr] + Decreasing[itr] - 1 ) ;
    }
    return length ;
}

int main()
 {
	unsigned int no_of_testcases ;
	cin >> no_of_testcases ; /*Input the Number of Testcases*/
	while ( no_of_testcases -- ) {
	    unsigned int N ;
	    cin >> N ; /* Get the size of array */
	    unsigned int arr[N] ;
	    for ( unsigned int itr = 0 ; itr < N ; itr ++ ) {
	        cin >> arr[itr] ; /* Get each array element */
	    }
	    cout << LongestBitonicSequence(arr,N) << endl ;
	}
	return 0;
}
