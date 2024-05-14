import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static int T;
    private static int boardSize;
    private static Pair start, end;
    private static boolean[][] visited;
    private static Pair[] directions = {
            new Pair(1, 2), new Pair(1, -2),
            new Pair(-2, 1), new Pair(-2, -1),
            new Pair(2, 1), new Pair(2, -1),
            new Pair(-1, -2), new Pair(-1, 2),
    };

    public static class Pair {
        int x;
        int y;
        int cnt = 0;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Pair(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return x == pair.x && y == pair.y;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(reader.readLine());
        while (T-- > 0) {
            boardSize = Integer.parseInt(reader.readLine());

            StringTokenizer st = new StringTokenizer(reader.readLine());
            start = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            st = new StringTokenizer(reader.readLine());
            end = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

            visited = new boolean[boardSize][boardSize];
            solve();
        }
    }

    private static void solve() {
        Queue<Pair> q = new LinkedList<>();
        q.add(start);
        visited[start.x][start.y] = true;
        while (!q.isEmpty()) {
            Pair current = q.poll();
            if (current.equals(end)) {
                System.out.println(current.cnt);
                return;
            }
            for (Pair direction : directions) {
                Pair next = new Pair(current.x + direction.x, current.y + direction.y, current.cnt + 1);
                if (isValid(next)) {
                    q.add(next);
                    visited[next.x][next.y] = true;
                }
            }
        }
    }

    private static boolean isValid(Pair pair) {
        return pair.x >= 0 && pair.x < boardSize && pair.y >= 0 && pair.y < boardSize && !visited[pair.x][pair.y];
    }
}