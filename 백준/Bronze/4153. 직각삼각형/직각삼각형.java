import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {
    private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static final List<Integer> values = new ArrayList<>();
    private static final List<String> answers = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        while (true) {
            init();
            if (isValidExit()) {
                answers.forEach(System.out::println);
                return;
            }
            answers.add(isPythagoras() ? "right" : "wrong");
        }
    }

    public static void init() throws IOException {
        StringTokenizer st = new StringTokenizer(reader.readLine());
        values.clear();
        while (st.hasMoreTokens()) {
            values.add(Integer.parseInt(st.nextToken()));
        }
    }

    public static boolean isValidExit() {
        return values.stream().allMatch(value -> value == 0);
    }

    public static boolean isPythagoras() {
        List<Integer> sortedValues = values.stream().sorted().collect(Collectors.toUnmodifiableList());
        return square(sortedValues.get(0)) + square(sortedValues.get(1)) == square(sortedValues.get(2));
    }

    public static Integer square(int x) {
        return x * x;
    }
}