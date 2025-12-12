import java.io.*;
import java.util.*;

public class Main {

    static class Edge{
        int to;
        int weight;

        Edge(int to , int weight){
            this.to = to;
            this.weight = weight;
        }
    }

    static int N , M;
    static List<Edge>[] graph;
    static int start , end;

    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());

      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      graph = new ArrayList[N+1];
      for(int i =1; i<=N; ++i){
          graph[i] = new ArrayList<>();
      }

      int left = 1;
      int right = 0;

      for(int i = 0; i<M; ++i){
         st =new StringTokenizer(br.readLine());
         int u = Integer.parseInt(st.nextToken());
         int v = Integer.parseInt(st.nextToken());
         int w = Integer.parseInt(st.nextToken());

         graph[u].add(new Edge(v , w));
         graph[v].add(new Edge(u , w));

         right = Math.max(right , w);
      }

      st = new StringTokenizer(br.readLine());
      start = Integer.parseInt(st.nextToken());
       end  = Integer.parseInt(st.nextToken());

      int answer = 0;

      while(left <= right){
          int mid = (left+right) /2;

          if (canGo(mid)) {
              answer = mid;
              left = mid+1;
          }else{
              right = mid-1;
          }

          
      }

        System.out.println(answer);
    }

    static boolean canGo(int limit){
        boolean[] visited = new boolean[N+1];
        Queue<Integer> q = new LinkedList<>();

        q.offer(start);
        visited[start] = true;

        while(!q.isEmpty()){
            int cur = q.poll();

            if(cur == end) return true;

            for(Edge e : graph[cur]){
                if(!visited[e.to] && e.weight >= limit){
                    visited[e.to] = true;
                    q.offer(e.to);
                }
            }
        }
        return false;
    }
}