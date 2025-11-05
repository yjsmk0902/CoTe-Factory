class Solution {
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        int x, y;
        int max = n * n;
        int flag;
        
        if(n % 2 == 0) {
            x = n / 2;
            y = n / 2 - 1;
            flag = 1;
        } else {
            x = n / 2;
            y = n / 2;
            flag = -1;
        }
        
        answer[x][y] = max--;
        int idx = 1;
        
        for(int i = x, j = y; max >= n;){
        
            for(int k = 0; k < idx; k++){
                j += flag;
                answer[i][j] = max--;
            }
        
            flag *= -1;
            
            for(int k = 0; k < idx; k++){
                i += flag;
                answer[i][j] = max--;
            }
            
            idx++;
        }
        
        for(int i = n - 2; i >= 0; i--){
            answer[0][i] = i + 1; 
        }        
        
        
        return answer;
    }
}