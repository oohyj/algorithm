import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine().trim());
        int[] cranes = new int[N];
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) cranes[i] = Integer.parseInt(st.nextToken());
        }

        int M = Integer.parseInt(br.readLine().trim());
        int[] boxes = new int[M];
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) boxes[i] = Integer.parseInt(st.nextToken());
        }

    
        Arrays.sort(cranes);
        Arrays.sort(boxes);
        reverse(cranes);
        reverse(boxes);

       
        if (boxes.length > 0 && cranes[0] < boxes[0]) {
            System.out.println(-1);
            return;
        }

       
        int[] pos = new int[N];
        boolean[] loaded = new boolean[M];
        int moved = 0;
        int minutes = 0;

        while (moved < M) {
            for (int i = 0; i < N; i++) {
                // 현재 크레인이 들 수 있는 박스를 찾을 때까지 전진
                while (pos[i] < M) {
                    if (!loaded[pos[i]] && cranes[i] >= boxes[pos[i]]) {
                        loaded[pos[i]] = true;
                        pos[i]++;     // 다음 탐색 시작 위치 갱신
                        moved++;
                        break;
                    } else {
                        pos[i]++;     // 이미 실은 박스거나 무거우면 다음 것으로
                    }
                }
            }
            minutes++;
        }

        System.out.println(minutes);
    }

    private static void reverse(int[] a) {
        for (int i = 0, j = a.length - 1; i < j; i++, j--) {
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
}