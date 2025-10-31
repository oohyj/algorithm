#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
int answer = 0;

void dfs(int node , int sheep , int wolf ,set<int> nextnodes , vector<int>& info){
    if(info[node] == 0) sheep++;
    else wolf++;
    
    if(wolf >= sheep) return;
    
    answer = max(answer , sheep);
    
    for(int child : graph[node]){
        nextnodes.insert(child);
    }
    
    nextnodes.erase(node);
    
    for(const auto& iter : nextnodes){
        dfs(iter, sheep , wolf , nextnodes , info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    graph.assign(n , {});
    
    for(const auto& e : edges){
        graph[e[0]].push_back(e[1]);
    }
    
    set<int> nextnodes;
    
    dfs(0 , 0 , 0 , nextnodes , info);
    return answer;
}