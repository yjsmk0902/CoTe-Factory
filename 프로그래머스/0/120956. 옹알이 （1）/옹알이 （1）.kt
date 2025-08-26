class Solution {
    fun solution(babbling: Array<String>): Int {
        var answer: Int = 0
        return babbling.count { word ->
            word.replace("aya", " ")
                .replace("ye", " ")
                .replace("woo", " ")
                .replace("ma", " ")
                .isBlank()
        }
    }
}