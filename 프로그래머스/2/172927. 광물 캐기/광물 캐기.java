import java.util.*;

class Solution {
    
    static Map<String , Integer> mineralMap = new HashMap<>();
    
    static int[][] fatigue = {
        {1 , 1 , 1},
        {5 , 1 , 1},
        {25 , 5 , 1}
    };
    
    static int answer;
    
    static void dfs(int[] picks , String[] minerals , int sum , int idx){
        if(idx == minerals.length || picks[0] == 0 && picks[1] ==0 && picks[2] == 0){
            answer = Math.min(answer ,sum);
            return;
        }
        
        for(int i = 0; i<3; ++i){
            if(picks[i] > 0){
                picks[i]--;
                
                int tempSum = sum;
                int tempIdx = idx;
                for(int j =0; j<5 && tempIdx < minerals.length; ++j , tempIdx++){
                    tempSum += fatigue[i][mineralMap.get(minerals[tempIdx])];
                }
                dfs(picks , minerals , tempSum , tempIdx);
                picks[i]++;
            }
        }
    }
    public int solution(int[] picks, String[] minerals) {
         answer =  25 * 50 +1;
        
        mineralMap.put("diamond", 0);
        mineralMap.put("iron", 1);
        mineralMap.put("stone", 2);

        dfs(picks, minerals, 0, 0);

        return answer;
    }
}