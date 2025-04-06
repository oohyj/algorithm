#include <iostream>
#include <vector>

using namespace std;

int R , C , K;
int answer = 0;
vector<vector<char>> board;
vector<vector<bool>> visited;
int dx[] = {1 , -1 , 0 , 0};
int dy[] = { 0 , 0 , 1 , -1};
void dfs(int x , int y ,int cnt){

    if (cnt == K && x == 0 && y == C - 1) {
       answer++;
        return;
    }

    visited[x][y] = true;
    for(int i = 0; i<4; i++){
        int nx = x+ dx[i];
        int ny = y + dy[i];
        if(nx >=0 && nx < R && ny >=0 && ny < C && board[nx][ny] != 'T' && !visited[nx][ny]){
            dfs(nx , ny , cnt+1);
        }
    }
    visited[x][y] = false;

}

int main(){

    cin >> R >> C >> K;

    board.assign(R , vector<char>(C));
    visited.assign(R , vector<bool>(C , false));

    for(int i =0; i<R; ++i){
        for(int j =0; j <C; ++j){
            cin >> board[i][j];
        }
    }


    dfs(R-1 , 0, 1);

    cout << answer << '\n';
    return 0;
}
