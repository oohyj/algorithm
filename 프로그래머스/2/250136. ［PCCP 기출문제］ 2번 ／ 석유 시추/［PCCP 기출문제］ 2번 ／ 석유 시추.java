import java.util.*;

class Solution {
    static int[][] copy_land;
    static int miny, maxy;
    static int[] oil;
    static int N, M;

    public int solution(int[][] land) {
        N = land.length;
        M = land[0].length;

        copy_land = new int[N][];
        for (int i = 0; i < N; ++i) {
            copy_land[i] = Arrays.copyOf(land[i], M);
        }

        oil = new int[M];

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (copy_land[i][j] == 1) {    
                    miny = maxy = j;              
                    int temp = getOil(i, j);     
                    for (int k = miny; k <= maxy; ++k) oil[k] += temp;  
                }
            }
        }

        int answer = 0;
        for (int v : oil) answer = Math.max(answer, v);
        return answer;
    }

    static int getOil(int x, int y) {
    
        if (x < 0 || x >= N || y < 0 || y >= M) return 0;


        if (copy_land[x][y] == 0) return 0;

      
        copy_land[x][y] = 0;

     
        if (y < miny) miny = y;
        if (y > maxy) maxy = y;

        return 1
            + getOil(x - 1, y)
            + getOil(x + 1, y)
            + getOil(x, y - 1)
            + getOil(x, y + 1);
    }
}