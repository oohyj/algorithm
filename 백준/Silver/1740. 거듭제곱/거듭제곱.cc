#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long N;
    if (!(cin >> N)) return 0;

  
    vector<int> bits;
    while (N > 0) {
        bits.push_back(N & 1u); 
        N >>= 1;
    }
    reverse(bits.begin(), bits.end()); 
    unsigned long long res = 0;
    for (int b : bits) {
        res = res * 3ull + (unsigned long long)b;
    }

    cout << res << "\n";
    return 0;
}