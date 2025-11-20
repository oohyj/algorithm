#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = sqrt((double)(x1 - x2) * (x1 - x2) +
                        (double)(y1 - y2) * (y1 - y2));

       
        if (d == 0 && r1 == r2) {
            cout << -1 << "\n";
            continue;
        }

        if (d > r1 + r2 || d < abs(r1 - r2)) {
            cout << 0 << "\n";
            continue;
        }

        if (d == r1 + r2 || d == abs(r1 - r2)) {
            cout << 1 << "\n";
            continue;
        }


        cout << 2 << "\n";
    }

    return 0;
}