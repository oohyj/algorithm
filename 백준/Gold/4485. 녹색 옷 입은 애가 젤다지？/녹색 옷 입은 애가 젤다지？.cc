#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int N;
    const int INF = 1e9;
    int tc = 1;

    while(true){

        cin >> N;
        if(N == 0) break;
        vector<vector<int>> cave(N , vector<int>(N , 0));
        for(int i =0;i<N; ++i){
            for(int j =0; j<N; ++j){
                cin >> cave[i][j];
            }
        }

        vector<vector<int>> dist(N , vector<int>(N , INF));
        dist[0][0] = cave[0][0];

        typedef pair<int , pair<int , int>> node;

        priority_queue<node , vector<node> , greater<node>> pq;
         pq.push({dist[0][0] , {0 , 0}});

         int dx[] = { -1 , 1 , 0 , 0};
         int dy[] = { 0 , 0 , -1 , 1};

         while(!pq.empty()){
             auto[cost , pos] = pq.top();
             pq.pop();
             int y = pos.first  , x = pos.second;

             if(cost > dist[y][x]) continue;

             for(int i =0;i<4; ++i){
                 int nx = x + dx[i];
                 int ny = y + dy[i];

                 if(nx <0 || nx >= N || ny < 0 || ny >=N) continue;
                 int ncost = cost + cave[ny][nx];
                 if(ncost < dist[ny][nx]){
                     dist[ny][nx] = ncost;
                     pq.push({ncost , {ny , nx}});
                 }
             }
         }
        cout << "Problem " << tc++ << ": " << dist[N-1][N-1] << '\n';

    }
    return 0;
}