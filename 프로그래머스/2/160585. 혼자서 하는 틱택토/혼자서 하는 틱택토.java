import java.util.*;
class Solution {
    public int solution(String[] board) {
       
        int OCnt = 0 ,XCnt = 0;
        // 선공이 O , 후공이 X
        char[][] game = new char[3][3];
        
        for(int i =0; i<3; ++i){
            for(int j =0; j<3; ++j){
                if(board[i].charAt(j) == 'O') OCnt++;
                if(board[i].charAt(j) == 'X')XCnt++;
                game[i][j] = board[i].charAt(j);
            }
        }
        
        if(!(OCnt == XCnt || OCnt == XCnt +1)) return 0;
        
        boolean winO = isThree('O' , game);
        boolean winX = isThree('X' , game);
        if(winO && winX) return 0; // 동시에 이기는 건 불가
        
        if (winO && OCnt != XCnt + 1) return 0;
        if (winX && OCnt != XCnt) return 0;

        
        return 1;
    }
    
    static boolean isThree(char a , char[][] game){
        //가로
        for(int i =0; i<3; ++i){
          if(game[i][0] == a && game[i][1] == a && game[i][2] == a) return true;
        }
        //세로
   
       for (int j = 0; j < 3; ++j) {
           if(game[0][j] == a && game[1][j] == a && game[2][j] == a) return true;
        }
        //대각선
        if(game[0][0] == a && game[1][1] == a && game[2][2] == a) return true;
        if(game[0][2] == a && game[1][1] == a && game[2][0]==a) return true;
        return false;
    }
}