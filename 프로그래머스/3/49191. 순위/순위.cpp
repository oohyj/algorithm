#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n+1 , vector<bool>(n+1));
    
    for(auto& result : results){
        int win = result[0];
        int lose = result[1];
        graph[win][lose] = true;
    }
    
    //플로이드 - 워셜
    for(int k = 1; k<=n; ++k){
        for(int i = 1; i <=n; i++){
            for(int j =1; j<=n; j++){
                if(graph[i][k] && graph[k][j]){
                    graph[i][j] = true;
                }
            }
        }
    }
    
    for(int i =1; i<=n; i++){
        int win_cnt =0;
        int lose_cnt = 0;
        for(int j =1; j<=n; j++){
            if(graph[i][j]) win_cnt++;
            if(graph[j][i]) lose_cnt++;
        }
        
        if((win_cnt + lose_cnt) == n-1){
            answer++;
        }
    }
    
    return answer;
}