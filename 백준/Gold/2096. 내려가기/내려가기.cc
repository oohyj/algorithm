#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int a, b, c;
    int max_prev[3], min_prev[3], max_curr[3], min_curr[3];

    cin >> max_prev[0] >> max_prev[1] >> max_prev[2];
    min_prev[0] = max_prev[0];
    min_prev[1] = max_prev[1];
    min_prev[2] = max_prev[2];

    for (int i = 1; i < N; ++i) {
        cin >> a >> b >> c;

        max_curr[0] = max(max_prev[0], max_prev[1]) + a;
        max_curr[1] = max({max_prev[0], max_prev[1], max_prev[2]}) + b;
        max_curr[2] = max(max_prev[1], max_prev[2]) + c;

        min_curr[0] = min(min_prev[0], min_prev[1]) + a;
        min_curr[1] = min({min_prev[0], min_prev[1], min_prev[2]}) + b;
        min_curr[2] = min(min_prev[1], min_prev[2]) + c;

        for (int j = 0; j < 3; ++j) {
            max_prev[j] = max_curr[j];
            min_prev[j] = min_curr[j];
        }
    }

    int max_answer = max({max_prev[0], max_prev[1], max_prev[2]});
    int min_answer = min({min_prev[0], min_prev[1], min_prev[2]});

    cout << max_answer << " " << min_answer << '\n';
    return 0;
}