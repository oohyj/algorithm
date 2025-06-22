#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 10001;

vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int dist[MAX];

pair<int, int> bfs(int start) {
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    queue<int> q;
    q.push(start);
    visited[start] = true;

    int maxNode = start;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto next : graph[curr]) {
            int nextNode = next.first;
            int weight = next.second;
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                dist[nextNode] = dist[curr] + weight;
                q.push(nextNode);
                if (dist[nextNode] > dist[maxNode]) {
                    maxNode = nextNode;
                }
            }
        }
    }

    return {maxNode, dist[maxNode]};
}

int main() {
    int u, v, w;
    while (cin >> u >> v >> w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }


    pair<int, int> first = bfs(1);
   
    pair<int, int> result = bfs(first.first);

    cout << result.second << '\n';

    return 0;
}