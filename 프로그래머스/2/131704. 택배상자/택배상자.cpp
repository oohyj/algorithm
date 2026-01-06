#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> s;
    int cur = 1;
    for(int i = 0; i < order.size(); ++i){
       int target = order[i];
       if(target >= cur){
           while(cur < target){
               s.push(cur);
               cur+=1;
           }
           
           cur+=1;
           answer +=1;
       }
        else{
            if(!s.empty() && s.top() == target){
                s.pop();
                answer+=1;
            }
            else  break;
        }
    }

    return answer;
}