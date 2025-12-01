import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] dp = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            int min = Integer.MAX_VALUE;
            for (int s = 1; s * s <= i; s++) {
                int sq = s * s;
                if (dp[i - sq] + 1 < min) min = dp[i - sq] + 1;
            }
            dp[i] = min;
        }

        System.out.println(dp[N]);
    }
}