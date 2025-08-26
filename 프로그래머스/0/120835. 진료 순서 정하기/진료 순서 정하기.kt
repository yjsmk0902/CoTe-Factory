class Solution {
    fun solution(emergency: IntArray): IntArray {
        var answer: IntArray = intArrayOf()
        val indexedItems = emergency.withIndex().map{ it.index + 1 to it.value }
        return indexedItems
            .sortedByDescending { it.second }
            .mapIndexed { rank, (index, value) ->
                index to rank
            }
            .sortedBy { it.first }
            .map { it.second + 1 }
            .toIntArray()
    }
}