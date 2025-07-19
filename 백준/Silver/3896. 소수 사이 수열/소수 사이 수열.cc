#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1299709;
vector<bool> isPrime(MAX + 2, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= MAX; ++i) {
        if (isPrime[i])
            primes.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        if (isPrime[k]) {
            cout << 0 << '\n';
            continue;
        }
        auto it = upper_bound(primes.begin(), primes.end(), k);
        int right = *it;
        int left = *(it - 1);

        cout << (right - left) << '\n';
    }

    return 0;
}