#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> isVisited;
int M, N, K;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void mark(int a, int b, int c, int d) {
    for (int i = b; i < d; ++i) {       
        for (int j = a; j < c; ++j) {  
            board[i][j] = 0; 
        }
    }
}

int bfs(int x, int y) {
    isVisited[x][y] = true;
    queue<pair<int, int>> q;
    int cnt = 1;
    q.push({x, y});

    while (!q.empty()) {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int new_x = current_x + dx[i];
            int new_y = current_y + dy[i];

            if (new_x >= 0 && new_x < M && new_y >= 0 && new_y < N &&
                !isVisited[new_x][new_y] && board[new_x][new_y] == 1) {
                isVisited[new_x][new_y] = true;
                cnt++;
                q.push({new_x, new_y});
            }
        }
    }

    return cnt;
}

int main() {
    cin >> M >> N >> K;

    board.assign(M, vector<int>(N, 1));
    isVisited.assign(M, vector<bool>(N, false));

    for (int i = 0; i < K; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mark(a, b, c, d);
    }

    int count = 0;
    vector<int> area;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!isVisited[i][j] && board[i][j] == 1) {
                count++;
                area.push_back(bfs(i, j));
            }
        }
    }

    sort(area.begin(), area.end());

    cout << count << '\n';
    for (auto& a : area) {
        cout << a << ' ';
    }
    

    return 0;
}