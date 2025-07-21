#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);
    vector<int> time(N + 1);
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int t, cnt;
        cin >> t >> cnt;
        time[i] = t;

        for (int j = 0; j < cnt; ++j) {
            int pre;
            cin >> pre;
            graph[pre].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            dp[i] = time[i];
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int next : graph[now]) {

            dp[next] = max(dp[next], dp[now] + time[next]);

            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }


    int answer = *max_element(dp.begin() + 1, dp.end());
    cout << answer << '\n';

    return 0;
}