#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main(){
    int C , N;
    cin >> C >> N;

    vector<pair<int , int>> cities(N);

    for(int i =0; i<N; ++i){
        cin >> cities[i].first >> cities[i].second;
    }

    int maxCustomer = C+100;
    vector<int> dp(maxCustomer+1 , INF);
    dp[0] = 0;

    for(int i = 0; i<N; ++i){
        int cost = cities[i].first;
        int customer = cities[i].second;
        for(int j = customer; j <= maxCustomer; ++j){
            dp[j] = min(dp[j] , dp[j-customer]+cost);
        }
    }
    
    int result = INF;
    for(int i =C; i <= maxCustomer; ++i){
        result = min(result , dp[i]);
    }
    
    cout << result << '\n';
    
    return 0;
}