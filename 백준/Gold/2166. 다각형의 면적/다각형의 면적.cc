#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        ll x1 = points[i].first;
        ll y1 = points[i].second;
        ll x2 = points[(i + 1) % n].first;
        ll y2 = points[(i + 1) % n].second;

        sum1 += x1 * y2;
        sum2 += x2 * y1;
    }

    double area = abs(sum1 - sum2) / 2.0;

    cout << fixed << setprecision(1) << area << '\n';

    return 0;
}