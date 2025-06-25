#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int n = p.size();
    long long p_num = stoll(p);  

    for (int i = 0; i <= t.size() - n; ++i) {
        string s = t.substr(i, n);
        long long s_num = stoll(s);
        if (s_num <= p_num) answer++;
    }

    return answer;
}