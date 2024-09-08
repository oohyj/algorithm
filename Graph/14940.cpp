#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n , m;
vector<vector<int> > board;
vector<vector<int> > result;
vector<vector<bool> > visited;
int dx[] = { 1 , 0 , -1 , 0};
int dy[] = { 0 , 1 , 0 , -1};

void bfs(int x , int y){
    queue<pair<int , int> > q;
    q.push(make_pair(x , y));
    visited[x][y] = true;
    result[x][y] = 0;

    while(!q.empty()){

        pair<int , int> cur_pair = q.front();
        for(int v =0;  v<4 ; v++){
            int x_next = cur_pair.first + dx[v];
            int y_next = cur_pair.second+ dy[v];

            if(x_next <0 || x_next >= n || y_next <0 || y_next >=m){
                continue;
            }

            if(board[x_next][y_next] == 1 && !visited[x_next][y_next]){
                q.push(make_pair(x_next , y_next));
                visited[x_next][y_next] = true;
                result[x_next][y_next] = result[cur_pair.first][cur_pair.second]+1;
            }
        }

        q.pop();
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int  x , y;
    cin >> n >> m;
    board.assign(n , vector<int>(m, 0));
    result.assign(n , vector<int>(m , 0));
    visited.assign(n , vector<bool>(m , false));

    for(int i =0; i<n;i++){
        for(int j =0; j<m; j++){
            int a;
            cin >> a;
             board[i][j] = a;

            if(a == 2){
                x = i;
                y = j;
            }
        }
    }

    bfs( x , y);

    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if (result[i][j] == 0 && board[i][j] == 1)
                cout << -1 << ' ';
            else
                cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

   return 0;

}
