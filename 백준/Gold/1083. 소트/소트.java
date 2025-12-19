import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        List<Integer> arr = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) arr.add(Integer.parseInt(st.nextToken()));
        long S = Long.parseLong(br.readLine());

        for (int i = 0; i < N && S > 0; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < N && j - i <= S; j++) {
                if (arr.get(j) > arr.get(maxIdx)) {
                    maxIdx = j;
                }
            }
            for (int j = maxIdx; j > i; j--) {
                Collections.swap(arr, j, j - 1);
            }
            S -= (maxIdx - i);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(arr.get(i));
            if (i + 1 < N) sb.append(" ");
        }
        System.out.println(sb);
    }
}