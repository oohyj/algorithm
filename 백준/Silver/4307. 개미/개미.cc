#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int L, n;
        cin >> L >> n;

        int pos;
        int minTime = 0;
        int maxTime = 0;

        for (int i = 0; i < n; i++) {
            cin >> pos;
            int left = pos;
            int right = L - pos;

            minTime = max(minTime, min(left, right));
            maxTime = max(maxTime, max(left, right));
        }

        cout << minTime << " " << maxTime << "\n";
    }

    return 0;
}