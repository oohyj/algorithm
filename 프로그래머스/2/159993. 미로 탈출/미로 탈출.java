import java.util.*;

class Solution {
    public int solution(String[] maps) {
        int answer = 0;
        int row = maps.length;
        int col = maps[0].length();
        
        int startX=-1 , startY=-1, endX=-1 , endY=-1 ,  leverX = -1, leverY = -1;

        char[][] board = new char[row][col];
        for(int i =0; i<row; ++i){
            for(int j = 0; j<col; ++j){
                board[i][j] = maps[i].charAt(j);
                if (board[i][j] == 'S') {
                    startX = i; startY = j;
                } else if (board[i][j] == 'L') {
                    leverX = i; leverY = j;
                } else if (board[i][j] == 'E') {
                    endX = i; endY = j;
                }
            }
        }
        
       int distToLever = bfs(board, startX, startY, leverX, leverY);
        if (distToLever == -1) return -1;

        int distToEnd = bfs(board, leverX, leverY, endX, endY);
        if (distToEnd == -1) return -1;

        return distToLever + distToEnd;
        
    }
    
    private int bfs(char[][] board , int sx , int sy , int tx , int ty){
        int row = board.length;
        int col = board[0].length;
        boolean[][] isVisited = new boolean[row][col];
        int[] dx = { -1 , 1 , 0 , 0};
        int[] dy = { 0 , 0 , -1 , 1};
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{sx , sy , 0}); // 마지막은 거리
        isVisited[sx][sy] = true;
        
        while(!q.isEmpty()){
            int[] point = q.poll();
            int x = point[0] , y = point[1] , dist = point[2];
            if(x == tx && y == ty){
                return dist;
            }
            
            for(int i =0; i<4; ++i){
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX >=0 && newX < row && newY >=0 && newY < col){
                     if (!isVisited[newX][newY] && board[newX][newY] != 'X') {
                        isVisited[newX][newY] = true;
                        q.offer(new int[]{newX, newY, dist + 1});
                    }
                }
            }
        }
    return -1;
    
    }
}