#include <iostream>
const int MOD = 1e6;
using namespace std;

int main() {
    int N;
    cin >> N;

    // dp[day][L][A]: day일차까지 기록했을 때, 지각 L번, 연속 결석 A번 한 경우의 수
    int dp[1001][2][3] = {}; // 지각(L): 0~1, 연속 결석(A): 0~2

    dp[0][0][0] = 1;

    for (int day = 1; day <= N; ++day) {
        for (int l = 0; l <= 1; ++l) {
            for (int a = 0; a <= 2; ++a) {
                int val = dp[day - 1][l][a];
                if (val == 0) continue;

                // 'O' (출석): 결석 리셋
                dp[day][l][0] = (dp[day][l][0]+ val)% MOD;

                // 'L' (지각): 최대 1번
                if (l < 1)
                    dp[day][l + 1][0] = (dp[day][l+1][0] + val) % MOD;

                // 'A' (결석): 연속 3번 금지 → 2까지만
                if (a < 2)
                    dp[day][l][a + 1] = (dp[day][l][a+1] + val) %MOD;
            }
        }
    }

    int result = 0;
    for (int l = 0; l <= 1; ++l)
        for (int a = 0; a <= 2; ++a)
            result = (result + dp[N][l][a]) % MOD;

    cout << result << '\n';
    return 0;
}