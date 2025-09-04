import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] graph;
    static int[][] dp;
    static boolean[] visited;

    static void dfs(int u){
        visited[u] = true;
        dp[u][0] = 0; // u가 얼리 어답터가 아님
        dp[u][1] = 1; // u가 얼리 어답터임

        for(int v : graph[u]){
            if(!visited[v]){
                dfs(v);
                dp[u][0] += dp[v][1];
                dp[u][1] += Math.min(dp[v][0] , dp[v][1]);
            }
        }
    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        graph = new ArrayList[n+1];
        for(int i = 1; i<=n; ++i){
            graph[i] = new ArrayList<>();
        }

        for(int i =0; i<n-1; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph[a].add(b);
            graph[b].add(a);
        }

        dp = new int[n+1][2];
        visited = new boolean[n+1];

        dfs(1);

        System.out.println(Math.min(dp[1][0] , dp[1][1]));

    }
}