import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int round = 1;

        while (a != b) {
            a = (a + 1) / 2;
            b = (b + 1) / 2;
            round++;

            if (a == b) {
                System.out.println(round - 1);
                return;
            }
        }
        System.out.println(-1);
    }
}