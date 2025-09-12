import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N ,  K; // 멀티탭 구멍의 개수 , 전기 용품의 총 사용횟수
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int[] seq = new int[K];

        st = new StringTokenizer(br.readLine());
        for(int i =0; i<K; ++i){
           if(!st.hasMoreTokens()){
               st = new StringTokenizer(br.readLine());
           }
            seq[i] = Integer.parseInt(st.nextToken());
        }

       Set<Integer> plugged = new HashSet<>();
       int answer = 0;

       for(int i =0; i<K; ++i){
           if(plugged.contains(seq[i])) continue;

           if(plugged.size() < N){
               plugged.add(seq[i]);
               continue;
           }

           int removeTarget = -1;
           int latest = -1;

           for(int dev : plugged){
               int nextIdx = Integer.MAX_VALUE;
               for(int j = i+1; j<K; ++j){
                   if(seq[j] == dev) {
                       nextIdx = j;
                       break;
                   }
               }
               if(nextIdx > latest){
                   latest = nextIdx;
                   removeTarget = dev;
               }
           }

           plugged.remove(removeTarget);
           plugged.add(seq[i]);
           answer++;

       }
       System.out.println(answer);
    }
}