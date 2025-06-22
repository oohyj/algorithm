#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { -1 , 1 , 0 , 0 };
int dy[] = { 0 , 0 , -1 , 1 };

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N, K, cnt = 0;
        cin >> M >> N >> K;

        vector<vector<int>> board(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        while (K--) {
            int a, b;
            cin >> a >> b;
            board[b][a] = 1;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!visited[i][j] && board[i][j] == 1) {
                    cnt++;
                    visited[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({ i, j });

                    while (!q.empty()) {
                        int current_x = q.front().first;
                        int current_y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; ++k) {  
                            int new_x = current_x + dx[k];
                            int new_y = current_y + dy[k];

                            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M &&
                                !visited[new_x][new_y] && board[new_x][new_y] == 1) {
                                visited[new_x][new_y] = true;  
                                q.push({ new_x, new_y });
                            }
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}