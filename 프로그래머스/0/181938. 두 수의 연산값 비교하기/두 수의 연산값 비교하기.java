import java.util.*;
import java.io.*;

class Solution {
    public int solution(int a, int b) {
        int aCalB = Integer.parseInt("" + a + b);
        int doubleACalB = 2 * a * b;
        return aCalB == doubleACalB ? aCalB : Math.max(aCalB, doubleACalB);
    }
}