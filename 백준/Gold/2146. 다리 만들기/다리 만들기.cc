#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
int N;
vector<vector<int>> country;
vector<vector<bool>> isVisited; // 각 섬을 방문했는지
vector<vector<int>> indexingIsland; // 각 섬들을 인덱싱

int dy[] = { -1 , 1 , 0 , 0};
int dx[] = { 0  , 0 , -1 , 1};

void bfsForCountIsland(int y , int x , int standard){ // standard는 지금 탐색 중인 섬을 채울 숫자
    queue<pair<int , int>> q;
    q.push({y , x});
    isVisited[y][x] = true;
    indexingIsland[y][x] = standard;

    while(!q.empty()){
        auto [cur_y, cur_x] = q.front();
        q.pop();

        for(int dir = 0; dir < 4; ++dir){
            int new_y = cur_y + dy[dir];
            int new_x = cur_x + dx[dir];
            if(new_y < 0 || new_y >= N || new_x < 0 || new_x >= N) continue;
            if(!isVisited[new_y][new_x] && country[new_y][new_x] == 1) {
                isVisited[new_y][new_x] = true;
                indexingIsland[new_y][new_x] = standard;
                q.push({new_y , new_x});
            }
        }
    }
}

int bfsForCountBridge(int id){ // num은 섬번호
    vector<vector<int>> dist (N , vector<int>(N , -1));
    queue<pair<int , int>> q;

    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            if(indexingIsland[i][j] == id){
                q.push({i , j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        auto[y , x] = q.front(); q.pop();

        for(int d = 0; d < 4; ++d){
            int ny = y + dy[d] , nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if(indexingIsland[ny][nx] == 0 && dist[ny][nx] == -1){
                dist[ny][nx] = dist[y][x] +1;
                q.push({ny , nx});
            }

            if(indexingIsland[ny][nx] > 0 && indexingIsland[ny][nx] != id){
                return dist[y][x];
            }
        }
    }
    return INT_MAX;
}


int main(){

    cin >> N;
    country.assign(N , vector<int>(N , 0));
    for(int i =0; i<N; ++i){
        for(int j =0; j <N; ++j){
            cin >> country[i][j];
        }
    }

    // 너비로 탐색한 다음 -> 각 섬들에게 숫자 부여
    // 그리고 나서 다른 섬까지의 위치
    indexingIsland.assign(N , vector<int>(N , 0));
    isVisited.assign(N , vector<bool>(N , false));
    int standard = 2; // 0 , 1 은 각각 바다 , 육지를 나타내니까

    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            if(!isVisited[i][j] && country[i][j] == 1){ // 아직 해당 섬을 방문하지 않았고 1이라면
                bfsForCountIsland(i , j , standard++);
            }
        }
    }

    int ans = INT_MAX;

    for(int id = 2; id < standard; ++id){
        ans = min(ans , bfsForCountBridge(id));
    }

    cout << ans << '\n';


    return 0;
}