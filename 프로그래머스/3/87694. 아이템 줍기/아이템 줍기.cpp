#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 2501;
    
    vector<vector<int>> board(102 , vector<int>(102 , 0));
    
    // 0 이면 사각형 밖 , 1이면 이동할 수 있는 지점 , 2는 사각형 안 <- 이동할 수 없음
    
    for(int i = 0; i< rectangle.size(); ++i){
        int r1 = rectangle[i][0] * 2;
        int c1 = rectangle[i][1] * 2;
        int r2 = rectangle[i][2] * 2;
        int c2 = rectangle[i][3] * 2;
        
    for(int j = r1; j <= r2; ++j){
        for(int k = c1 ; k <= c2; ++k){
            if(j == r1 || j == r2 || k == c1 || k == c2){
                if(board[j][k] != 2){
                   board[j][k] = 1;    
                }
            }
            else board[j][k] = 2; // 사각형 내부는 지나갈 수 없음
        }
      }
    }
    
    vector<vector<bool>> visited (102 , vector<bool>(102 , false));
    
    queue<tuple<int , int , int>> q;
    int distance = 1;
    q.push({characterX*2, characterY*2 , distance});
    visited[characterX*2][characterY*2] = true;
    int dx[] = { -1 , 1 , 0 , 0};
    int dy[] = { 0 , 0 , -1 , 1};
    
    while(!q.empty()){
        auto[cx , cy , dist] = q.front();
        q.pop();
        
        if(cx == (itemX*2) && cy == (itemY*2)){
            answer = min(answer , dist);
            break;
        }
        
        for(int dir = 0; dir < 4; ++dir){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || nx >= 102 || ny < 0 || ny >= 102) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] == 1){
                visited[nx][ny] = true;
                q.push({nx , ny , dist+1});
            }
        }
    }
    
    return answer/2;
}