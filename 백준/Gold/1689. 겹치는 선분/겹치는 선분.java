import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[][] events = new int[2 * N][2];
        int idx = 0;

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            events[idx][0] = s;
            events[idx][1] = 1;   
            idx++;

            events[idx][0] = e;
            events[idx][1] = -1;  
            idx++;
        }

        Arrays.sort(events, (a, b) -> {
            if (a[0] == b[0]) return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });

        int cur = 0;
        int answer = 0;

        for (int[] ev : events) {
            if (ev[1] == -1) {   
                cur--;
            } else {          
                cur++;
                answer = Math.max(answer, cur);
            }
        }

        System.out.println(answer);
    }
}