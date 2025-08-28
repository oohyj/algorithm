import java.io.*;
//import java.util.*;

public class Main {
    static final int MOD = 987654321;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       // StringBuilder out = new StringBuilder();
        int N = Integer.parseInt(br.readLine().trim());

        long[] dp = new long[N+1];
        dp[0] = 1;


        for(int i = 2; i <=N; i+=2){
            long cnt = 0; // 횟수 세기
            for(int j = 0; j <= i-2; j+=2){
                cnt = (cnt + (dp[j] * dp[i-j-2] % MOD)) % MOD;
            }
            dp[i] = cnt;
        }

       System.out.println(dp[N]);
    }
}