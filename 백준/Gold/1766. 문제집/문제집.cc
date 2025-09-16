#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){


    int N  , M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    vector<int> indeg(N+1 , 0);

    for(int i =0; i<M; ++i){
        int A , B;
        cin >> A >> B;
        adj[A].push_back(B);
        indeg[B]++;
    }

    priority_queue<int , vector<int> , greater<int>> pq;  // 쉬운 것부터 , 숫자가 작은 것부터

    for(int i =1; i<=N; ++i){
        if(indeg[i] == 0) pq.push(i);
    }

    vector<int> order;
    order.reserve(N);

    while(!pq.empty()){
        int u = pq.top();
        pq.pop();

        order.push_back(u);
        for(int v : adj[u]){
            if(--indeg[v] == 0) pq.push(v);
        }
    }

    for(int i =0; i<N; ++i){
        if(i) cout << ' ';
        cout << order[i];
    }

    cout << '\n';

    return 0;
}
