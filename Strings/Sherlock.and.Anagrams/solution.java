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
     * Complete the 'sherlockAndAnagrams' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING s as parameter.
     */

    public static String sortedString(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return String.valueOf(chars);
    }

    public static int _sherlockAndAnagrams(String s) {
    // Write your code here
        // create an array contains all substr from s 
        Map<String, Integer> list = new HashMap<String, Integer>();
        for (int i = 0; i < s.length(); i++) {
            for (int len = 1; len < s.length() - i + 1; len++) {
                String temp = s.substring(i, i + len);
                String sortedS = sortedString(temp);
                if (list.get(sortedS) != null) {
                    list.put(sortedS, list.get(sortedS) + 1);
                } else {
                    list.put(sortedS, 1);
                }
            }
        }
        
        int total = 0;
        for (Map.Entry<String, Integer> entry : list.entrySet()){
            int value = entry.getValue();
            if (value >= 2) {
                total += value*(value-1)/2;
            }
        }
        
        return total;
         
    }
    
    // optimize
    public static int sherlockAndAnagrams(String s) {
    // Write your code here
        // create an array contains all substr from s 
        Map<String, Integer> list = new HashMap<String, Integer>();
        for (int i = 0; i < s.length(); i++) {
            for (int len = 1; len < s.length() - i + 1; len++) {
                String temp = s.substring(i, i + len);
                String sortedS = sortedString(temp);
                list.compute(sortedS, (k,v) -> v == null ? 1 : 1 + v);
            }
        }
        
        int total = 0;
        for (int value : list.values()){
            if (value >= 2) {
                total += value*(value-1)/2;
            }
        }
        
        return total;
         
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                String s = bufferedReader.readLine();

                int result = Result.sherlockAndAnagrams(s);

                bufferedWriter.write(String.valueOf(result));
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
