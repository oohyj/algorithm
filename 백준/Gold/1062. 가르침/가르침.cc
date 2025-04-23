#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K, result = 0;
vector<int> wordMask;

int canReadable(int learned) {
    int cnt = 0;
    for (int mask : wordMask) {
        if ((mask & learned) == mask) cnt++;
    }

    if (cnt == N) {
        cout << N << '\n';
        exit(0);
    }
    return cnt;
}

void backtrack(int index, int depth, int learned) {
    if (depth == K - 5) {
        result = max(result, canReadable(learned));
        return;
    }

    for (int i = index; i < 26; ++i) {
        if (!(learned & (1 << i))) {
            backtrack(i + 1, depth + 1, learned | (1 << i));
        }
    }
}

int main() {
    cin >> N >> K;

    if (K < 5) {
        cout << "0\n";
        return 0;
    }

    wordMask.resize(N);
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        int bit = 0;
        for (int j = 4; j < str.size() - 4; ++j) { // anta, tica 제거
            bit |= (1 << (str[j] - 'a'));
        }
        wordMask[i] = bit;
    }

   
    int learned = 0;
    learned |= (1 << ('a' - 'a'));
    learned |= (1 << ('c' - 'a'));
    learned |= (1 << ('i' - 'a'));
    learned |= (1 << ('n' - 'a'));
    learned |= (1 << ('t' - 'a'));

    backtrack(0, 0, learned);

    cout << result << '\n';
    return 0;
}