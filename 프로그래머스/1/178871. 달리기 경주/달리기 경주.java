import java.util.*;
class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        int n = players.length;
        Map<String , Integer> m = new HashMap<>();
        for(int i =0; i<n; ++i){
              m.put(players[i] , i);
        }
        for(int i =0;i<callings.length; ++i){
            int target_idx = m.get(callings[i]); // 변경해야할 idx
            int prev_idx = target_idx -1;
            if(prev_idx >= 0){
                String prev = players[prev_idx];
                String target = players[target_idx];
                
                m.put(target , prev_idx);
                m.put(prev , target_idx);
                
                players[prev_idx] = target;
                players[target_idx] = prev;
            }
        }
        
        answer = players;
        return answer;
    }
}