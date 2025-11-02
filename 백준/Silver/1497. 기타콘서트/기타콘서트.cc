#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if(!(cin >> N >> M)) return 0;
    vector<unsigned long long> masks(N, 0);
    for (int i = 0; i < N; ++i) {
        string name, s;
        cin >> name >> s;
        unsigned long long m = 0;
        for (int j = 0; j < M; ++j) if (s[j] == 'Y') m |= (1ULL << j);
        masks[i] = m;
    }
    int bestCnt = INT_MAX, maxSongs = 0;
    for (int mask = 1; mask < (1 << N); ++mask) {
        unsigned long long cover = 0;
        int cnt = __builtin_popcount(mask);
        if (cnt >= bestCnt && maxSongs == M) continue;
        for (int i = 0; i < N; ++i) if (mask & (1 << i)) cover |= masks[i];
        int songs = __builtin_popcountll(cover);
        if (songs > maxSongs) { maxSongs = songs; bestCnt = cnt; }
        else if (songs == maxSongs) bestCnt = min(bestCnt, cnt);
    }
    if (maxSongs == 0) cout << -1 << '\n';
    else cout << bestCnt << '\n';
    return 0;
}