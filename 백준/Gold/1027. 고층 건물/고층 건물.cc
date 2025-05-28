#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> height;

bool canSee(int i, int j) {
    double x1 = i, y1 = height[i];
    double x2 = j, y2 = height[j];

    for (int k = min(i, j) + 1; k < max(i, j); ++k) {
        double x = k;
        double y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
        if (height[k] >= y) return false; 
    }
    return true;
}

int main() {
    cin >> N;
    height.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> height[i];
    }

    int maxVisible = 0;

    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (canSee(i, j)) cnt++;
        }
        maxVisible = max(maxVisible, cnt);
    }

    cout << maxVisible << '\n';
    return 0;
}