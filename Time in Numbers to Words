import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    
    // Complete the timeInWords function below.
    static String timeInWords(int h, int m) {
        Map <Integer,String> map = new HashMap<Integer,String>();
        map.put(new Integer(1) , "one") ;
        map.put(new Integer(2) , "two") ;
        map.put(new Integer(3) , "three") ;
        map.put(new Integer(4) , "four") ;
        map.put(new Integer(5) , "five") ;
        map.put(new Integer(6) , "six") ;
        map.put(new Integer(7) , "seven") ;
        map.put(new Integer(8) , "eight") ;
        map.put(new Integer(9) , "nine") ;
        map.put(new Integer(10) , "ten") ;
        map.put(new Integer(11) , "eleven") ;
        map.put(new Integer(12) , "twelve") ;
        map.put(new Integer(13) , "thirteen") ;
        map.put(new Integer(14) , "fourteen") ;
        map.put(new Integer(15) , "quarter") ;
        map.put(new Integer(16) , "sixteen") ;
        map.put(new Integer(17) , "seventen") ;
        map.put(new Integer(18) , "eighteen") ;
        map.put(new Integer(19) , "nineteen") ;
        map.put(new Integer(20) , "twenty") ;
        map.put(new Integer(21) , "twenty one") ;
        map.put(new Integer(22) , "twenty two") ;
        map.put(new Integer(23) , "twenty three") ;
        map.put(new Integer(24) , "twenty four") ;
        map.put(new Integer(25) , "twenty five") ;
        map.put(new Integer(26) , "twenty six") ;
        map.put(new Integer(27) , "twenty seven") ;
        map.put(new Integer(28) , "twenty eight") ;
        map.put(new Integer(29) , "twenty nine") ;
        map.put(new Integer(30) , "half") ;
        String time_in_words = "" ;
        if ( m == 0 ) {
            time_in_words += map.get(new Integer(h)) ;
            time_in_words += " o' clock" ;
            return time_in_words ;
        }
        if ( m == 1 ) {
            time_in_words += "one minute past " + map.get(new Integer(h)) ;
            return time_in_words ;
        }
        if ( m == 30 ) {
            time_in_words += "half past " ;
            time_in_words = time_in_words + map.get(new Integer(h)) ;
            return time_in_words ;
        }
        if ( m == 15 ) {
            time_in_words += "quarter past " ;
            time_in_words = time_in_words + map.get(new Integer(h)) ;
            return time_in_words ;
        }
        if ( m < 30 ) {
            time_in_words += map.get(new Integer(m)) + " minutes past " + map.get(new Integer(h)) ;
            return time_in_words ;
        }
        m = 60 - m ;
        if ( h == 12 ) {
            if ( m == 15 ) {
                time_in_words += "quarter to one" ;
            }
            else if ( m == 1 ) {
                time_in_words += "one minute to one" ;
            }
            else {
            time_in_words += map.get(new Integer(m)) + " minutes to one" ;
            }
            return time_in_words ;
        }
        if ( m == 15 ) {
                time_in_words += "quarter to " + map.get(new Integer(h+1));
                return time_in_words ;
            }
        if ( m == 1 ) {
            time_in_words += "one minute to " + map.get(new Integer(h+1)) ;
            return time_in_words ;
        }
        time_in_words += map.get(new Integer(m)) + " minutes to " + map.get(new Integer(h+1));
        return time_in_words ;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int h = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = timeInWords(h, m);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
