import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        System.out.println("a = "+ stringTokenizer.nextToken());
        System.out.println("b = "+ stringTokenizer.nextToken());
        
        bufferedReader.close();
    }
}