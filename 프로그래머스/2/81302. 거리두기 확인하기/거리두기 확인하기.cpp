#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isSafe(const vector<string>& room , int x , int y){
    int dx[4] = {1 , -1 , 0, 0};
    int dy[4] = {0 , 0 , 1 , -1};
    
    queue<pair<pair<int , int> , int>> q;
    q.push(make_pair(make_pair(x , y), 0));
    
    vector<vector<bool>> visited(5 , vector<bool>(5 , false));
    visited[x][y] = true;
    
    while(!q.empty()){
        pair<pair<int , int> , int> front = q.front(); q.pop();
        pair<int , int> cur = front.first;
        int dist = front.second;
        int cx = cur.first;
        int cy = cur.second;
        
        if(dist >= 1 && room[cx][cy] == 'P') return false;
        if(dist == 2) continue;
        
        for(int dir =0; dir <4; ++ dir){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >=5 || ny >=5) continue;
            if(visited[nx][ny] || room [nx][ny] == 'X') continue;
            
            visited[nx][ny] = true;
            q.push(make_pair(make_pair(nx , ny) , dist+1));
            
        }
    }
    return true;
}



vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(const auto& room : places){
        bool ok = true;
        for(int i =0; i<5 && ok; ++i){
            for(int j =0; j<5 && ok; ++j){
                if(room[i][j] == 'P'){
                    if(!isSafe(room , i , j)){
                        ok = false;
                        break;
                    }
                }
            }
        }
        answer.push_back(ok? 1 : 0);
    }
    return answer;
}