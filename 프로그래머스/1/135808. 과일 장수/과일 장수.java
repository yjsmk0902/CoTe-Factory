import java.util.*;

class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        int max = score.length;
        int temp = 0;
        int[] map = new int[10]; 
        
        Arrays.stream(score).forEach(value ->{
            map[value]++;
        });
        
        for(int i = 9; i >= 1; i--){
            int boxes = map[i] + temp / m;
            if(boxes < 1){
                continue;
            }
            answer += (map[i] + temp) / m * i * m;
            temp = (map[i] + temp) % m;
        }
       
        return answer;
    }
}