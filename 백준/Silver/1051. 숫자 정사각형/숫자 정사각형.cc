#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    int maxLen = min(N, M);   

  
    for (int len = maxLen; len >= 1; --len) {
       
        for (int i = 0; i + len - 1 < N; ++i) {
            for (int j = 0; j + len - 1 < M; ++j) {
                char c = board[i][j];
            
                if (board[i][j + len - 1] == c &&
                    board[i + len - 1][j] == c &&
                    board[i + len - 1][j + len - 1] == c) {
                    cout << len * len << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 1 << "\n";
    return 0;
}