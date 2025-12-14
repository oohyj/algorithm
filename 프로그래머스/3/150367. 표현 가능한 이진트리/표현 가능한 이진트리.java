import java.util.*;

class Solution {
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];
        
        for(int i = 0; i<numbers.length; ++i){
            String binary = Long.toBinaryString(numbers[i]);
            
            int len = binary.length();
            int treeSize = 1;
            while(treeSize < len){
                treeSize = treeSize * 2 +1;
            }
            
            String padded = "0".repeat(treeSize - len)  + binary;
            
            answer[i] = isValid(padded)? 1 : 0;
        }
        
        return answer;
    }
    
    private boolean isValid(String s){
        if(s.length() == 1) return true;
        
        int mid = s.length()/2;
        char root = s.charAt(mid);
        
        if(root == '0'){
            for(int i =0; i<s.length(); ++i){
                if(s.charAt(i) == '1'){
                    return false;
                }
            }
            return true;
        }
        
        String left = s.substring(0 , mid);
        String right = s.substring(mid+1);
        
        return isValid(left) && isValid(right);
    }
}