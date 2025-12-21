import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        long[] fact = new long[N + 1];
        fact[0] = 1;
        for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;

        st = new StringTokenizer(br.readLine());
        int type = Integer.parseInt(st.nextToken());

        boolean[] used = new boolean[N + 1];

        if (type == 1) {
            long k = Long.parseLong(st.nextToken());
            StringBuilder sb = new StringBuilder();

            for (int i = 1; i <= N; i++) {
                long block = fact[N - i];
                for (int num = 1; num <= N; num++) {
                    if (used[num]) continue;
                    if (k > block) {
                        k -= block;
                    } else {
                        used[num] = true;
                        sb.append(num).append(" ");
                        break;
                    }
                }
            }
            System.out.println(sb.toString().trim());

        } else {
            long rank = 1;
            int[] perm = new int[N];
            for (int i = 0; i < N; i++) perm[i] = Integer.parseInt(st.nextToken());

            for (int i = 0; i < N; i++) {
                int cnt = 0;
                for (int num = 1; num < perm[i]; num++) {
                    if (!used[num]) cnt++;
                }
                rank += cnt * fact[N - i - 1];
                used[perm[i]] = true;
            }
            System.out.println(rank);
        }
    }
}