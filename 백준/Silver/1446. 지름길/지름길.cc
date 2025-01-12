#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX 1e4+1

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<tuple<int, int, int> > shortcuts;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b <= D && c < (b - a)) { // 지름길이 고속도로를 벗어나지 않고 더 짧은 경우만 저장
            shortcuts.emplace_back(a, b, c);
        }
    }

    vector<int> dist(D + 1, MAX);
    dist[0] = 0; 


    for (int i = 0; i <= D; i++) {
        if (i > 0) {
            dist[i] = min(dist[i], dist[i - 1] + 1); // 일반 도로로 이동
        }
        for (const auto& [start, end, length] : shortcuts) {
            if (i == start) { // 현재 위치가 지름길 시작점이라면
                dist[end] = min(dist[end], dist[start] + length);
            }
        }
    }

    cout << dist[D] << '\n';
    return 0;
}