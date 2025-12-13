import java.util.*;

class Solution {
    
    static final int INF = 1_000_000_000;
    public int solution(int[][] info, int n, int m) {
        int answer = INF;
        
        int T = info.length;
        
        int[][] dp = new int[T+1][m];
        
        for(int i =0; i<=T; ++i){
            Arrays.fill(dp[i] , INF);
        }
         dp[0][0] = 0;
        
        
        for(int i =0; i < T; ++i){
          for(int b =0; b<m; ++b){
              if(dp[i][b] == INF) continue;
              //A가 도둑질하는 경우
              int newA = dp[i][b] + info[i][0];
if (newA < n) {
    dp[i+1][b] = Math.min(dp[i+1][b], newA);
}
              //B가 도둑질하는 경우
              int newB = b + info[i][1];
              if(newB < m){
                  dp[i+1][newB] = Math.min(dp[i+1][newB] , dp[i][b]);
              }
          }
        }
        
        for(int b = 0; b<m; ++b){
            answer = Math.min(answer , dp[T][b]);
        }
        
        if(answer == INF) answer = -1;
        return answer;
    }
}