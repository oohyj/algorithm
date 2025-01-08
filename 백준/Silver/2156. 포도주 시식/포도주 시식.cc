#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int N;
    vector<int> wine;
    vector<int> dp;

    cin >> N;

    wine.assign(N, 0);
    dp.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> wine[i];
    }

    if (N == 1) {
        cout << wine[0] << '\n';
        return 0;
    } 
    else if (N == 2) {
        cout << wine[0] + wine[1] << '\n';
        return 0;
    }

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max({wine[0] + wine[2], wine[1] + wine[2], dp[1]});

    for (int i = 3; i < N; i++) {
        dp[i] = max({dp[i-1], dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]});
    }

    cout << dp[N-1] << '\n';

    return 0;
}