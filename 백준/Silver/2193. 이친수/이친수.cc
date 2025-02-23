#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;

    ll dp[91];
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N] << '\n';
    return 0;
}
