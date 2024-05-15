import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int T;
    public static int w, h;
    public static char[][] board;
    public static boolean[][] visited;
    public static Pair person;
    public static List<Pair> fires = new ArrayList<>();
    public static final Pair[] directions = {
            new Pair(1, 0), new Pair(0, -1),
            new Pair(-1, 0), new Pair(0, 1)
    };

    public static class Pair {
        int x, y;
        int cnt = 0;
        boolean isFire = false;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Pair(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }

        public Pair(int x, int y, boolean isFire) {
            this.x = x;
            this.y = y;
            this.isFire = isFire;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            h = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            board = new char[w][h];
            visited = new boolean[w][h];
            fires.clear();
            for (int i = 0; i < w; i++) {
                String line = br.readLine();
                for (int j = 0; j < h; j++) {
                    board[i][j] = line.charAt(j);
                    if (board[i][j] == '@') {
                        person = new Pair(i, j);
                    }
                    if (board[i][j] == '*') {
                        fires.add(new Pair(i, j, true));
                    }
                }
            }
            solve();
        }
    }

    private static void solve() {
        Queue<Pair> q = new LinkedList<>(fires);
        q.add(person);
        visited[person.x][person.y] = true;
        while (!q.isEmpty()) {
            Pair current = q.poll();
            if (!current.isFire) {
                if (isExit(current)) {
                    System.out.println(current.cnt + 1);
                    return;
                }
                for (Pair direction : directions) {
                    Pair next = new Pair(current.x + direction.x, current.y + direction.y, current.cnt + 1);
                    if (isMove(next)) {
                        q.add(next);
                        visited[next.x][next.y] = true;
                    }
                }
            }
            for (Pair direction : directions) {
                Pair next = new Pair(current.x + direction.x, current.y + direction.y, true);
                if (isFireMove(next)) {
                    board[next.x][next.y] = '*';
                    q.add(next);
                }
            }
        }
        System.out.println("IMPOSSIBLE");
    }

    private static boolean isFireMove(Pair pair) {
        return isBoardSize(pair) && isSpace(pair);
    }

    private static boolean isMove(Pair pair) {
        return isBoardSize(pair) && isSpace(pair) && !visited[pair.x][pair.y];
    }

    private static boolean isBoardSize(Pair pair) {
        return pair.x >= 0 && pair.y >= 0 && pair.x < w && pair.y < h;
    }

    private static boolean isSpace(Pair pair) {
        return board[pair.x][pair.y] == '.';
    }

    private static boolean isExit(Pair pair) {
        return pair.x == 0 || pair.y == 0 || pair.x == w - 1 || pair.y == h - 1;
    }
}