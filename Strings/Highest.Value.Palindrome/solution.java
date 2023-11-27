// https://www.hackerrank.com/challenges/richie-rich/problem

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;
 
class Result {

    /*
     * Complete the 'highestValuePalindrome' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING s
     *  2. INTEGER n
     *  3. INTEGER k
     */
    public static int countDiff(String s) {
        int n = 0;
        int len = s.length();
        for (int i = 0; i < len/2; i++) {
            if (s.charAt(i) != s.charAt(len - 1 - i)) {
                n++;
            }
        }
        return n;
    }
    
    public static String convert(String str, int k, int index) {
        char[] chars = str.toCharArray();
        int len = str.length();
        int count = 0;
        for (int i = index; i < len/2; i++ ) {
            if (chars[i] != chars[len - 1 - i]) {
                if (chars[i] > chars[len - 1 - i] ) {
                    chars[len-1-i] = chars[i] ;
                } else {
                     chars[i] = chars[len-1-i]; 
                }
                count++;
                if (count == k) {
                    break;
                }
            }
        }
        return String.copyValueOf(chars);  
    }
    

    public static String highestValuePalindrome(String s, int n, int k) {
    // Write your code here
        if (k >= n) {
            char[] arr = new char[n];
            Arrays.fill(arr, '9');
            return String.valueOf(arr);
        }
    
        int nDiff = countDiff(s);
        if (nDiff > k) {
            return "-1";
        }
        if (nDiff == k) {
            if (k == 0) {
                return s;
            }
            return convert(s, k, 0);
        }
        
        // k > nDiff
        char[] chars = s.toCharArray();
        
        int i = 0;
        // nDiff = 0 
        if (nDiff == 0 && k >= 1) {
            while (true) {
                if (k <= 1 || i == (int) n/2) {
                        if (k >= 1 && n % 2 == 1) {
                            chars[(n-1)/2] = '9';
                        }
                        return String.valueOf(chars);
                }
                if ((chars[i] != chars[n-1-i]) || (chars[i] == chars[n-1-i] && chars[i] != '9' )) {
                    chars[i] = '9';
                    chars[n-1-i] = '9';
                    k -= 2;
                    i++;

                } else {
                    i++;
                }
                
            }
        }
        
        // nDiff != 0 
        while (k > 0 && i < (int) n/2) {
            if (chars[i] != chars[n-1-i]) {
                if (chars[i] == '9' || chars[n-1-i] == '9') {
                    if (chars[i] != '9') {
                        chars[i] = '9';
                    } else {
                        chars[n-1-i] = '9';
                    }
                    k--;
                    nDiff--;
                    i++;
                    continue;
                }
                if (k > nDiff) {
                        chars[i] = '9';
                        chars[n-1-i] = '9';
                        k -= 2;
                        nDiff -= 1;
                        i++;
                } else {
                    if (chars[i] > chars[n-1-i]) {
                        chars[n-1-i] = chars[i];
                    } else {
                        chars[i] = chars[n-1-i];
                    }
                    nDiff--;
                    k--;
                    i++;
                }
                    
            } else if ( chars[i] != '9') {
                if (k - nDiff >= 2) {
                    chars[i] = '9';
                    chars[n-1-i] = '9';
                    k -= 2;
                    i++;
                }
 
            } else {
                i++;
            }
        }
        if (k > 0 && n % 2 == 1) {
            chars[(n-1)/2] = '9';
        }
        return String.valueOf(chars);
        
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int k = Integer.parseInt(firstMultipleInput[1]);

        String s = bufferedReader.readLine();

        String result = Result.highestValuePalindrome(s, n, k);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
