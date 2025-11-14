#include <bits/stdc++.h>
using namespace std;

bool isInside(int x, int y, int cx, int cy, int r) {
    long long dx = x - cx;
    long long dy = y - cy;
    long long dist2 = dx * dx + dy * dy;
    long long r2 = 1LL * r * r;
    return dist2 < r2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        int answer = 0;

        for (int i = 0; i < n; ++i) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool startIn = isInside(x1, y1, cx, cy, r);
            bool endIn   = isInside(x2, y2, cx, cy, r);

          
            if (startIn ^ endIn) {
                ++answer;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}