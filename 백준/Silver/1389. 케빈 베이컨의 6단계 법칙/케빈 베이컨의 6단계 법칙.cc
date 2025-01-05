#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > friends;
vector<int> answer;

void bfs(int start, int N) {
    queue<pair<int, int> > q;
    vector<bool> visited(N + 1, false);

    q.push(make_pair(start, 0));
    visited[start] = true;

    while (!q.empty()) {
        int current_v = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int j = 1; j <= N; j++) {
            if (friends[current_v][j] == 1 && !visited[j]) {
                visited[j] = true;
                q.push(make_pair(j, dist + 1));
                answer[start] += dist + 1;  // 거리 누적
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    friends.assign(N + 1, vector<int>(N + 1, 0));
    answer.assign(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        bfs(i, N);
    }

    int min_value = 1e9, min_index = 0;
    for (int i = 1; i <= N; i++) {
        if (answer[i] < min_value) {
            min_value = answer[i];
            min_index = i;
        }
    }

    cout << min_index << '\n';
    return 0;
}