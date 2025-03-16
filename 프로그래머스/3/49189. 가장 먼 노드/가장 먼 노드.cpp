#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> line;
vector<bool> visited;

void bfs(int index , vector<int>& distance){
    queue<int> q;
    q.push(index);
    visited[index] = true;
    
    while(!q.empty()){
        int current_v = q.front();
        q.pop();
        
        for(int next : line[current_v]){
            if(!visited[next]){
                visited[next] = true;
                distance[next] = distance[current_v]+1;
                q.push(next);
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    line.assign(n+1 , vector<int>()); // 노드가 20000개 이하이므로 인접리스트로 구현
    visited.assign(n+1 , false);
    
    for(auto& e : edge){
        int u = e[0];
        int v = e[1];
        line[u].push_back(v);
        line[v].push_back(u);
    }
    
    vector<int> distance(n+1 , 0);
    bfs(1 , distance);
    
    int max_value = *max_element(distance.begin() , distance.end());
    
    for(int i =0; i<distance.size(); i++){
        if(distance[i] == max_value){
            answer++;
        }
    }
    
    return answer;
}