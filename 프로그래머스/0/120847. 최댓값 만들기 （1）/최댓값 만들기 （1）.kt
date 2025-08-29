class Solution {
    fun solution(numbers: IntArray): Int {
        var answer: Int = 0
        val sortedList = numbers.sortedDescending()
        return sortedList[0] * sortedList[1]
    }
}