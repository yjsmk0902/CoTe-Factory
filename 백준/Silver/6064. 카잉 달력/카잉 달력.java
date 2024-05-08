import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static int T;
    private static final List<Input> inputs = new ArrayList<>();
    private static final List<Integer> answers = new ArrayList<>();

    public static class Input {
        private int M, N, x, y;

        public Input(int m, int n, int x, int y) {
            M = m;
            N = n;
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        init();
        inputs.forEach(input -> {
            int i = 0, j = 0;
            int maxValue = input.M * input.N;
            while (true) {
//                System.out.println(input.M + " " + input.N + " " + input.x + " " + input.y);
                int calculateM = calculate(input.M, input.x, i);
                int calculateN = calculate(input.N, input.y, j);
//                System.out.println(calculateM + " " + calculateN);

                if (calculateM == calculateN) {
                    answers.add(calculateM);
                    break;
                }
                if (calculateM > maxValue || calculateN > maxValue) {
                    answers.add(-1);
                    break;
                }
                if (calculateM < calculateN) i++;
                if (calculateM > calculateN) j++;
            }
        });
        answers.forEach(System.out::println);
    }

    public static void init() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(reader.readLine());
        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            inputs.add(new Input(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
    }

    public static int calculate(int a, int b, int index) {
        return a * index + b;
    }
}