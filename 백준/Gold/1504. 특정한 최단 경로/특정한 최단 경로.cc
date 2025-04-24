#include <iostream>
#include <vector>
#include <queue>

const int INF = 2e8;

using namespace std;

int N , E , v1 , v2;
vector<vector<pair<int , int>>> graph;

vector<int> dijkstra(int start){
    vector<int> dist(N+1 , INF);
    priority_queue<pair<int, int> , vector<pair<int,int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0 , start});
    while(!pq.empty()){
        auto[cost, now] = pq.top();
        pq.pop();

        if(cost > dist[now]) continue;

        for(auto &[next , weight] : graph[now]){
            if(dist[next] > cost + weight){
                dist[next] = cost+weight;
                pq.push({dist[next] , next});
            }
        }
    }
    return dist;
}

int main(){

    cin >> N >> E;
    graph.assign(N+1 , {});

    for(int i =0; i<E; ++i){
        int a ,b , c;
        cin >> a >> b >> c;
        graph[a].emplace_back( b, c);
        graph[b].emplace_back(a , c);
    }

    cin >> v1 >> v2;

    vector<int> dist1 = dijkstra(1);
    vector<int> distV1 = dijkstra(v1);
    vector<int> distV2 = dijkstra(v2);

    int path1 = dist1[v1] + distV1[v2] + distV2[N];
    int path2 = dist1[v2] + distV2[v1] + distV1[N];

    int answer = min(path1 , path2);
    if(answer >= INF) cout << -1 << '\n';
    else cout << answer << '\n';


    return 0;
}