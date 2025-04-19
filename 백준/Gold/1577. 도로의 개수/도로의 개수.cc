#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
bool construction[2*MAX][2*MAX] = { false};
unsigned long long dp[MAX][MAX] = {0};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N , M , K;
    cin >> N >> M >> K;

    // 공사중인 도록 위치 기록
    for(int i =0; i<K; ++i){
        int a , b , c , d;
        cin >> a >> b >> c >>d;

        // 도로는 점과 점 사이에 있음 -> 격자 확장하여 저장
        construction[b+d][a+c] = true;
    }

    // 시작점 초기화
    dp[0][0] = 1;

    //세로축 초기화 (오른쪽 방향)
    for(int j =1; j<=N; ++j){
        if(construction[0][2*j-1]) break;
        dp[0][j] = 1;
    }

    // 가로축 초기화
    for(int i =1; i<=M; ++i){
        if(construction[2*i-1][0]) break;
        dp[i][0] = 1;
    }

    for(int i =1; i<=M; ++i){
        for(int j =1; j <=N; ++j) {
            if (!construction[2 * i - 1][2 * j]) dp[i][j] += dp[i-1][j];
            if(!construction[2*i][2*j-1]) dp[i][j] += dp[i][j-1];
        }
    }

    cout << dp[M][N] <<'\n';

    return 0;
}