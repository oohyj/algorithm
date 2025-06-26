#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char , int> m; // 알파벳 - 자판 횟수 최소값
    for(string key : keymap){
        for(int i =0; i<key.size(); ++i){
            if(m.count(key[i]) > 0){ // 해당하는 키 값이 있다면
                int now_v = m[key[i]];
                m[key[i]] = min(i+1 , now_v);
            }
            else m[key[i]] = i+1;
        }
    }
    

    
     for(string target : targets){
        int cnt = 0;
        bool impossible = false;

        for(char ch : target){
            if(m.count(ch) == 0){
                impossible = true;
                break;
            }
            cnt += m[ch];
        }

        if(impossible) cnt = -1;
        answer.push_back(cnt);
    }
    return answer;
}