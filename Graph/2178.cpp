#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
vector<vector<int> > board;
vector<vector<bool> > visited; // 해당 칸을 방문했는지
vector<vector<int> > dist; // 시작점부터 거리

void bfs(int startX , int startY){
    queue<pair<int , int> > q;
    q.push(make_pair(startX , startY));
    visited[startY][startX] = true;
    dist[startY][startX] =1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i =0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];


            if(new_x >=0 && new_x <m && new_y >=0 && new_y <n && board[new_y][new_x] == 1 && visited[new_y][new_x] == false){
                q.push(make_pair(new_x , new_y));
                visited[new_y][new_x] = true;
                dist[new_y][new_x] = dist[y][x] +1;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    board.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));
    dist.assign(n , vector<int>(m ,0));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            board[i][j] = row[j] - '0';
        }
    }

    bfs(0,0);

    cout << dist[n-1][m-1] <<'\n';

    return 0;
}