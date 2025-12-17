import java.io.*;
import java.util.*;

public class Main {

    static class Node{
        int to;
        int score;
        Node(int to , int score){
            this.to = to;
            this.score = score;
        }
    }

    static int N , M , K;
   static ArrayList<Node>[] graph;
   static int[][] dp;
   static int INF = 1_000_000_000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N+1];

        for(int i =1; i<=N; ++i){
            graph[i] = new ArrayList<>();
        }
        
        for(int i = 0; i<K; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if(a < b){
                graph[a].add(new Node(b , c));
            }
        }

        dp = new int[N+1][N+1];
        
        for(int i =1; i<=N; ++i){
            Arrays.fill(dp[i] , -INF);
        }

        dp[1][1] = 0;
        
        for(int i =1; i<=N; ++i){
            for(int cnt = 1; cnt <M; ++cnt){
                if(dp[i][cnt] == -INF) continue;
                
                for(Node next : graph[i]){
                    int to = next.to;
                    int score = next.score;
                    
                    dp[to][cnt+1] = Math.max(dp[to][cnt+1] , dp[i][cnt] + score);
                }
            }
        }
        
        int answer = 0;
        for(int cnt = 1; cnt <=M; ++cnt){
            answer = Math.max(answer , dp[N][cnt]);
        }

        System.out.println(answer);
    }
}