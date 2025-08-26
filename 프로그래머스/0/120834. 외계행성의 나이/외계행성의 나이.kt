class Solution {
    fun solution(age: Int): String {
        var answer: String = ""
        val sb = StringBuilder(age.toString())
        for((index, value) in age.toString().withIndex()){
            sb[index] = (value.code + 97 - 48).toChar()
        }
        return sb.toString()
    }
}