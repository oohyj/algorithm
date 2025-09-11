import java.io.*;
import java.util.*;
class Solution {
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        int answer = 0;
        
        Arrays.sort(data , (a , b) -> {
            if(a[col-1] == b[col-1]) return Integer.compare(b[0] , a[0]);
            return Integer.compare(a[col-1] , b[col-1]);
        });
    
        for(int i = row_begin-1; i<= row_end-1; ++i){
            int sum = 0;
            //  System.out.println("현재 row : " + i);
            for(int j =0; j<data[0].length; ++j){
                sum = sum + (data[i][j] % (i+1));
               // System.out.println("현재 data mod : " + data[i][j]);
            }
           // System.out.println("sum : " + sum);
            answer = answer ^ sum;
        }
        
        return answer;
    }
}