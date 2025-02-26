#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q; 
    
    for(int t =0; t<24; t++){
        while(!q.empty() && q.front() <= t){ // 큐에 담긴 서버 종료 시각이 종료 시각을 넘었다면
            q.pop();
        }
        
        int required = players[t]/m;
        
        while(required > q.size()){
            int expansion = required - q.size(); // 추가로 필요한 서버 개수
            answer += expansion;
            
            for(int i =0; i<expansion; i++){
                q.push(t+k); // 서버 종료 시각 넣어서 추가
            }
        }
        
    }
    
    
    return answer;
}
