class Solution {
    public String addStrings(String num1, String num2) {
        String result ="" ;
        int carry = 0 ;
        int len1 = num1.length() , len2 = num2.length() ;
        int itr = len1 - 1 , jtr = len2 - 1 ;
        while ( itr >= 0 && jtr >=0 ) {
            int sum = Character.getNumericValue(num1.charAt(itr)) + Character.getNumericValue(num2.charAt(jtr)) + carry ;
            carry = sum / 10 ;
            sum %= 10 ;
            result = (char)(sum + '0') + result ;
            itr -= 1 ; jtr -= 1 ;
        }
        while ( itr < 0 && jtr >= 0 ) {
            int sum = Character.getNumericValue(num2.charAt(jtr)) + carry ;
            carry = sum / 10 ;
            sum %= 10 ;
            result = (char)(sum + '0') + result ;
            jtr -= 1 ;
        }
        while ( jtr < 0 && itr >= 0 ) {
            int sum = Character.getNumericValue(num1.charAt(itr)) + carry ;
            carry = sum / 10 ;
            sum %= 10 ;
            result = (char)(sum + '0') + result ;
            itr -= 1 ;
        }
        if ( carry > 0 ) {
            result = (char)(carry + '0') + result ;
        }
        return result ;
    }
}
