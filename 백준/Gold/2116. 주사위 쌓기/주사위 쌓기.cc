#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<array<int, 6>> dice(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    int opp[6] = {5, 3, 4, 1, 2, 0};
    int answer = 0;

    for (int start = 0; start < 6; start++) {
        int sum = 0;

        int bottomIdx = start;
        int topIdx = opp[start];
        int prevTopValue = dice[0][topIdx];

        int mx = 0;
        for (int i = 0; i < 6; i++) {
            if (i != bottomIdx && i != topIdx) {
                mx = max(mx, dice[0][i]);
            }
        }
        sum += mx;

        for (int i = 1; i < N; i++) {
            int b = 0, t = 0;
            for (int j = 0; j < 6; j++) {
                if (dice[i][j] == prevTopValue) {
                    b = j;
                    t = opp[j];
                    break;
                }
            }

            int curMax = 0;
            for (int j = 0; j < 6; j++) {
                if (j != b && j != t) {
                    curMax = max(curMax, dice[i][j]);
                }
            }

            sum += curMax;
            prevTopValue = dice[i][t];
        }

        answer = max(answer, sum);
    }

    cout << answer << "\n";
    return 0;
}