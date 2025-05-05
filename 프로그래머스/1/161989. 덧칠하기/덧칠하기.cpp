#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int current_loc;
    queue<int> q;
    for(int i =0; i<section.size(); ++i){
        q.push(section[i]);
    }
    
    while(!q.empty()){
        current_loc = q.front();
        while(!q.empty()&&current_loc + m -1 >= q.front()) {q.pop();}
        ++answer;
    }
    
    return answer;
}