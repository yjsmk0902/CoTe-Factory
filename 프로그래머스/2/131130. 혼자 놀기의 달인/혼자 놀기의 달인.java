import java.util.*;

class Solution {

    char[] visited;
    PriorityQueue<Integer> count = new PriorityQueue<>(Collections.reverseOrder());
    List<Integer> group = new ArrayList<>();

    public int solution(int[] cards) {
        visited = new char[cards.length];
        Arrays.fill(visited, 'N');
        for (int i = 0; i < cards.length; i++) {
            if (visited[i] == 'N') {
                visit(cards, i);
                count.add(group.size());
                group = new ArrayList<>();
            }
        }
        if (count.size() == 1) {
            return 0;
        }
        return count.poll() * count.poll();
    }

    public void visit(int[] cards, int idx) {
        group.add(cards[idx]);
        visited[idx] = 'Y';
        if (cards[idx] <= cards.length && visited[cards[idx] - 1] == 'N') {
            visit(cards, cards[idx] - 1);
        }
    }

}