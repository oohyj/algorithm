#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;


int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    parent.resize(n);
    
   
    for (int i = 0; i < n; ++i)
        parent[i] = i;

   
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    for (const auto& cost : costs) {
        int a = cost[0];
        int b = cost[1];
        int c = cost[2];

        if (find(a) != find(b)) {
            unite(a, b);
            answer += c;
        }
    }

    return answer;
}