import java.util.*;
class Solution {
    
    static final int INF = Integer.MAX_VALUE;
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;
    
        int needA = 0 , needC = 0;
        
        for(int[] problem : problems){
            int ar  = problem[0] , cr = problem[1] , aw = problem[2] , cw = problem[3] , cost = problem[4];
            needA = Math.max(needA , ar);
            needC = Math.max(needC , cr);
        }
        int[][] dp = new int[needA+1][needC+1]; // 해당하는 알고력 , 코딩력에 도달할 수 잇는 시간
        int startA = Math.min(alp , needA);
        int startC = Math.min(cop , needC);
        for(int i =0; i<= needA; ++i){
           Arrays.fill(dp[i] , INF);
        }
        
        dp[startA][startC] = 0;
        
        for(int i = startA; i<=needA; ++i){
            for(int j = startC; j <= needC; ++j){
                int cur = dp[i][j];
                if(cur == INF) continue;
                
                // 공부를 하는 경우
                if(i + 1 <= needA) dp[i+1][j] = Math.min(dp[i+1][j] , cur+1);
                if(j+1 <= needC) dp[i][j+1] = Math.min(dp[i][j+1] , cur+1);
                
                // 문제를 푸는 경우
                for(int[] problem : problems){
                    int ar  = problem[0] , cr = problem[1] , aw = problem[2] , cw = problem[3] , cost = problem[4];
                    if( i >= ar && j >= cr ){
                        int ni = Math.min(needA , i + aw);
                        int nj = Math.min(needC , j + cw);
                        dp[ni][nj] = Math.min(dp[ni][nj] , cur+cost);
                    }
                }
            }
        }
        
        answer = dp[needA][needC];
            
        return answer;
    }
}