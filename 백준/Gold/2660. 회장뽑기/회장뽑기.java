import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static ArrayList<Integer>[] friend;

    static int[] bfs(int node){

        int[] dist = new int[N+1];
        Arrays.fill(dist , -1);

        Queue<Integer> q = new ArrayDeque<>();
        q.offer(node);
        dist[node] = 0;

        while(!q.isEmpty()){

            int cur = q.poll();

            for(int next : friend[cur]){
               if(dist[next] == -1){
                   dist[next] = dist[cur]+1;
                   q.offer(next);
               }
            }
        }

        return dist;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

         N = Integer.parseInt(st.nextToken());

         friend = new ArrayList[N+1];

        for(int i = 1; i <=N; ++i){
            friend[i] = new ArrayList<>();
        }

         while(true){
             st = new StringTokenizer(br.readLine());
             int a = Integer.parseInt(st.nextToken());
             int b = Integer.parseInt(st.nextToken());

             if(a == -1 && b == -1) break;

             friend[a].add(b);
             friend[b].add(a);
         }


         int[] score = new int[N+1];

         for(int i =1; i<=N; ++i){
             int[] dist = bfs(i);
             int maxDist = 0;

             for(int j =1; j <=N; ++j){
                 maxDist = Math.max(maxDist , dist[j]);
             }

             score[i] = maxDist;
         }

         ArrayList<Integer> answer = new ArrayList<>();

         int minScore = Integer.MAX_VALUE;
         int candidate = 0;

         for(int j = 1; j <=N; ++j){
             minScore = Math.min(minScore , score[j]);
         }

         for(int i = 1; i<=N; ++i){
             if(score[i] == minScore) {
                 candidate++;
                 answer.add(i);
             }
         }

         System.out.println(minScore + " "+ candidate);
         for(int i = 0; i < answer.size(); ++i){
             System.out.print(answer.get(i) + " ");
         }

    }
}