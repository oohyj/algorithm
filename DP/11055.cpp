#include <iostream>

using namespace std;

int main(){
    int n , sum =0;
    int a[1001], dp[1001];
    cin >> n;

    for(int i =0; i<n; i++){
        cin >> a[i];
        dp[i] = a[i];
        for(int j=0; j<i; j++){
            if(a[i] > a[j]){
               dp[i] = max(dp[i] , dp[j] + a[i]);
            }
        }
    }

    for(int i=0; i<n; i++){
       sum = max(sum , dp[i]);
    }

    cout << sum <<"\n";

    return 0;
}