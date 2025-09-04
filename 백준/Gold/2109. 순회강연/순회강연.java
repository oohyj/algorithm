import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        int[][] lecture = new int[n][2]; // 강연료 , 남은 day
        for(int i = 0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            lecture[i][0] = time;
            lecture[i][1] = d;
        }

        Arrays.sort(lecture , Comparator.comparingInt(a -> a[1]));
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        long money = 0;
        for(int[] lec : lecture){
            minHeap.offer(lec[0]);
            money += lec[0];
            while(minHeap.size() > lec[1]){
               money -= minHeap.poll();
            }
        }

        System.out.println(money);

    }
}