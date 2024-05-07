import java.util.*;

public class Main {
    static final int UNKNOWN = 0;
    static final int TRUTH = 1;
    static final int LIE = 2;

    static int N, M;
    static boolean[] know;
    static int ans = 0;
    static HashSet<Integer> truth = new HashSet<>();
    static HashSet<Integer>[] party;

    public static void BFS() {
        Queue<Integer> q = new LinkedList<>();
        for (int it : truth) {
            q.add(it);
            know[it] = true;
        }
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 1; i <= M; i++) {
                if (party[i].contains(cur)) {
                    for (int next : party[i]) {
                        if (!know[next]) {
                            q.add(next);
                            know[next] = true;
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        N = scanner.nextInt();
        M = scanner.nextInt();
        know = new boolean[N + 1];
        party = new HashSet[M + 1];
        for (int i = 1; i <= M; i++) {
            party[i] = new HashSet<>();
        }

        Arrays.fill(know, false);

        int temp = scanner.nextInt();
        while (temp-- > 0) {
            int num = scanner.nextInt();
            truth.add(num);
        }
        for (int i = 1; i <= M; i++) {
            temp = scanner.nextInt();
            while (temp-- > 0) {
                int num = scanner.nextInt();
                party[i].add(num);
            }
        }

        BFS();

        for (int i = 1; i <= M; i++) {
            boolean flag = false;
            for (int it : party[i]) {
                if (know[it]) {
                    flag = true;
                    break;
                }
            }
            ans = (flag ? ans : ans + 1);
        }

        System.out.println(ans);
    }
}
