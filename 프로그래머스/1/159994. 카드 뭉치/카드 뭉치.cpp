#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> q1 , q2 , target;
    for(string card : cards1){
        q1.push(card);
    }
    for(string card : cards2){
        q2.push(card);
    }
    int idx = 0;
    for(string g : goal){
    
        if(!q1.empty() && q1.front() == g){
            ++idx;
            q1.pop();
        }
        else if(!q2.empty() && q2.front() == g){
            ++idx;
            q2.pop();
        }
        else break;
    }
    
    if(idx == goal.size()){
        answer = "Yes";
    }else{
        answer = "No";
    }
    
    
    return answer;
}