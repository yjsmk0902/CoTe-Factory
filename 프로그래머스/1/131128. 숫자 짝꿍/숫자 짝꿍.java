import java.util.*;

class Solution {
    public String solution(String X, String Y) {
        String answer = "";
        boolean isZero = true;
        
        int[] mapX = new int[10];
        int[] mapY = new int[10];
        
        
        for(int i = 0; i < X.length(); i++){
            mapX[Integer.parseInt(String.valueOf(X.charAt(i)))]++;
        }
        
        for(int i = 0;i < Y.length(); i++){
            mapY[Integer.parseInt(String.valueOf(Y.charAt(i)))]++;
        }
        
        for(int i = 9; i >= 0; i--){
            int min = mapX[i] <= mapY[i] ? mapX[i] : mapY[i];
            if(min != 0){
                if(i != 0){
                    isZero = false;
                }
                answer += String.valueOf(i).repeat(min);
            }                                       
        }
        
        if(answer == ""){
            return "-1";
        }else if(isZero){
            return "0";
        }else {
            return answer;
        }
    }
}