#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, int height) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = current_x + dx[i];
            int new_y = current_y + dy[i];

            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
                if (!visited[new_x][new_y] && board[new_x][new_y] > height) {
                    visited[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
        }
    }
}

int cntSafeArea(int height) {
    int cnt = 0;
    visited.assign(N, vector<bool>(N, false));  

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] > height && !visited[i][j]) {
                bfs(i, j, height);
                ++cnt;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> N;
    board.assign(N, vector<int>(N));

    int max_height = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]);
        }
    }

    int answer = 1;  // 비가 안 오는 경우도 고려

    for (int h = 1; h < max_height; ++h) {
        answer = max(answer, cntSafeArea(h));
    }

    cout << answer << '\n';

    return 0;
}