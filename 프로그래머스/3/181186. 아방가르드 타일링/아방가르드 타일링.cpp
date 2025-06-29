#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DIV 1000000007

vector<long long> dp(100001, 0);
vector<long long> sum(100001, 0);


int solution(int n) {
    sum[1] = dp[1] = 1;
    sum[2] = dp[2] = 3;
    sum[3] = dp[3] = 10;

    for(int i = 4; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] * 2 + dp[i - 3] * 5) % DIV;
        if(i > 4) dp[i] = (dp[i] + sum[i - 4] * 2) % DIV;
        if(i > 5) dp[i] = (dp[i] + sum[i - 5] * 2) % DIV;
        if(i > 6) dp[i] = (dp[i] + sum[i - 6] * 4) % DIV;
        if(i % 3 == 1) dp[i] = (dp[i] + 2) % DIV;
        else if(i % 3 == 2) dp[i] = (dp[i] + 2) % DIV;
        else if(i % 3 == 0) dp[i] = (dp[i] + 4) % DIV;
        sum[i] = (sum[i - 3] + dp[i]) % DIV;
    }
    return dp[n] % DIV;

}