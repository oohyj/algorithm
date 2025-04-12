#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N , M;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dx[] = {-1, -1, -1,  0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1,-1, 0, 1};

bool bfs(int x , int y){
    bool isPeak = true;
    queue<pair<int , int>> q;
    q.push({x , y});
    visited[x][y] = true;

    while(!q.empty()){
        int current_x = q.front().first;
        int current_y = q.front().second;

        q.pop();

        for(int i =0; i<8; ++i){
            int new_x = current_x + dx[i];
            int new_y = current_y + dy[i];


            if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) {
                continue;
            }

            if (board[new_x][new_y] > board[current_x][current_y]) {
                isPeak = false;
            }

            if (!visited[new_x][new_y] && board[new_x][new_y] == board[current_x][current_y]) {
                visited[new_x][new_y] = true;
                q.push({new_x , new_y});
            }


        }

    }
    return isPeak;
}

int main(){

    cin >> N >>M;

    board.assign(N , vector<int>(M));
    visited.assign(N , vector<bool>(M));

    for(int i = 0; i<N; ++i){
        for(int j =0; j<M; ++j){
             cin >> board[i][j];
        }
    }

    int answer = 0;

    for(int i =0; i <N; ++i){
        for(int j =0; j<M; ++j){
            if(!visited[i][j] ){
                bool isPeak = bfs(i , j);
                if(isPeak){
                    ++answer;
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}