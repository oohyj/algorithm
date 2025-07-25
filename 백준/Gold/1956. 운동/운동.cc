#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main(){

    int V , E;
    cin >> V >> E;

    vector<vector<int>> graph(V+1 , vector<int>(V+1 , INF));

    for(int i =0; i<E; ++i){
        int a , b , c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for(int k =1; k<=V; ++k){
        for(int i =1; i<=V; ++i){
            for(int j = 1; j<=V; ++j){
                if(graph[i][k] != INF && graph[k][j] != INF){
                    graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    int answer = INF;

    for(int i =1; i<=V; ++i){
        for(int j =1; j<V;++j){
            if(i !=j && graph[i][j] != INF && graph[j][i] != INF){
                answer = min(answer , graph[i][j] + graph[j][i]);
            }
        }
    }



    cout << (answer == INF? -1 : answer) << '\n';



    return 0;
}