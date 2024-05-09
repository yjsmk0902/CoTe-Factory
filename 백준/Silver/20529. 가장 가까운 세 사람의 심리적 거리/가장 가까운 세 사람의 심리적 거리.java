import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static int T;
    private static int N;
    private static final List<String> MBTI = new ArrayList<>();
    private static final List<Integer> answers = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        input(reader);
        for (int i = 0; i < T; i++) {
            init(reader);
            solve();
        }
        answers.forEach(System.out::println);
    }

    public static void input(BufferedReader reader) throws IOException {
        T = Integer.parseInt(reader.readLine());
    }

    public static void init(BufferedReader reader) throws IOException {
        MBTI.clear();
        N = Integer.parseInt(reader.readLine());
        StringTokenizer st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < N; i++) {
            MBTI.add(st.nextToken());
        }
    }

    public static void solve() {
        if (N > 32) {
            answers.add(0);
            return;
        }
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    int distance = 0;
                    for (int l = 0; l < 4; l++) {
                        distance += MBTI.get(i).charAt(l) != MBTI.get(j).charAt(l) ? 1 : 0;
                        distance += MBTI.get(j).charAt(l) != MBTI.get(k).charAt(l) ? 1 : 0;
                        distance += MBTI.get(k).charAt(l) != MBTI.get(i).charAt(l) ? 1 : 0;
                    }
                    answer = Math.min(answer, distance);
                    if (answer == 0) {
                        answers.add(answer);
                        return;
                    }
                }
            }
        }
        answers.add(answer);
    }
}