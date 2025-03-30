#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string , int> m;
    for(int i =0; i<participant.size(); i++){
        m[participant[i]]++;
    }
    
    for(int i =0; i<completion.size(); i++){
        m[completion[i]]--;
    }
    
    for(auto iter : m){
        if(iter.second >0){
            answer = iter.first;
            break;
        }
    }
    return answer;
}