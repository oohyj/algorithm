#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> order;

    for (int i = 0; i < s.size(); ++i) {
        if (order.count(s[i]) == 0) {
            answer.push_back(-1);
        } else {
           
            answer.push_back(i - order[s[i]]);
        }
      
        order[s[i]] = i;
    }

    return answer;
}