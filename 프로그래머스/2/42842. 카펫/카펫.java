import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        for (int i = 1; i <= yellow; i++) {
            if (yellow % i == 0) {
                int j = yellow / i;

                int row = i + 2;
                int column = j + 2;
                int total = row * column;
                int outside = total - yellow;

                if (outside == brown) {
                    return new int[]{column, row}; 
                }
            }
        }
        return new int[0]; 
    }
}