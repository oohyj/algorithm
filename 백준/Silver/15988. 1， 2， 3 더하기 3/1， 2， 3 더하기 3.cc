#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1'000'000'009;

int main(){
    int T;
    cin >>T;

    vector<int> query(T , 0);

    int mx = 0;

    for(int i =0; i<T; ++i){
        int n;
        cin >> n;
        query[i] = n;
        mx = max(mx , n);
    }
    
    vector<int> dp(max(4, mx + 1), 0);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i =4; i<=mx; ++i){
        long long s = ((long long)dp[i-1] + dp[i-2]) % MOD;
        s =(s+dp[i-3]) %MOD;
        dp[i] = (int) s;
    }

    for(int n : query){
        cout << dp[n] << '\n';
    }

    return 0;
}