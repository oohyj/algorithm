#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n , m;
vector<vector<int> > adj; // 인접리스트
vector<bool> visited_dfs;
vector<int> count_node;

void dfs (int v , int& cnt){
    visited_dfs[v] = true;
    cnt++; // 해킹한 컴퓨터 수
    for(int u : adj[v]){
        if(!visited_dfs[u]){
            dfs(u , cnt);
        }
    }
}

int main(){

    cin >> n >>m;

    adj.resize(n+1);
    count_node.resize(n+1 , 0);

    for(int i =0; i <m; i++){
        int a , b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for(int v =1; v < n+1 ; v++){
        visited_dfs.assign(n+1 , false);
        int cnt =0;
        dfs(v , cnt);
        count_node[v] = cnt;
    }

    int max_hack = *max_element(count_node.begin()+1 , count_node.end());

    for(int i = 1; i<=n; i++){
        if(count_node[i] == max_hack){
            cout << i <<" ";
        }
    }

    return 0;
}
