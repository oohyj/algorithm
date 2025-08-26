#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> buildTime(N); // 해당 번호의 건물을 짓는 데 걸리는 시간
    vector<vector<int>> adj(N); // 해당 번호의 건물을 짓기 전에 지어야 하는 건물 정보
    vector<int> indeg(N , 0); // 이전에 지어야 하는 건물 개수

    for(int i =0; i<N; ++i){
        int t;
        cin >> t;
        buildTime[i] = t;
        int x;
        while(true){
            cin >> x;
            if(x == -1) break;
            adj[--x].push_back(i);
            indeg[i]++;
        }
    }

    queue<int> q;
    vector<int> result(N , 0);

    for(int i =0; i<N; ++i){
       if(indeg[i] == 0){
           result[i] = buildTime[i];
           q.push(i);
       }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int idx : adj[cur]){
           result[idx] = max(result[idx] , result[cur]+buildTime[idx]);

           if(--indeg[idx] == 0){
               q.push(idx);
           }
        }
    }

    for(int idx : result){
        cout << idx << '\n';
    }


    return 0;
}
