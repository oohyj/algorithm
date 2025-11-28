import java.io.*;
import java.util.*;

public class Main {
    static final int INF = 1_000_000_000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] dist = new int[n+1][n+1];
        int[][] nxt = new int[n+1][n+1];

        for (int i=1;i<=n;i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for (int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            dist[a][b] = w;
            dist[b][a] = w;
            nxt[a][b] = b;
            nxt[b][a] = a;
        }

        for (int k=1;k<=n;k++){
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        nxt[i][j] = nxt[i][k];
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j) sb.append("- ");
                else sb.append(nxt[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.print(sb);
    }
}