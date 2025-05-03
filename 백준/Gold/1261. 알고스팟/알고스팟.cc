#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int dx[] = { -1  , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};

int main(){

    int M , N;
    cin >> M >> N;

    vector<string> maze(N);

    for(int i =0; i<N; ++i){
        cin>> maze[i];
    }

    vector<vector<int>> dist(N , vector<int>(M , 1e9)); // 벽 부순 횟수 저장
    deque<pair<int , int>> dq;

    dist[0][0] = 0;
    dq.push_front({0 , 0});

    while(!dq.empty()){
        auto[x , y] = dq.front();
        dq.pop_front();

        for(int i =0; i<4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <0 || ny < 0 || nx >=N || ny >=M) continue;

            int cost = (maze[nx][ny] == '1')? 1 : 0;
            if(dist[nx][ny] > dist[x][y] + cost){
                dist[nx][ny] = dist[x][y] + cost;

                if(cost == 1) dq.push_back({nx , ny});
                else dq.push_front({nx , ny});
            }
        }
    }

    cout << dist[N-1][M-1] << '\n';

    return 0;
}