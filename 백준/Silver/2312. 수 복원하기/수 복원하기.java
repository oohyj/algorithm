import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringBuilder sb = new StringBuilder();

      int T = Integer.parseInt(br.readLine());

      while(T-- > 0){
          int N = Integer.parseInt(br.readLine());
          int num = N;

          for(int i =2; i*i <= num; ++i){
              int count = 0;
              while(N%i == 0){
                  count++;
                  N /= i;
              }
              
              if(count > 0){
                  sb.append(i).append(' ').append(count).append('\n');
              }
          }
          if( N > 1){
              sb.append(N).append(' ').append(1).append('\n');
          }
      }
      
      System.out.println(sb.toString());
    }
}