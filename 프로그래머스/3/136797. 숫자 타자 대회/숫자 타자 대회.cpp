#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
// 1756 -> 10
// 5123 -> 8

const int INF = 1e9;
int solution(string numbers) {
    int answer = 0;
  
    pair<int,int> pos[10] = {
    {3,1}, // 0
    {0,0}, {0,1}, {0,2},
    {1,0}, {1,1}, {1,2},
    {2,0}, {2,1}, {2,2}
     };
    
     int cost[10][10];
    
    for(int i = 0; i<10; ++i){
        for(int j = 0; j<10; ++j){
            if(i==j){
                cost[i][j] = 1;
                continue;
            }
            int dr = abs(pos[i].first - pos[j].first);
            int dc = abs(pos[i].second - pos[j].second);
            cost[i][j] = 3* min(dr , dc) + 2*abs(dr-dc);
        }
    }
    
    
    int dp[10][10]  , next_dp[10][10]; // 왼손이 L , 오른손이 R에 있을 때 비용
    for(int i =0; i<10; ++i){
        for(int j = 0; j<10; ++j){
            dp[i][j] = INF;
        }
    }
    
    dp[4][6] = 0;
    
    for(char c : numbers){
        int x = c -'0';
        
        for(int i = 0; i <10; ++i){
            for(int j =0; j<10; ++j){
                next_dp[i][j] = INF;
            }
        }
        
        for(int l = 0; l <= 9; ++l){
            for(int r = 0; r <=9; ++r){
                if(dp[l][r] == INF) continue;
                
                if( r != x){
                    next_dp[x][r] = min(next_dp[x][r] , dp[l][r] + cost[l][x]);
                }
                
                if( l != x){
                    next_dp[l][x] = min(next_dp[l][x] , dp[l][r] + cost[r][x]);
                }
            }
        }
        
        memcpy(dp , next_dp , sizeof(dp));
    }
    
    answer = INF;
    
    for(int l = 0;  l <= 9; ++l){
        for(int r = 0; r <=9 ; ++r){
            answer = min(answer , dp[l][r]);
        }
    }
    
    
    return answer;
}