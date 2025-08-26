class Solution {
    fun solution(n: Int): Int {
        var answer: Int = 0
        for(i in n/2 downTo 1){
            if(n % i == 0){
                answer++
            }
        }
        return answer + 1
    }
}