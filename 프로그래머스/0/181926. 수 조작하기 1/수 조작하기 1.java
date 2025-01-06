class Solution {
    public int solution(int n, String control) {
        int answer = n;
        for(int i = 0; i < control.length(); i++){
            char c = control.charAt(i);
            switch(c){
                case 'w' -> answer++;
                case 's' -> answer--;
                case 'd' -> answer += 10;
                case 'a' -> answer -= 10;
            }
        }
        return answer;
    }
}