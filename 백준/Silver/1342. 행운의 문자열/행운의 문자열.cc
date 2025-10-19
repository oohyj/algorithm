#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    sort(s.begin(), s.end());
    long long ans = 0;

    do {
        bool ok = true;
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == s[i-1]) { ok = false; break; }
        }
        if (ok) ++ans;
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << '\n';
    return 0;
}