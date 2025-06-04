import java.util.*;
class Solution {
    int[] dx = { 1 , 0 , -1 , 0};
    int[] dy = { 0 , 1 , 0 , -1};
    public int solution(String[] storage, String[] requests) {
        int answer = 0;
        int row = storage.length;
        int col = storage[0].length();
        
        boolean[][] container = new boolean[row][col];
        
        for(int i =0; i<row; ++i){
            for(int j =0; j<col; ++j){
                container[i][j] = true;
            }
        }
        
        for(String req : requests){
            boolean[][] copy = new boolean[row][col];
            for(int i =0; i<row; ++i){
                copy[i] = container[i].clone();
            }
            for(int i =0; i<row; ++i){
                for(int j =0; j<col; ++j){
                    if(storage[i].charAt(j) == req.charAt(0)){
                        if(req.length() == 2){ // 크레인
                            copy[i][j] = false; //삭제
                        }
                        else{ //지게차
                            Queue<int[]> q = new LinkedList<>();
                            boolean[][] check = new boolean[row][col];
                            q.offer(new int[]{i , j});
                            check[i][j] = true;
                            boolean canMove = false;
                            
                            while(!q.isEmpty()){
                                int[] cur = q.poll();
                                int curx = cur[0];
                                int cury = cur[1];
                                
                                for(int dir =0; dir<4; ++dir){
                                    int newx = curx+dx[dir];
                                    int newy = cury+dy[dir];
                                    
                                    if(newx <0 || newx >=row || newy <0 || newy >= col){
                                        canMove = true;
                                        break;
                                    }
                                    
                                    if(check[newx][newy] || container[newx][newy]){
                                        continue;
                                    }
                                    
                                    q.offer(new int[]{newx , newy});
                                    check[newx][newy] = true;
                                }
                                
                                if(canMove){
                                    break;
                                }
                                
                            }
                            if(canMove){
                                copy[i][j] = false;
                            }
                        }
                    }
                }
            }
            
            container = copy;
        }
    for(int i =0; i<row; ++i){
        for(int j =0; j<col; ++j){
            if(container[i][j]){
                answer++;
            }
        }
    }
     
        return answer;
    }
}