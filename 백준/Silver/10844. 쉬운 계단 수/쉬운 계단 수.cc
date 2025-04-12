#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9;

int main(){

    int N;
    cin >> N;

    vector<vector<int>> dp(N+1 , vector<int>(10, 0));

    for(int j = 1; j <= 9 ; ++j){
        dp[1][j] = 1;
    }

    for(int i = 2; i <= N; ++i){
       for(int j =0; j<=9; ++j){
           if(j > 0){
               dp[i][j] += dp[i-1][j-1];
               dp[i][j] %= MOD;
           }
           if(j < 9){
               dp[i][j] += dp[i-1][j+1];
               dp[i][j] %= MOD;
           }
       }
    }

    int answer = 0;
    for(int i =0; i<=9; ++i){
        answer = (answer +dp[N][i] ) % MOD;
    }


    cout << answer << '\n';
    return 0;
}
