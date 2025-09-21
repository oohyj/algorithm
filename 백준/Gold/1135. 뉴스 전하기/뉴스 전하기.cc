#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<vector<int>> child;

int dfs(int u){
    vector<int> times;
    for(int v : child[u]){
        times.push_back(dfs(v));
    }
    if(times.empty()) return 0;

    sort(times.begin() , times.end() , greater<int>());

    int best = 0;

    for(int i =0; i< (int)times.size(); ++i){
        best = max(best , times[i]+ i+1);
    }
    return best;
}

int main(){

    cin >> N;

    child.assign(N , {});

    for(int i =0; i < N; ++i){
        int p;
        cin >> p;
        if(p != -1) child[p].push_back(i);
    }

    cout << dfs(0) << '\n';
    return 0;
}