#include <iostream>

using namespace std;

typedef  long long ll;

int main(){
    ll N , K;
    cin >> N >> K;

    ll low = 0;
    ll high = N/2;
    ll mid;
    bool ans = false;

    while(low <= high){
        mid = (low + high)/2;

        ll cnt = (mid+1)*(N-mid+1);
        if(cnt == K){
            ans = true;
            break;
        }
        else if(cnt > K){
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    if(ans) cout << "YES" ;
    else cout << "NO";

    return 0;
}