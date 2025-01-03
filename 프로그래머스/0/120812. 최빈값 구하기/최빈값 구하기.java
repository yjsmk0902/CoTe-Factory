import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] array) {
        int[] tmpList = new int[1000];
        Arrays.fill(tmpList, 0);
        int max = 0;
        int answer = -1;
        for (int n : array) {
            tmpList[n]++;
        }
        for (int i = 0; i < tmpList.length; i++) {
            if (tmpList[i] > max) {
                max = tmpList[i];
                answer = i;
            }
            else if (tmpList[i] == max) {
                answer = -1;
            }
        }
        return answer;
    }
}