#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m = {
    {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0},
    {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}};
    int n = survey.size();
    for(int i = 0; i<n; ++i){
        int choice = choices[i];
        int score = abs(choice - 4); // 1~3: 비동의, 5~7: 동의
        if(choices[i] > 4){ // 동의의 경우
            m[survey[i][1]] += score;
        }
        else if(choices[i] <4){ // 비동의의 경우
            m[survey[i][0]] += score;
        }
        else continue;
    }
    
    if(m['R']>=m['T']) answer +='R';
    else answer +='T';
    
    if(m['C']>=m['F']) answer +='C';
    else answer +='F';
    
    if(m['J']>=m['M']) answer +='J';
    else answer +='M';
    
    if(m['A']>=m['N']) answer +='A';
    else answer +='N';
    
    return answer;
}