#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool isExist(string b , vector<string>& list){
    for(string s : list){
        if(s == b) return true;
    }
    return false;
}

vector<int> solution(vector<string> id_list, vector<string> _report, int k) {
    vector<int> answer;
    map<string , int> report_cnt; // 각 id들이 얼마나 신고를 당했는지
    map<string , vector<string>> report; // 신고 기록
    for(int i =0; i<id_list.size(); ++i){
        report[id_list[i]];
    }
    
    for(int i =0; i<_report.size(); ++i){
        string a ,  b;
        stringstream ss(_report[i]);
        ss  >> a >> b;
        if(isExist(b , report[a])) continue;
        else{
            report[a].push_back(b);
        report_cnt[b]++;
        }
    }
    vector<string> target;
    
    for(const auto& iter : report_cnt){
        if(iter.second >= k){
            target.push_back(iter.first);
        }
    }
    
    
    for(int i =0; i<id_list.size(); ++i){
        string user = id_list[i];
        vector<string> v = report[user];
        int cnt = 0;
        for(int j =0; j < v.size(); ++j){
            for(int t = 0; t < target.size(); ++t){
                if(v[j] == target[t]) cnt++;
            }
        }
        
        answer.push_back(cnt);
    }
    
    
    return answer;
}