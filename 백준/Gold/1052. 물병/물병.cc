#include <iostream>

using namespace std;

int countBits(long long x){
    int cnt = 0;
    while( x > 0){
        if( x%2 == 1) cnt++;
        x /= 2;
    }
    return cnt;
}

int main(){

    long long n , k;

    cin >> n >> k;

    if(countBits(n) <= k){
        cout << 0 << '\n';
        return 0;
    }

    long long buy = 0;

    while(countBits(n) > k){
        long long right = 1;
        while(( n & right) == 0)right <<= 1;

        buy += right;
        n += right;
    }

    cout << buy << '\n';
    return 0;
}