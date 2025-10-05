#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
using Node = tuple<int , int , int>; // 현재까지의 비용 , x , y
const int INF = 1e9;

int main(){

    int n;
    cin >> n;

    vector<string> board(n);

    for(int i =0; i<n; ++i){
        cin >> board[i];
    }

    vector<vector<int>> dist(n , vector<int>(n , INF));
    priority_queue<Node , vector<Node> , greater<Node>> pq;

    dist[0][0] = 0;
    pq.emplace(0 , 0 , 0);

    int dx[] = { -1 , 1 , 0 , 0};
    int dy[] = { 0 , 0 , -1 , 1};

    while(!pq.empty()){

        auto[d , x , y] = pq.top();
        pq.pop();

        if(d != dist[x][y]) continue;
        if(x == n-1 && y == n-1) break;

        for(int dir = 0; dir < 4; ++dir){
            int nx = x + dx[dir] , ny = y + dy[dir];
            if(nx <0 || nx >= n || ny < 0 || ny >= n) continue;

            int w = (board[nx][ny] == '1')? 0 : 1;

            if(dist[nx][ny] > d + w){
                dist[nx][ny] = d + w;
                pq.emplace(dist[nx][ny] , nx , ny);
            }
        }

    }

    cout << dist[n-1][n-1] << '\n';

    return 0;
}