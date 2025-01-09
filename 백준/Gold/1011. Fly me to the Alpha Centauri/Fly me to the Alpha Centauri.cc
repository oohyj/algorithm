#include <iostream>

using namespace std;

int alpha_centauri(long long x, long long y) {

    long long max = 0, move = 0;

    while (max * max <= y - x) {
        max++;
    }
    max--; // 루프를 초과한 상태에서 종료했으므로 1 감소

    move = 2 * max - 1;

    long long rem = y - x - (max * max);
    rem = (rem + max - 1) / max;

    move += rem;
    return move;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long x, y;
        cin >> x >> y;
        cout << alpha_centauri(x, y) << '\n';
    }
    return 0;
}