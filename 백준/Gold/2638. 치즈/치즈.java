import java.io.*;
import java.util.*;

public class Main {

    static int n , m;
    static int dx[] = { -1 , 1 , 0 , 0};
    static int dy[] = { 0 , 0 , -1 , 1};

    static int[][] board ; // 치즈판
    static int[][] check; // 몇 분에 사라졌는지 체크
    static boolean[][] visited; // 외부 공기 표시
    static boolean[][] visitedForAir;// 외부 공기 탐색용

    static boolean checkTwoFaces(int y , int x){
        int count = 0;
       for(int d = 0; d < 4; ++d){
           int ny = y + dy[d];
           int nx = x + dx[d];

           if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
           if(visited[ny][nx] && board[ny][nx] == 0){
               count++;
           }
       }

       if(count >= 2) return true;
       else return false;
    }

    static void findExternalAir(int y , int x){
        Queue<int[]> q = new LinkedList<>();
        visitedForAir[y][x] = true;
        visited[y][x] = true;
        q.add(new int[]{y , x});

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int cy = cur[0] , cx= cur[1];

            for(int d =0; d<4; ++d){
                int ny = cy + dy[d];
                int nx = cx + dx[d];

                if(ny < 0 || ny >= n || nx < 0 || nx >=m) continue;

                if(!visitedForAir[ny][nx] && board[ny][nx] == 0){
                    visitedForAir[ny][nx] = true;
                    visited[ny][nx] = true;
                    q.add(new int[]{ny , nx});
                }
            }
        }
    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

         n = Integer.parseInt(st.nextToken());
         m = Integer.parseInt(st.nextToken());

        board = new int[n][m]; // 치즈있는 자리
        check = new int[n][m]; // 몇 분에 사라졌는지 체크


        for(int i =0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j =0; j<m; ++j){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

int time = 0;
        while(true){
            visited = new boolean[n][m]; // 외부 공기 표시
            visitedForAir = new boolean[n][m]; // 외부 공기 방문 표시용

            findExternalAir(0 , 0); // 외부 공기 표시하기

            List<int[]> toMelt = new ArrayList<>();

            for(int i =0; i<n; ++i){
                for(int j =0; j <m; ++j){
                    if(board[i][j] == 1 && checkTwoFaces(i , j)){
                        toMelt.add(new int[]{i , j});
                    }
                }
            }


            if(toMelt.isEmpty()) break;

            time++;

            for(int i =0; i<toMelt.size(); ++i){
                int[] cand = toMelt.get(i);
                board[cand[0]][cand[1]] = 0; // 치즈 녹이기
            }

        }

        System.out.println(time);

    }
}