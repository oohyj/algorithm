import java.util.*;
class Solution {
    
    static long findMax(long[] arr){
        long current = arr[0];
        long max_cnt = arr[0];
        
        for(int i =1; i<arr.length; ++i){
            current = Math.max(arr[i] , current+arr[i]);
            max_cnt = Math.max(max_cnt , current);
        }
        
        return max_cnt;
    }
    
    
    public long solution(int[] sequence) {
        long answer = 0;
        
        int n = sequence.length;
        long[] pulse1 = new long[n];
        long[] pulse2 = new long[n];
        
        for(int i =0; i<n; ++i){
            int sign = (i % 2==1)? 1 : -1;
            pulse1[i] = sequence[i] * sign;
            pulse2[i] = sequence[i] * -sign;
        }
        
        answer = Math.max(findMax(pulse1) , findMax(pulse2));
        return answer;
    }
}