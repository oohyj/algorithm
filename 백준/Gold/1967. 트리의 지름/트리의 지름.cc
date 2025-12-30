#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int farNode = 0 , maxDist = 0;
vector<vector<pair<int, int>>> adj;
vector<int> visited;

void dfs(int cur , int dist)
{
   if (dist > maxDist)
   {
       maxDist = dist;
       farNode = cur;
   }

    for (auto [v , w] : adj[cur])
    {
        if (!visited[v])
        {
            visited[v] = true;
            dfs(v , dist+w);
        }
    }
}

int main()
{

    int N;
    cin >> N;

    adj.resize(N+1);
    visited.resize(N+1 , false);

    for (int i = 0; i<N-1; ++i)
    {
        int left , right , w;
        cin >> left >> right >> w;
        adj[left].push_back({right , w});
        adj[right].push_back({left , w});
    }
    visited[1] = true;
    dfs(1 , 0);

    maxDist = 0;
    fill(visited.begin() , visited.end() , false);
    visited[farNode] = true;
    
    dfs(farNode ,0);

    cout << maxDist << '\n';


    return 0;
}
