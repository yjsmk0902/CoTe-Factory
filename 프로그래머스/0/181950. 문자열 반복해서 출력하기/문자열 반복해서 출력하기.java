import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String value = st.nextToken();
        IntStream.range(0, Integer.parseInt(st.nextToken())).mapToObj(i -> value).forEach(System.out::print);

        br.close();
    }
}