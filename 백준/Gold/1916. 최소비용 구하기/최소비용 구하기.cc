#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N , M;
const int INF = 1e9;
vector<pair<int , int>> graph[1001];
vector<int> dist;

void dijkstra(int start){
    priority_queue<pair<int, int> , vector<pair<int , int>>,greater<>> pq;
    dist[start] = 0;
    pq.push({0 , start});

    while(!pq.empty()){
        int currentDist = pq.top().first; // 거리
        int currentNode = pq.top().second; // 노드
        pq.pop();

        if(currentDist > dist[currentNode]) continue;

        for(auto [nextNode , weight] : graph[currentNode]){
            int newDist = currentDist + weight;
            if(newDist < dist[nextNode]){
                dist[nextNode] = newDist;
                pq.push({newDist , nextNode});
            }
        }
    }
}

int main(){
    cin >> N >> M;
    dist.assign(N + 1, INF);

    for(int i = 0; i < M; ++i){
        int u , v , w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v , w);
    }

    int start , target;
    cin >> start >> target;

    dijkstra(start);


    cout << dist[target] << '\n';

    return 0;
}