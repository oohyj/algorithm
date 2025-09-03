#include <iostream>
#include <vector>
using namespace std;


int main(){

    const int MOD = 1000000000;

    int N;
    cin >> N;

    vector<int> dp(N+1 , 0);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i<=N; ++i){
        long long s = dp[i-2];
        s += dp[i-1];
        if(s >= MOD) s -= MOD;

        long long cur = (long long)(i-1) * s %MOD;
        dp[i] = (int) cur;
    }

    cout << dp[N] << '\n';
    return 0;
}