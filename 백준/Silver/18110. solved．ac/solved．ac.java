import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    private static long n;
    private static List<Integer> score = new ArrayList<>();
    private static int exceptedNum;
    private static int sum;
    private static int calculateNum;

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());

        if (n == 0) {
            sb.append(0);
            System.out.println(sb);
            return;
        }

        for (int i = 0; i < n; i++) {
            score.add(Integer.parseInt(br.readLine()));
        }

        Collections.sort(score);

        exceptedNum = (int) Math.round(n * 0.15);
        calculateNum = (int) (n - exceptedNum * 2);

        for (int i = 0; i < calculateNum; i++) {
            sum += score.get(i + exceptedNum);
        }

        sb.append(Math.round((double) sum / (double) calculateNum));
        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}