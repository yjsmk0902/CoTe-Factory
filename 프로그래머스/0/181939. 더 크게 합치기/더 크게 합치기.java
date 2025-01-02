import java.util.*;
import java.io.*;

class Solution {
    public int solution(int a, int b) {
        int aCalB = Integer.parseInt("" + a + b);
        int bCalA = Integer.parseInt("" + b + a);
        return Math.max(aCalB, bCalA);
    }
}