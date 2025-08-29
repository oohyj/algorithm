#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> a, dp;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int dfs(int y, int x) {
    int &ret = dp[y][x];
    if (ret) return ret;          
    ret = 1;                  

    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (a[ny][nx] > a[y][x]) {
            ret = max(ret, 1 + dfs(ny, nx));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    a.assign(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> a[i][j];

    dp.assign(N, vector<int>(N, 0));

    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans = max(ans, dfs(i, j));

    cout << ans << '\n';
    return 0;
}