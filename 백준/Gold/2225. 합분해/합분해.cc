#include <iostream>

using namespace std;

int main(){

    int N , K;
    cin >> N >> K;

    const int MOD = 1000000000;

    int dp[201][201]={0};

    for(int i =0; i<=N; ++i){
       dp[i][1] = 1;
    }

    for(int k =2; k<=K; ++k){
        for(int n =0; n <= N ; ++n){
            for(int x = 0; x <=n; ++x){
                dp[n][k] = (dp[n][k] + dp[n-x][k-1]) % MOD;
            }
        }
    }

    cout << dp[N][K] <<'\n';
    return 0;
}