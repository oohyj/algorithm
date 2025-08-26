#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main(){

    int K , W , H;
    cin >> K >> W >> H;
    vector<vector<int>> trip(H , vector<int>(W , 0));
    for(int i =0; i<H;++i){
        for(int j =0; j<W; ++j){
            cin >> trip[i][j];
        }
    }

    queue<tuple<int , int , int>> q; // y , x , 사용한 말 점프 횟수
    vector<vector<vector<int>>> dist(H , vector<vector<int>>(W , vector<int>(K+1 , -1)));

    int dy[] = { -1 , 1 , 0 , 0};
    int dx[] = { 0 , 0 , -1 , 1};

    q.push({0 , 0 , 0});
    dist[0][0][0] = 0;

    // 체스 나이트 이동
    int ky[] = {-2 , -2 , -1 , -1 , 1 , 1, 2 , 2};
    int kx[] = {1 , -1 , -2 , 2 , -2 , 2 , -1 , 1};



    while(!q.empty()){
        auto[y , x , used] = q.front();
        q.pop();
        int d = dist[y][x][used];

        if(y == H-1 && x == W-1){
            cout << d << '\n';
            return 0; // 도착하면 종료
        }

        for(int dir = 0; dir <4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= H || nx <0 || nx >= W) continue;
            if(trip[ny][nx] == 1) continue; // 장애물 있으면 pass
            if(dist[ny][nx][used] != -1) continue; // 이미 방문
            dist[ny][nx][used] = d+1;
            q.push({ny , nx , used});
        }


        if(used < K) {
            // 말 점프
            for (int dir = 0; dir < 8; ++dir) {
                int ny = y + ky[dir];
                int nx = x + kx[dir];

                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (trip[ny][nx] == 1) continue; // 착륙?지점에 장애물 있으면 pass
                if (dist[ny][nx][used+1] != -1) continue;
                dist[ny][nx][used+1] = d+1;
                q.push({ny , nx , used+1});
            }
        }

    }

    cout << "-1" << '\n';

    return 0;
}