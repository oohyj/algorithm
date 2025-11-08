import java.io.*;
import java.util.*;

public class Main {
    static final long NEG_INF = Long.MIN_VALUE / 4;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());


        List<Integer>[] byGenre = new ArrayList[11];
        for (int g = 1; g <= 10; g++) byGenre[g] = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());
            byGenre[g].add(c);
        }


        long[][] prefix = new long[11][];
        int[] size = new int[11];
        for (int g = 1; g <= 10; g++) {
            List<Integer> list = byGenre[g];
            list.sort(Comparator.reverseOrder());
            size[g] = list.size();
            prefix[g] = new long[size[g] + 1];
            for (int i = 1; i <= size[g]; i++) {
                prefix[g][i] = prefix[g][i - 1] + list.get(i - 1);
            }
        }

        long[] prev = new long[K + 1];
        long[] cur = new long[K + 1];
        Arrays.fill(prev, NEG_INF);
        prev[0] = 0;

        for (int g = 1; g <= 10; g++) {
            Arrays.fill(cur, NEG_INF);
            for (int k = 0; k <= K; k++) {
                if (prev[k] == NEG_INF) continue;
                int maxPick = Math.min(size[g], K - k);
                for (int t = 0; t <= maxPick; t++) {
                    long bonus = (long) t * (t - 1); 
                    long val = prev[k] + prefix[g][t] + bonus;
                    if (val > cur[k + t]) cur[k + t] = val;
                }
            }
            long[] tmp = prev; prev = cur; cur = tmp;
        }

        System.out.println(prev[K]);
    }
}