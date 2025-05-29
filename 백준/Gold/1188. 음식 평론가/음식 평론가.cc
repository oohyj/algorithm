#include <iostream>

using namespace std;

int gcd(int a , int b){
    while(b != 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }

    return a;
}

int main(){

    int N , M;
    cin >> N >> M;

    int answer = M - gcd(N , M) ;
    cout << answer << '\n';

    return 0;
}