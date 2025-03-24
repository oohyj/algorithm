#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n , vector<bool>(m , false));
    
    int dx[] = {-1 , 1 , 0 , 0};
    int dy[] = {0,0,-1 , 1};
    
    pair<int , int> start;
    pair<int , int> goal;
    
    for(int i =0; i<n; ++i){
        for(int j =0; j<m; j++){
            if(board[i][j] =='R') start = {i , j};
            if(board[i][j] == 'G') goal = { i , j};
        }
    }
    
    queue<tuple<int , int , int>> q; // x , y , 이동횟수
    q.push(make_tuple(start.first , start.second , 0));
    visited[start.first][start.second] = true;
    
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int count = get<2>(q.front());
        q.pop();
        
        if(x == goal.first && y == goal.second){
            return count;
        }
        
        for(int dir =0; dir <4; dir++){
            int nx = x;
            int ny = y;
            
            while(true){
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];
                
                if(tx >= 0 && tx < n && ty >=0 && ty <m && board[tx][ty] != 'D'){
                    nx = tx;
                    ny = ty;
                }else{
                    break;
                }
            }
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_tuple(nx , ny , count+1));
            }
}
    }
    
    return -1;
}