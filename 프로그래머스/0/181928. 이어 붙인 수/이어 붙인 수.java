import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        String oddN = "";
        String evenN = "";
        
        for(int n : num_list){
            if(n % 2 == 0) evenN += n;
            if(n % 2 == 1) oddN += n;
        }
        answer = Integer.parseInt(evenN) + Integer.parseInt(oddN);
        return answer;
    }
}