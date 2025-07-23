#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(V + 1);
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(V + 1, 0);
        bool flag = false;

        for (int i = 1; i <= V; ++i) {
            if (color[i] != 0) continue; // 이미 방문했으면 패스

            queue<int> q;
            color[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int current = q.front(); q.pop();
                for (const auto& next : graph[current]) {
                    if (color[next] == 0) {
                        color[next] = -color[current];
                        q.push(next);
                    } else if (color[next] == color[current]) {
                        cout << "NO" << '\n';
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }

            if (flag) break;
        }

        if (!flag) {
            cout << "YES" << '\n';
        }
    }

    return 0;
}