#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int M , N;
vector<vector<int>> mountain;
vector<vector<ll>> dp;


int dy[] = {-1 , 1 , 0 , 0};
int dx[] = { 0 , 0 , -1 , 1};

ll dfs(int y , int x){
   if(y == M-1 && x == N-1){ // 최종 목적지 도착
       return 1;
   }
   ll &ret = dp[y][x];

   if(ret != -1) return ret;
   ret = 0;

   for(int i =0; i<4; ++i){
       int ny = y + dy[i];
       int nx = x + dx[i];

       if(ny >= 0 && ny < M && nx >=0 && nx < N){
           if(mountain[ny][nx]  <  mountain[y][x]){
              ret += dfs(ny , nx);
           }
       }
   }
    return ret;

}

int main(){

    cin >> M >> N;

    mountain.assign(M , vector<int>(N , 0));
    for(int i =0; i<M; ++i){
        for(int j =0; j<N; ++j){
            cin >> mountain[i][j];
        }
    }

    dp.assign(M , vector<ll>(N , -1));


    cout <<dfs(0 , 0)  << '\n';


    return 0;
}