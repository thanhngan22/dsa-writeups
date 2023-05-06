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
     * Complete the 'commonChild' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. STRING s1
     *  2. STRING s2
     */

    public static int _commonChild(String s1, String s2) {
    // Write your code here
    ArrayList<Integer> counts = new ArrayList<Integer>();
    for (int i = 0; i < s1.length(); i++) {
        int count = 0;
        
        int k = i;
        int j = 0;
        int prev = -1;
        while (true) {
            for ( j = prev + 1; j < s2.length() ; j++ ) {
                if (s1.charAt(k) == s2.charAt(j)) {
                    count++;
                    prev = j;
                    break;
                }
            }
            if (count == 0) {
                break;
            } 
            k++;
            if (k >= s1.length()) {
                break;
            }
        }
        
        counts.add(count);
        System.out.println(s1.charAt(i) + " " +  count);
    }
    int max = Collections.max(counts);
    return max;

    }
    
    public static int commonChild(String s1, String s2) {
        int[][] dp = new int[s1.length()+1][s2.length()+1];

        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[s1.length()][s2.length()];
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s1 = bufferedReader.readLine();

        String s2 = bufferedReader.readLine();

        int result = Result.commonChild(s1, s2);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
