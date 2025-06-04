import java.util.*;
class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        int MAX = (int)1e9+7;
        int[][] dp = new int[n][m];
        
        for(int i =0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                    dp[i][j] = 1;
            }
        }
        
        for(int i =0; i<puddles.length; ++i){
            dp[puddles[i][1]-1][puddles[i][0]-1] = 0;
        }
   
        for (int j = 1; j < m; ++j) {
            if (dp[0][j] == 0 || dp[0][j - 1] == 0) dp[0][j] = 0;
        }

        for (int i = 1; i < n; ++i) {
            if (dp[i][0] == 0 || dp[i - 1][0] == 0) dp[i][0] = 0;
        }
        for(int i = 1; i<n; ++i){
            for(int j =1; j <m; ++j){
                if(dp[i][j] != 0){
                     dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MAX;
                }
            }
        }
        
        answer = dp[n-1][m-1];
        
        return answer;
    }
}