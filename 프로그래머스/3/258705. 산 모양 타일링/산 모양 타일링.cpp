#include <vector>
using namespace std;

int solution(int n, vector<int> tops) {
    const int MOD = 10007;
    int size = 2 * n + 3; // 삼각형 인덱스는 최대 2n+2까지 접근
    vector<int> dp(size, 0);

    dp[1] = 1; // 삼각형 1개만 있는 경우
    dp[2] = 2; // 삼각형 2개일 때 (삼각형 2개 or 마름모)

    for (int i = 1; i <= n; ++i) {
        int idx = 2 * i;

        if (tops[i - 1] == 1) {
            // 위 삼각형이 붙어있는 경우
            dp[idx + 1] = (2 * dp[idx - 1] + dp[idx]) % MOD;
            dp[idx] = (dp[idx] + dp[idx - 1]) % MOD; // 아래만 덮기
        } else {
            // 위 삼각형이 없는 경우
            dp[idx + 1] = (dp[idx - 1] + dp[idx]) % MOD;
        }

        // 다음 칸 전체까지의 누적 경우의 수
        dp[idx + 2] = (dp[idx] + dp[idx + 1]) % MOD;
    }

    return dp[2 * n + 1];
}