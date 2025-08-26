class Solution {
    fun solution(dots: Array<IntArray>): Int {
        if(calInclination(dots[0], dots[1]) == calInclination(dots[2], dots[3])){
            return 1
        } else if(calInclination(dots[0], dots[2]) == calInclination(dots[1], dots[3])){
            return 1
        } else if(calInclination(dots[0], dots[3]) == calInclination(dots[1], dots[2])){
            return 1
        }
        return 0
    }
    
    fun calInclination(pointA: IntArray, pointB: IntArray): Double {
        return ((pointA[1] - pointB[1]).toDouble() / (pointA[0] - pointB[0])).toDouble()
    }
}