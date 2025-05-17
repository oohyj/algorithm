import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        Queue<Integer> q = new LinkedList<>();
        for(int t =0; t<24; ++t){
            while(!q.isEmpty() && q.peek() <=t){
                q.poll();
            }
            
            int required = players[t]/m;
            while(required > q.size()){
               int expansion = required - q.size();
                answer += expansion;
                
                for(int i =0; i<expansion; ++i){
                    q.add(t+k);
                }
            }
        }
        return answer;
    }
}