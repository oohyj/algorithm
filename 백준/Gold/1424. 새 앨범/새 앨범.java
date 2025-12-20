import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine().trim());
        int L = Integer.parseInt(br.readLine().trim());
        int C = Integer.parseInt(br.readLine().trim());

        int K = (C + 1) / (L + 1); // 항상 >= 1

        
        int M = (K % 13 == 0) ? (K - 1) : K;


        if (M <= 0) {

            System.out.println(N);
            return;
        }


        boolean[] allowed = new boolean[M + 1];
        List<Integer> allowedList = new ArrayList<>();
        for (int i = 1; i <= M; i++) {
            if (i % 13 != 0) {
                allowed[i] = true;
                allowedList.add(i);
            }
        }

     
        boolean[] possible2 = new boolean[2 * M + 1];
        for (int a : allowedList) {
            for (int b : allowedList) {
                possible2[a + b] = true;
            }
        }

        int start = (N + M - 1) / M;

        for (int m = Math.max(1, start); ; m++) {
            if (canMake(N, M, allowed, possible2, m)) {
                System.out.println(m);
                return;
            }
        }
    }

    static boolean canMake(int N, int M, boolean[] allowed, boolean[] possible2, int m) {
        if (m == 1) {
            return N <= M && (N % 13 != 0);
        }
        if (m == 2) {
           
            if (N < 2 || N > 2 * M) return false;
            int lo = Math.max(1, N - M);
            int hi = Math.min(M, N - 1);
            for (int a = lo; a <= hi; a++) {
                if (!allowed[a]) continue;
                int b = N - a;
                if (b >= 1 && b <= M && allowed[b]) return true;
            }
            return false;
        }


        int rem = N - (m - 3) * M;


        if (rem < 3 || rem > 3 * M) return false;

    
        int cLo = Math.max(1, rem - 2 * M);
        int cHi = Math.min(M, rem - 2);

        for (int c = cLo; c <= cHi; c++) {
            if (!allowed[c]) continue;
            int s = rem - c; 
            if (s >= 2 && s <= 2 * M && possible2[s]) return true;
        }
        return false;
    }
}