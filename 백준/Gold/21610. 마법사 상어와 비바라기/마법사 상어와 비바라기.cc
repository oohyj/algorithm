#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<pair<int, int>> loc; // 구름 위치

// 방향: ←, ↖, ↑, ↗, →, ↘, ↓, ↙ (1~8 → 0~7)
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void plusWater(int cnt, int x, int y) {
    board[x][y] += cnt;
}

void checkWater() {
    for (auto& iter : loc) {
        int cnt = 0;
        for (int i = 1; i < 8; i += 2) { // 대각선만 (1,3,5,7)
            int nx = iter.first + dx[i];
            int ny = iter.second + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] > 0) {
                ++cnt;
            }
        }
        plusWater(cnt, iter.first, iter.second);
    }
}

void moveBoard(int d, int s) {
    vector<pair<int, int>> new_loc;

    for (auto& iter : loc) {
        int nx = (iter.first + dx[d] * s + N * s) % N;
        int ny = (iter.second + dy[d] * s + N * s) % N;
        new_loc.push_back({nx, ny});
    }

    loc = new_loc;

    // 이동한 위치에 물 1 증가
    for (auto& iter : loc) {
        plusWater(1, iter.first, iter.second);
    }
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(N));

    // 초기 구름 위치
    loc.push_back({N - 1, 0});
    loc.push_back({N - 1, 1});
    loc.push_back({N - 2, 0});
    loc.push_back({N - 2, 1});

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    while (M--) {
        int d, s;
        cin >> d >> s;
        d = (d - 1 + 8) % 8; // 입력 d (1~8) → 인덱스 보정 (0~7)

        moveBoard(d, s);
        checkWater();

        vector<vector<bool>> isCloud(N, vector<bool>(N, false));
        for (auto& iter : loc) {
            isCloud[iter.first][iter.second] = true;
        }

        loc.clear();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!isCloud[i][j] && board[i][j] >= 2) {
                    loc.push_back({i, j});
                    board[i][j] -= 2;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            answer += board[i][j];
        }
    }

    cout << answer << '\n';

    return 0;
}