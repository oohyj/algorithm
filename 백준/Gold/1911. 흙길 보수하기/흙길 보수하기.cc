#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N;
    long long L;
    cin >> N >> L;

    vector<pair<long long, long long>> puddles(N);
    for (int i = 0; i < N; ++i) {
        long long start, end;
        cin >> start >> end;
        puddles[i] = {start, end};
    }

    sort(puddles.begin(), puddles.end()); 

    long long cur = 0; 
    long long answer = 0;

    for (auto &p : puddles) {
        long long s = p.first, e = p.second;

        if (cur < s) cur = s; 
        if (cur >= e) continue; 

        long long need = e - cur; 
        long long cnt = (need + L - 1) / L; 
        answer += cnt;
        cur += cnt * L; 
    }

    cout << answer << '\n';
    return 0;
}