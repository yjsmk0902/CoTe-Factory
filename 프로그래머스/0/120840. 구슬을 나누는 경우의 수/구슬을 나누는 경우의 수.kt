class Solution {
    fun solution(balls: Int, share: Int): Int {
        if (balls == share) return 1
        
        val r = minOf(share, balls - share)
        var result = 1L
        
        for (i in 0 until r) {
            result = result * (balls - i) / (i + 1)
        }
        
        return result.toInt()
    }
}