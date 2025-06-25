#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int n = p.size();
    long long p_num = stoll(p);  
    string s = "";

    for(int i = 0; i < n; ++i){
        s += t[i];
    }
    if(stoll(s) <= p_num) answer++;

    for(int i = n; i < t.size(); ++i){
        s = s.substr(1);
        s += t[i];
        if(stoll(s) <= p_num) answer++;
    }

    return answer;
}