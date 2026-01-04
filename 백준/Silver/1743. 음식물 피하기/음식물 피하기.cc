#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N , M;
int max_size = 0;
vector<vector<int>> aisle;
vector<vector<bool>> visited;
int dx[] = { -1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};

int dfs(int x , int y)
{
    int cnt = 1;

    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visited[nx][ny]) continue;
        if (aisle[nx][ny] == 1)
        {
            visited[nx][ny] = true;
            cnt += dfs(nx , ny);
        }
    }

    return cnt;

}
int main()
{
    int  K;
    cin >> N >> M >> K;
    aisle.assign(N , vector<int>(M , 0));
    visited.assign(N , vector<bool>(M , false));
    for (int i = 0; i < K; ++i)
    {
        int r  , c;
        cin >> r >> c;
        aisle[r-1][c-1] = 1;
    }

    for (int i = 0; i< N; ++i)
    {
        for (int j = 0; j<M; ++j)
        {
            if (aisle[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = true;
                int result = dfs(i , j);
                max_size = max(max_size , result);
            }
        }
    }

    cout << max_size << '\n';

    return 0;
}
