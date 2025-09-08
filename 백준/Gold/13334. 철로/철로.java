import java.io.*;
import java.util.*;

public class Main {

    static class Route{
        int start , end;
        Route(int h , int o){
            if (h <= o) { start = h; end = o; }
            else { start = o; end = h; }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        List<Route> all = new ArrayList<>(n);

        for(int i =0; i<n; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken());
            int o = Integer.parseInt(st.nextToken());
            all.add(new Route(h , o));
        }

        int d = Integer.parseInt(br.readLine());

        List<Route> cand = new ArrayList<>();
        for(Route r : all){
            if(r.end - r.start <= d) cand.add(r);
        }

        cand.sort(Comparator.comparingInt(r -> r.end));

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int ans = 0;
        for(Route r : cand){
            int left = r.end - d;
            minHeap.offer(r.start);
            while(!minHeap.isEmpty() && minHeap.peek() < left){
                minHeap.poll();
            }
            ans = Math.max(ans , minHeap.size());
        }
        System.out.println(ans);
    }
}