#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    const int m = 1000000;
    int dp1[m] = {0};
    int dp2[m] = {0};
    dp1[0] = money[0];
    dp1[1] = max(money[0] , money[1]);
    for(int i =2; i<n-1; ++i){
        dp1[i] = max(dp1[i-2] + money[i] , dp1[i-1]);
    }
    dp2[1] = money[1];
    dp2[2] = max(money[1] , money[2]);
    for(int i = 3; i<n; ++i){
        dp2[i] = max(dp2[i-2]+ money[i] , dp2[i-1]);
    }
    
    answer = max(dp1[n-2] , dp2[n-1]);
    return answer;
}