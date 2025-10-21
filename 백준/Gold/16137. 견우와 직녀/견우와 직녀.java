import java.io.*;
import java.util.*;

public class Main {

    static int N , M;
    static int[][] grid; // 격자

    static int[] dx = { -1 , 1 , 0 , 0};
    static int[] dy = { 0 , 0 , -1 , 1};


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N =Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        grid = new int[N][N];
        int answer = Integer.MAX_VALUE;


        for(int i =0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j =0; j<N; ++j){
                grid[i][j] =Integer.parseInt(st.nextToken());
            }
        }

        for(int i =0; i<N; ++i){
            for(int j =0; j<N; ++j){
               if(grid[i][j] == 0 && canPlaceBridge(i , j)){
                   grid[i][j] = M;
                   answer = Math.min(answer , bfs());
                   grid[i][j] = 0;
               }

            }
        }

        System.out.println(answer);
        }

       static boolean canPlaceBridge(int i , int j){
           boolean horiz = false , vert = false;

           if(in(i-1 , j) && grid[i-1][j] == 0) vert= true;
           if(in(i+1 , j ) && grid[i+1][j] == 0) vert = true;
           if(in(i , j-1 ) && grid[i][j-1] == 0) horiz = true;
           if(in(i , j+1) && grid[i][j+1] == 0) horiz = true;

          return !(horiz && vert);
       }

    static boolean in(int x , int y){
        int n = grid.length;
        if(x < 0 || x >= n || y < 0 || y >= n) return false;
        else return true;
    }

    static int bfs(){
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[N][N];

        q.offer(new int[]{0 , 0 , 0}); // x , y , time , bridgeUsed(사용했으면 1 , 아니면 0)
        visited[0][0] = true;

        while(!q.isEmpty()){
            var cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int time = cur[2];
            visited[x][y] = true;

            if(x == N-1 && y == N-1){
                return time;
            }

            for(int dir = 0; dir <4; ++dir){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(!in(nx , ny)) continue;
                if(grid[nx][ny] == 0) continue;
                if(visited[nx][ny]) continue;

                if(grid[nx][ny] ==1) {
                    visited[nx][ny] = true;
                    q.offer(new int[]{nx , ny , time+1});
                }

                if(grid[nx][ny] >= 2){
                    if(grid[x][y] != 1) continue;

                    int t = grid[nx][ny];
                    int arrive = time+1;
                    if(arrive % t == 0){
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx , ny , arrive});
                    }else{
                        q.offer(new int[]{x , y , time+1});
                    }
                }


            }
        }
        return Integer.MAX_VALUE;
    }
}