#include <string>
#include <vector>
#include <queue>

using namespace std;

int calDistance(int start, int end , vector<vector<int>>& way , int n){
    vector<bool> visited(n , false);
    queue<pair<int , int>> q;
    visited[start] = true;
    q.push({start , 0});
    
    while(!q.empty()){
        auto[current , dist] = q.front();
        q.pop();
        if(current == end) return dist;

        for (int neighbor : way[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor , dist + 1});
            }
        }
    }
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> way(n);
    for(auto& road : roads){
        int a = road[0] -1 , b = road[1] -1;
        way[a].push_back(b);
        way[b].push_back(a);
    }
    
    for(int i =0; i<sources.size(); ++i){
        if(destination-1 == sources[i]-1) answer.push_back(0);
        else answer.push_back(calDistance(sources[i]-1 , destination-1 , way , n));
    }
    
    return answer;
}