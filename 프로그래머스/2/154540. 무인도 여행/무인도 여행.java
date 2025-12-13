import java.util.*;

class Solution {
    
    static int dx[] = { -1 , 1 , 0 , 0};
    static int dy[] = { 0 , 0 , -1 , 1};
    static boolean[][] visited;
    static int N , M;
    static int[][] board;
    public int[] solution(String[] maps) {
       
        
        N = maps.length;
        M = maps[0].length();
        
        visited = new boolean[N][M];
        
        board = new int[N][M];
    
        for(int i = 0; i<N; ++i){
            for(int j =0; j<M; ++j){
               if (maps[i].charAt(j) == 'X') {
    board[i][j] = 0;
} else {
    board[i][j] = maps[i].charAt(j) - '0';
}
            }
        }
        
        List<Integer> arr = new ArrayList<>();
        
        for(int i = 0; i<N; ++i){
            for(int j = 0; j<M; ++j){
               if (board[i][j] > 0 && !visited[i][j]) {
    arr.add(bfs(i, j));
}
            }
        }
        
        if (arr.isEmpty()) {
    return new int[]{-1};
}
        
        Collections.sort(arr);
        
        int[] answer = new int[arr.size()];

        
        for(int i = 0; i< arr.size();++i){
            answer[i] = arr.get(i);
        }
        
        return answer;
    }
    
    static int bfs(int x , int y){
        visited[x][y] = true;
        
        Queue<int[]> q = new ArrayDeque<>();
        
        int num = 0;
        
        q.offer(new int[]{x , y});
        
        while(!q.isEmpty()){
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];
            
 
            num += board[cx][cy];
            
            for(int dir =0; dir < 4; ++dir){
                int nx = cx +dx[dir];
                int ny = cy + dy[dir];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
                if(board[nx][ny] == 0) continue; 
                 visited[nx][ny] = true;    
                q.offer(new int[]{ nx , ny});
            }
            
        }
        
        return num;
    }
}