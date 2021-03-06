class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0 ;
        for ( int i : nums ) {
            sum += i ;
        }
        int left_sum = 0 ;
        for ( int itr = 0 ; itr < nums.length ; itr += 1 ) {
            if ( left_sum == ( sum - nums[itr] ) ) {
                return itr ;
            }
            left_sum += nums[itr] ;
            sum -= nums[itr] ;
        }
        return -1 ;
    }
}
