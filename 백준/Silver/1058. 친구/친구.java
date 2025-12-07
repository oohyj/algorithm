import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        char[][] map = new char[N][N];

        for (int i = 0; i < N; i++) {
            map[i] = br.readLine().toCharArray();
        }

        int answer = 0;

        for (int i = 0; i < N; i++) {
            boolean[] visited = new boolean[N];
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (map[i][j] == 'Y') {
                    visited[j] = true;
                } else {
                    for (int k = 0; k < N; k++) {
                        if (map[i][k] == 'Y' && map[k][j] == 'Y') {
                            visited[j] = true;
                            break;
                        }
                    }
                }
            }
            int cnt = 0;
            for (boolean v : visited) if (v) cnt++;
            answer = Math.max(answer, cnt);
        }

        System.out.println(answer);
    }
}