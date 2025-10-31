#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    vector<vector<long long>> diff(n+1 , vector<long long>(m+1 , 0));
    
    for(const auto& s : skill){
        int type = s[0];
        int r1 = s[1] , c1 = s[2] , r2 = s[3] , c2 = s[4];
        long long v = (type == 1? -1LL : 1LL)*s[5];
        diff[r1][c1] += v;
        diff[r2+1][c1] -= v;
        diff[r1][c2+1] -= v;
        diff[r2+1][c2+1] += v;
    }
    
    for(int i =0; i<n; ++i){
        for(int j =1; j <m; ++j){
            diff[i][j] += diff[i][j-1];
        }
    }
    
    for(int j =0; j<m; ++j){
        for(int i =1; i<n;++i){
            diff[i][j] += diff[i-1][j];
         }
    }
    
    for(int i =0; i<n; ++i){
        for(int j =0; j<m; ++j){
            if(board[i][j] + diff[i][j] > 0) answer++;
        }
    }
  
    return answer;
}