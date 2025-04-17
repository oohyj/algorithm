#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N , M;
vector<vector<int>> li;

int calDistance(int start , int end){
    vector<bool> visited(N , false);

    queue<pair<int, int>> q;

    q.push({start , 0});
    visited[start] = true;

    while(!q.empty()){
        auto[current_node , dist] = q.front();
        q.pop();

        if(current_node == end ) return dist;
        for(int i =0; i<N; ++i){
            if(li[current_node][i] > 0 && !visited[i]){
                visited[i] = true;
                q.push({i , dist+li[current_node][i]});
            }
        }
    }

    return -1;
}

int main(){

    cin >> N >>M;
    li.assign(N , vector<int>(N, -1));

    for(int i =0; i<N-1; ++i){
        int a , b , c;
        cin >> a >>b >> c;
        a--;
        b--;
        li[a][b] = c;
        li[b][a] = c;
    }

    while(M--){
        int start , end;
        cin >> start >> end;
        start--;
        end--;
        cout << calDistance(start , end) << '\n';
    }

    return 0;
}