#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxVolume(int N, int S, int M, vector<int>& V) {

    vector<vector<bool> > dp(N + 1, vector<bool>(M + 1, false));
    dp[0][S] = true; 
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (dp[i - 1][j]) {
                if (j + V[i - 1] <= M) {
                    dp[i][j + V[i - 1]] = true;
                }
                if (j - V[i - 1] >= 0) {
                    dp[i][j - V[i - 1]] = true;
                }
            }
        }
    }

    int maxVolume = -1;
    for (int j = 0; j <= M; ++j) {
        if (dp[N][j]) {
            maxVolume = max(maxVolume, j);
        }
    }

    return maxVolume;
}

int main() {
    int N, S, M;
    cin >> N >> S >> M;

    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    int result = maxVolume(N, S, M, V);
    cout << result << '\n';

    return 0;
}