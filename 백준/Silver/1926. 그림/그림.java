import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static int n, m;
    private static int cnt = 0;
    private static int width = 0;
    private static final int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private static Coordinate[][] coordinates;

    public static class Coordinate {
        private int x;
        private int y;
        private final int value;
        private boolean visited;

        public Coordinate(int x, int y, int value) {
            this.x = x;
            this.y = y;
            this.value = value;
            this.visited = false;
        }

        public Coordinate(int value) {
            this.value = value;
            this.visited = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        input(reader);
        solve();
        System.out.println(cnt + "\n" + width);

    }

    public static void input(BufferedReader reader) throws IOException {
        StringTokenizer st = new StringTokenizer(reader.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        coordinates = new Coordinate[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(reader.readLine());
            for (int j = 0; j < m; j++) {
                coordinates[i][j] = new Coordinate(i, j, Integer.parseInt(st.nextToken()));
            }
        }
    }

    public static void solve() {
        Queue<Coordinate> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!coordinates[i][j].visited && coordinates[i][j].value == 1) {
                    bfs(q, i, j);
                }
            }
        }
    }

    private static void bfs(Queue<Coordinate> q, int startX, int startY) {
        int curWidth = 0;
        cnt++;
        coordinates[startX][startY].visited = true;
        q.add(coordinates[startX][startY]);
        curWidth++;

        while (!q.isEmpty()) {
            Coordinate current = q.poll();
            int currentX = current.x;
            int currentY = current.y;
            for (int[] direction : directions) {
                int nextX = currentX + direction[0];
                int nextY = currentY + direction[1];
                if (isValidCoordinate(nextX, nextY)) {
                    coordinates[nextX][nextY].visited = true;
                    q.add(coordinates[nextX][nextY]);
                    curWidth++;
                }
            }
        }
        width = Integer.max(width, curWidth);
    }

    public static boolean isValidCoordinate(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && !coordinates[x][y].visited && coordinates[x][y].value == 1;
    }
}