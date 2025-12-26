#include <bits/stdc++.h>
using namespace std;

struct Word {
    string s;
    int idx;
};

int commonPrefix(const string& a, const string& b) {
    int len = min(a.size(), b.size());
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] == b[i]) cnt++;
        else break;
    }
    return cnt;
}


bool samePrefixLen(const string& a, const string& b, int L) {
    if (L == 0) return true;

    return a.compare(0, L, b, 0, L) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> original(N);
    vector<Word> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> original[i];
        v[i] = { original[i], i };
    }

    sort(v.begin(), v.end(), [](const Word& a, const Word& b) {
        return a.s < b.s;
    });


    int bestLen = 0;
    for (int i = 0; i < N - 1; ++i) {
        bestLen = max(bestLen, commonPrefix(v[i].s, v[i + 1].s));
    }

    int ansS = N, ansT = N;

    int i = 0;
    while (i < N) {
        int j = i;

        while (j + 1 < N && samePrefixLen(v[i].s, v[j + 1].s, bestLen)) {
            ++j;
        }

        if (j - i + 1 >= 2) {
            int min1 = N, min2 = N;
            for (int k = i; k <= j; ++k) {
                int id = v[k].idx;
                if (id < min1) { min2 = min1; min1 = id; }
                else if (id < min2) { min2 = id; }
            }

            int S = min1, T = min2;
            if (S < ansS || (S == ansS && T < ansT)) {
                ansS = S;
                ansT = T;
            }
        }

        i = j + 1;
    }

    cout << original[ansS] << '\n';
    cout << original[ansT] << '\n';
    return 0;
}