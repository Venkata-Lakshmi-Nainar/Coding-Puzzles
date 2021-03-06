class Solution {
    public int[] sortArrayByParity(int[] A) {
        int jtr = A.length - 1 , itr = 0 ;
        while ( jtr > itr ) {
            if ( A[itr] % 2 > 0 && A[jtr] % 2 == 0 ) {
                int temp = A[jtr] ;
                A[jtr] = A[itr] ;
                A[itr] = temp ;
                jtr -= 1 ;
                itr += 1 ;
            }
            
            if ( A[itr] % 2 == 0 ) {
                itr += 1 ;
            }
            if ( A[jtr] % 2 > 0 ) {
                jtr -= 1 ;
            }
        }
        return A ;
    }
}
