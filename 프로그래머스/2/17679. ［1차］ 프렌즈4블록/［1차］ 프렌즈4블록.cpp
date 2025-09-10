#include <string>
#include <vector>

using namespace std;

vector<vector<char>> block;  // 블록 정보
vector<vector<bool>> toRemove;  // 지워야 할 블록 정보 

void markBomb(){
    int m = block.size();
    int n = block[0].size();
    
    for(int i =0; i<m; ++i){
        fill(toRemove[i].begin() , toRemove[i].end() , false); // 매 라운드마다 빈 칸으로 초기화
    }
for(int i =0; i< m-1; ++i){
    for(int j =0; j<n-1; ++j){
        char c = block[i][j];
        if(c =='.') continue;
        if(c == block[i][j+1] &&
           c == block[i+1][j] &&
           c == block[i+1][j+1]
          )
        { toRemove[i][j] = true;
                toRemove[i][j+1] = true;
                toRemove[i+1][j] = true;
                toRemove[i+1][j+1] = true;}
    }
}
}
       
int eraseBomb(){
    int m = block.size();
    int n = block[0].size();
    
    int removed = 0;
    for(int i =0; i<m; ++i){
        for(int j =0; j<n;++j){
            if(toRemove[i][j]){ // 지워야 하는 블록이면
                block[i][j] = '.';
                removed++;
            }
        }
    }
    return removed;
}

void applyGravity(){
    int m = block.size();
    int n = block[0].size();
    
    for(int col = 0; col<n; ++col){
        int write = m-1;
        for(int row = m-1; row >=0; row--){
            if(block[row][col] != '.'){
                block[write][col] = block[row][col];
                if (write != row) block[row][col] = '.';
                --write;
            }
        }
    }
    
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    block.assign(m , vector<char>(n)); 
    toRemove.assign(m , vector<bool>(n , false)); 
    
    for(int i =0; i < m; ++i){
        for(int j =0; j<n; ++j){
            block[i][j] = board[i][j];
        }
    }
    
    while(true){
        // 지워질 블록 마킹
        markBomb();
        // 지워야 하는 블록 지우기
        int removed = eraseBomb();
        if(removed == 0) break; // 더 이상 없앨 께 없다면 종료
        answer += removed;
        applyGravity();
    }
    
    return answer;
}