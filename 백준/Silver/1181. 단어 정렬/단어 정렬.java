import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    private static int N;
    private static final List<String> values = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        init();
        List<String> answers = values.stream().distinct()
                .sorted(Comparator.comparing(String::length)
                        .thenComparing(string -> string))
                .collect(Collectors.toUnmodifiableList());

        answers.forEach(System.out::println);
    }

    public static void init() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(reader.readLine());
        while (N > 0) {
            values.add(reader.readLine());
            N--;
        }
    }
}