class Solution {
    fun solution(hp: Int): Int {
        var answer: Int = 0
        var temp: Int = hp
        answer += temp / 5
        temp = temp % 5
        answer += temp / 3
        temp = temp % 3
        answer += temp / 1
        return answer
    }
}