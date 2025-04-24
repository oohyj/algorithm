#include <iostream>
using namespace std;

int N;
double result = 0.0;
double dir[4]; // 동, 서, 남, 북 확률
const int SIZE = 30;
bool visited[SIZE][SIZE] = {false};
int dx[] = { 1 , -1 , 0 , 0};
int dy[] = { 0 , 0 , 1 , -1};

void dfs(int x, int y, int depth, double prob) {
    if (depth == N) {
        result += prob;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, depth + 1, prob * dir[i]);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < 4; ++i) {
        int a;
        cin >> a;
        dir[i] = a / 100.0;
    }

    int center = SIZE / 2;
    visited[center][center] = true;
    dfs(center, center, 0, 1.0);

    cout.precision(10);
    cout << fixed << result << '\n';

    return 0;
}