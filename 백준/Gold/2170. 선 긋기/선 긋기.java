import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        long[][] arr = new long[N][2];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            arr[i][0] = x;
            arr[i][1] = y;
        }

        Arrays.sort(arr, (a, b) -> {
            if (a[0] == b[0]) return Long.compare(a[1], b[1]);
            return Long.compare(a[0], b[0]);
        });

        long total = 0;

        long curStart = arr[0][0];
        long curEnd = arr[0][1];

        for (int i = 1; i < N; i++) {
            long s = arr[i][0];
            long e = arr[i][1];

            if (s <= curEnd) {

                curEnd = Math.max(curEnd, e);
            } else {
          
                total += curEnd - curStart;

                curStart = s;
                curEnd = e;
            }
        }

        total += curEnd - curStart;

        System.out.println(total);
    }
}