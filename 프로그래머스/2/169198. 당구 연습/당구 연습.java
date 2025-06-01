import java.util.*;

class Solution {
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {

        List<Integer> result = new ArrayList<>();
        
        for(int[] ball : balls){
            int targetX = ball[0];
            int targetY = ball[1];
            int minDist = Integer.MAX_VALUE;
            
            
            int[][] mirrors = new int[][]{
                {-targetX , targetY},
                {2*m-targetX , targetY},
                {targetX , -targetY},
                {targetX , 2*n-targetY}
            };
            
            for(int[] mirror : mirrors){
                int mx = mirror[0];
                int my = mirror[1];
                
                int dx = startX - mx;
                int dy = startY - my;
                
                if(startX == targetX){
                  if((startY > targetY && my < targetY)||(startY < targetY && my > targetY)) continue;
                }
                
                if(startY == targetY){
                     if((startX > targetX && mx < targetX)||(startX < targetX && mx > targetX)) continue;
                }
                int dist = dx*dx + dy*dy;
                minDist = Math.min(minDist , dist);
            }
            result.add(minDist);
            
        }
        
        int[] answer = result.stream().mapToInt(i ->i).toArray();
        return answer;
    }
}