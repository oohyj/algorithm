#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<vector<long long>> dp(65, vector<long long>(10, 0));

    // 길이가 1일 때 초기화
    for (int j = 0; j <= 9; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= 64; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    while (T--) {
        int N;
        cin >> N;
        long long result = 0;
        for (int j = 0; j <= 9; ++j) {
            result += dp[N][j];
        }
        cout << result << '\n';
    }

    return 0;
}