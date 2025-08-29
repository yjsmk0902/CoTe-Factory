class Solution {
    fun solution(letter: String): String {
        val morse = arrayOf(".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..")
        
        val morseMap = morse.zip('a'..'z').toMap()
        return letter.split(" ").map { morseMap[it] }.joinToString("")
    }
}