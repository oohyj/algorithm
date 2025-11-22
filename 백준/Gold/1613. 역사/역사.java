import java.io.*;
import java.util.*;

public class Main {

    static int N  , M , S;
    static boolean[][] before;

    static int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
       N = Integer.parseInt(st.nextToken());
       M = Integer.parseInt(st.nextToken());

       before = new boolean[N+1][N+1];

       for(int i =0; i<M; ++i){
           st = new StringTokenizer(br.readLine());
           int a = Integer.parseInt(st.nextToken());
           int b = Integer.parseInt(st.nextToken());
           before[a][b] = true;
       }

       for(int k = 1; k <=N; ++k){
           for(int i =1; i <=N; ++i){
               if(!before[i][k]) continue;
               for(int j =1; j<=N; ++j){
                   if(before[k][j]){
                       before[i][j] = true;
                   }
               }
           }
       }

       S = Integer.parseInt(br.readLine());
       StringBuilder sb = new StringBuilder();

       for(int i =0; i<S; ++i){
           st = new StringTokenizer(br.readLine());
           int x = Integer.parseInt(st.nextToken());
           int y = Integer.parseInt(st.nextToken());

           if(before[x][y]){
               sb.append(-1).append('\n');
           }else if(before[y][x]){
               sb.append(1).append('\n');
           }else{
               sb.append(0).append('\n');
           }
       }

       System.out.print(sb.toString());



    }


}