import java.io.*;
import java.util.*;

public class Main {

    static int R, C;
    static char[][] board;
    static boolean[] used = new boolean[26];
    static int answer = 0;

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    static void dfs(int x, int y, int depth) {
        answer = Math.max(answer, depth);

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

            int idx = board[nx][ny] - 'A';
            if (used[idx]) continue;  

            used[idx] = true;
            dfs(nx, ny, depth + 1);
            used[idx] = false;        
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new char[R][C];

        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            for (int j = 0; j < C; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        used[board[0][0] - 'A'] = true;
        dfs(0, 0, 1);

        System.out.println(answer);
    }
}