#include <iostream>
#include <cmath>

using namespace std;

int dp[50001]; //4가지 이하의 제곱수의 경우
int main(){

    int n;

    cin >> n;

    for(int i =1; i<=sqrt( 50000) ; i++){
        dp[i*i] =1;
    }

    for(int i=1; i<=n; i++){
        int min = 5;
        if(dp[i] != 1){
            for(int j =1; j<= sqrt(i); j++){
                int a = dp[j*j] + dp[i-j*j];
                if(min >a){
                    min = a;
                    dp[i] = a;
                }

            }
        }
    }

    cout << dp[n];
    return 0;
}
