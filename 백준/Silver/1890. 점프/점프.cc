#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    vector<vector<long long>> dp(N, vector<long long>(N, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == 0) continue;
            if (board[i][j] == 0) continue;

            int jump = board[i][j];

            if (i + jump < N) {
                dp[i + jump][j] += dp[i][j];
            }

            if (j + jump < N) {
                dp[i][j + jump] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1] << '\n';
    return 0;
}