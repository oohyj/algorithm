#include <iostream>

using namespace std;

long long modExp(long long base, long long exp, long long mod) {
    if (exp == 0) return 1; // A^0 = 1
    long long half = modExp(base, exp / 2, mod); // 분할정복
    half = (half * half) % mod; // 제곱 결과에 mod 적용

    if (exp % 2 != 0) { // 홀수라면 base를 한 번 더 곱함
        half = (half * base) % mod;
    }
    return half;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    cout << modExp(A, B, C) << '\n';

    return 0;
}