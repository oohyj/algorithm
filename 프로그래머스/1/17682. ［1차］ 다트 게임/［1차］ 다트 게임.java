import java.util.*;
class Solution {
    
    static int calculator(int number , char c){
        if(c == 'S'){
            return number;
        }
        else if(c == 'D'){
            return number * number;
        }
        else{
            return number*number*number;
        }
        
    }
    public int solution(String dartResult) {
  
        
        int[] game = new int[3]; // 총 3회차 게임
        int order = 0; // 현재 게임 순서 (0-based index)
        
        for(int i =0; i < dartResult.length(); ++i){
           char ch = dartResult.charAt(i);
            if(Character.isDigit(ch)){
                int num;
                if(ch == '1' && i+1 < dartResult.length() && dartResult.charAt(i+1) == '0'){
                    num = 10;
                    i++;
                }else{
                    num = ch - '0';
                }
                game[order] = num;
            }
           if(ch == 'S' || ch == 'D' || ch  == 'T'){
               int t = game[order];
               game[order] = calculator(game[order] , ch);
               order++;
           }
           if(ch == '*'){
               int cur = order-1;
               game[cur] *= 2;
               if(cur -1 >= 0 ) game[cur-1] *=2;
           }
           if(ch == '#'){
              int cur = order -1;
               game[cur] *= -1;
           }
        }
        
      
        
        return game[0] + game[1] + game[2];
    }
}