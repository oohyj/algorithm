#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int left = 0, right = 0;
    int odd_count = 0, max_length = 0;

    while (right < N) {
        if (A[right] % 2 == 1) {
            ++odd_count;
        }

        while (odd_count > K) {
            if (A[left] % 2 == 1) {
                --odd_count;
            }
            ++left;
        }

        max_length = max(max_length, right - left + 1 - odd_count);
        ++right;
    }

    cout << max_length << '\n';
    return 0;
}