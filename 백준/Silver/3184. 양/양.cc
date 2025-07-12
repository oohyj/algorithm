#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C;
vector<string> yard;
bool visited[250][250];

int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, int& sheep, int& wolf) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int local_sheep = 0, local_wolf = 0;

    if (yard[x][y] == 'o') local_sheep++;
    else if (yard[x][y] == 'v') local_wolf++;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
                !visited[nx][ny] && yard[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});

                if (yard[nx][ny] == 'o') local_sheep++;
                else if (yard[nx][ny] == 'v') local_wolf++;
            }
        }
    }

    if (local_sheep > local_wolf) {
        sheep += local_sheep;
    } else {
        wolf += local_wolf;
    }
}

int main() {
    cin >> R >> C;
    yard.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> yard[i];
    }

    int total_sheep = 0, total_wolf = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && yard[i][j] != '#') {
                int sheep = 0, wolf = 0;
                bfs(i, j, sheep, wolf);
                total_sheep += sheep;
                total_wolf += wolf;
            }
        }
    }

    cout << total_sheep << " " << total_wolf << '\n';
    return 0;
}