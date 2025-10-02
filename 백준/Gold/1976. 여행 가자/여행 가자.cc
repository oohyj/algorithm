#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main(){

    int N , M;
    cin >> N >> M;

    vector<vector<int>> city(N);
    vector<int> trip(M , 0); // 동혁이 여행 경로

    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
           int a;
           cin >> a;
           if(a == 1){
               city[i].push_back(j);
           }
        }
    }

    for(int i =0; i<M; ++i){
        cin >> trip[i];
        --trip[i];
    }

    vector<int> visited(N , 0);

    queue<int> q ;
    q.push(trip[0]);
    visited[trip[0]] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt : city[cur]){
            if(!visited[nxt]) {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }

    }

    for(int x : trip){
        if(!visited[x]) {
            cout << "NO" << '\n';
            return 0;
        }
    }


    cout << "YES" << '\n';

    return 0;
}
