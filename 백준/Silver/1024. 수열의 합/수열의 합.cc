#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int L;
    cin >> N >> L;

    for (int k = L; k <= 100; ++k) {
        long long temp = N - (long long)k * (k - 1) / 2;
        if (temp < 0) continue;

        if (temp % k == 0) {
            long long x = temp / k;
            if (x >= 0) {
                for (int i = 0; i < k; ++i) {
                    cout << x + i;
                    if (i + 1 < k) cout << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}