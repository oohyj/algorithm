#include <bits/stdc++.h>
using namespace std;

long long N, L_, W_, H_;

bool can(long double a) {
    if (a == 0) return true;
    long long x = (long long)(L_ / a);
    long long y = (long long)(W_ / a);
    long long z = (long long)(H_ / a);
    __int128 prod = (__int128)x * y * z;
    return prod >= N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L_ >> W_ >> H_;

    long double low = 0.0L;
    long double high = min({(long double)L_, (long double)W_, (long double)H_});

    for (int i = 0; i < 100; ++i) {
        long double mid = (low + high) / 2.0L;
        if (can(mid)) low = mid;
        else high = mid;
    }

    cout.setf(ios::fixed);
    cout << setprecision(10) << (long double)low << "\n";
    return 0;
}