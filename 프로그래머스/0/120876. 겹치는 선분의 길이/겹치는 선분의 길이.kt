class Solution {
    fun solution(lines: Array<IntArray>): Int {
        val total = lines.flatMap { it.toList() }.sorted().distinct()
        return total.zipWithNext { pointA, pointB ->
            calDuplicate(pointA, pointB, lines)
        }.sum()
    }
    
    fun calDuplicate(pointA: Int, pointB: Int, lines: Array<IntArray>) : Int {
        return if (lines.count { it[0] <= pointA && it[1] >= pointB } >= 2) {
            pointB - pointA
        } else {
            0
        }
    }
}