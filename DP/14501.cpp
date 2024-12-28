#include <iostream>
#include <vector>

using namespace std;

int resign(vector<int> &dp , vector<pair<int, int> > &li ,int n){
    for(int i =0; i<n; i++){
        for(int j = i+li[i].first; j<=n; j++){
            if(dp[j] < dp[i]+ li[i].second){
                dp[j] = dp[i]+li[i].second;
            }
        }
    }

    return dp[n];
}

int main(){
    int n;
    vector<pair<int , int> > li;
    vector<int> dp;
    cin >> n;
    for(int i =0; i<n; i++){
        int a , b;
        cin >> a >> b;
        li.push_back(make_pair(a , b));
    }

    dp.assign(n+1 , 0);

    int ans = resign(dp , li , n);

    cout << ans <<'\n';

    return 0;

}