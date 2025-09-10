import java.util.*;
class Solution {
    
    static boolean[][] m; //지도
    
    static void convertBinary(int t , int n , int i){ // i는 행
        int idx = n-1;
        
        while(t > 0){
            int bit = t % 2;
            if(bit ==1){
                m[i][idx] = true;
            }
            t /=2;
            idx --;
        }
    }
    
    
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
         m = new boolean[n][n]; 
        
        for(int i = 0; i<n; ++i){
            convertBinary(arr1[i] , n , i);
        }
        
        for(int j =0; j<n; ++j){
            convertBinary(arr2[j] , n , j);
        }
        
        
        for(int i =0; i<n; ++i){
            StringBuilder sb = new StringBuilder();
            for(int j =0; j<n; ++j){
                if(m[i][j]) sb.append("#");
                else sb.append(" ");
            }
            answer[i] = sb.toString();
        }
        return answer;
    }
}