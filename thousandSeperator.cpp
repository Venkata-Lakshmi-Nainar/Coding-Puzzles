/*
https://leetcode.com/problems/thousand-separator/

Given an integer n, add a dot (".") as the thousands separator and return it in string format.

Example 1:
Input: n = 987
Output: "987"

Example 2:
Input: n = 1234
Output: "1.234"

Example 3:
Input: n = 123456789
Output: "123.456.789"

Example 4:
Input: n = 0
Output: "0"

Constraints:
0 <= n < 2^31
*/

class Solution {
public:
    string thousandSeparator(int n) {
     if ( n == 0 ) {
        return to_string(n) ;
    }
    bool IsNegative = false ;
    if ( n < 0 ) {
        IsNegative = true ;
        n = abs(n) ;
    }
    string number = "" ;
    while ( n > 0 ) {
        unsigned int itr = 3 ;
        while ( n > 0 && itr > 0 ) {
            number = to_string(n%10) + number ;
            n = n / 10 ;
            itr -= 1 ;
        }
        if ( n > 0 ) {
            number = '.' + number ;
        }
    }
    if ( IsNegative == true ) {
        number = '-' + number ;
    }
    return number ;
    }
};
