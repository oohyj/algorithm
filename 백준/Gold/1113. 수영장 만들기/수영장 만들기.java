import java.io.*;
import java.util.*;

public class Main {
    static int N , M;

    static int[][] pool;


    static int[] dx = { -1 , 1 , 0 , 0};
    static int[] dy = { 0 , 0 , -1 , 1};


    public static void main(String[] args) throws Exception {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());

       N =Integer.parseInt(st.nextToken());
       M = Integer.parseInt(st.nextToken());

       pool = new int[N][M];

        for (int i = 0; i < N; ++i) {
            String line = br.readLine().trim();
            for (int j = 0; j < M; ++j) {
                pool[i][j] = line.charAt(j) - '0';
            }
        }

       int answer = 0;

       for(int h =2; h<=9; ++h){ // 물 높이
           boolean[][] visited = new boolean[N][M];
          for(int i  = 0; i<N; ++i){
              for(int j =0; j<M; ++j){
                  if(!visited[i][j] && pool[i][j] < h){
                      Queue<int[]> q = new ArrayDeque<>();
                      List<int[]> comp = new ArrayList<>();
                      boolean leak = false;
                      visited[i][j] = true;
                      q.offer(new int[]{i , j});
                      comp.add(new int[]{i , j});
                      while(!q.isEmpty()){
                          var cur =  q.poll();
                          int x = cur[0];
                          int y = cur[1];
                          if(x== 0 || x == N-1 || y == 0 || y == M-1) leak = true;
                          for(int dir =0; dir< 4; ++dir){
                              int nx = x + dx[dir];
                              int ny = y + dy[dir];
                              if(in(nx , ny) && !visited[nx][ny] && pool[nx][ny] < h){
                                  visited[nx][ny] = true;
                                  q.offer(new int[]{nx , ny});
                                  comp.add(new int[]{nx , ny});
                              }
                          }
                      }
                      if(!leak){
                          for(int[] p : comp){
                              int x = p[0], y = p[1];
                              answer += h-pool[x][y];
                              pool[x][y] = h;
                          }
                      }
                  }
              }
          }

       }

       System.out.println(answer);

    }

    static boolean in(int x , int y){
        if(x <0 || x >= N || y <0 || y >=M) return false;
        else return true;
    }
    
}