#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n , cnt =0 , cur =1;
    cin >> n;

    while((cur << 1) < n){
        cur <<=1;
    }
    while(n>2){
        n-=cur , cnt++;
        while(n <= cur){
            cur >>=1;
        }
    }

    n ==1 ? cout << cnt%2 : cout << (cnt+1)%2;
}
