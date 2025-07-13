#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<pair<int , int>> players;

    int white , black;

    while(cin >> white >> black){
        players.push_back({white , black}); // first가 백 , second가 흑
    }

    int n = players.size();
    const int MAX = -1e9;

    // i번째까지 고려했을 때 j는 백의 개수 k는 흑의 개수
    vector<vector<vector<int>>> dp(n+1 ,vector<vector<int>>(16 , vector<int>(16 , MAX)));

    dp[0][0][0] = 0;

    for(int i = 0; i<n; ++i){
        for(int j = 0; j <16; ++j){
            for(int k = 0; k<16; ++k){
               if(dp[i][j][k] == MAX) continue;
               // 흑 , 백 둘 다 안고를꺼면
               dp[i+1][j][k] = max(dp[i+1][j][k] , dp[i][j][k]);
               // 백 골랐을 때
               if(j < 15) dp[i+1][j+1][k] = max(dp[i+1][j+1][k] , dp[i][j][k]+ players[i].first);
                // 흑 골랐을 때
                if(k <15) dp[i+1][j][k+1] = max(dp[i+1][j][k+1] , dp[i][j][k]+ players[i].second);
            }
        }
    }


    cout << dp[n][15][15] << '\n';



    return 0;
}