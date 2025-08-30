import java.io.*;
import java.util.*;

public class Main {

    static int[] dx = {-1 , 1 , 0 , 0};
    static int[] dy = {0 , 0 , -1 , 1};
    static int n = 5 ,  m = 5;
    static char[][] board = new char[n][m];
    static int answer = 0;
    static HashSet<Integer> seen = new HashSet<>();

    static void backTrack(List<int[]> frontier , boolean[][] visited , int sCnt , int cnt , int mask){
        if(cnt == 7){
            if(sCnt >= 4 && seen.add(mask)) answer++;
            return;
        }

       for(int idx = 0; idx < frontier.size(); ++idx){
           int y = frontier.get(idx)[0];
           int x = frontier.get(idx)[1];
           if(visited[y][x]) continue;
           visited[y][x] = true;

           int ns = sCnt + (board[y][x] == 'S'? 1 : 0);
           int nmask = mask | (1<<(y*5 + x));

           ArrayList<int[]> next = new ArrayList<>();
           for(int j = idx+1; j<frontier.size(); j++) next.add(frontier.get(j));
           for(int d = 0; d<4; ++d){
               int ny = y + dy[d];
               int nx = x + dx[d];
               if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
               if(visited[ny][nx]) continue;
               next.add(new int[]{ny , nx});
           }
           backTrack(next , visited  , ns , cnt+1 , nmask);
           visited[y][x] = false;
       }

    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int i =0; i<n; ++i){
            String line = br.readLine();
            for(int j =0; j<m; ++j){
                board[i][j] = line.charAt(j);
            }
        }

        boolean[][] visited = new boolean[n][m];

        for(int i =0; i<5; ++i){
            for(int j =0; j<5; ++j){
                visited[i][j] = true;
                int s = (board[i][j] == 'S') ? 1 : 0;
                int mask = 1 << (i*5+j);
                ArrayList<int[]> frontier = new ArrayList<>();
                for(int d = 0; d <4; ++d){
                    int ny = i+ dy[d] , nx = j + dx[d];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    frontier.add(new int[]{ny , nx});
                }
                backTrack(frontier , visited , s , 1 , mask);
                visited[i][j] = false;
            }
        }

        System.out.println(answer);

    }
}