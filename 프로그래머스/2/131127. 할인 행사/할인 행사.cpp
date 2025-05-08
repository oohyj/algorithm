#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool isCorrect(unordered_map<string , int>& buy , unordered_map<string , int>& sell){
    for(auto& iter : buy){
        if(!sell.count(iter.first) || sell[iter.first] != iter.second){
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string , int> buy;
    for(int i = 0; i<want.size(); ++i){
        buy[want[i]] = number[i];
    }
    
    for (int i = 0; i <= discount.size() - 10; ++i) {
    unordered_map<string, int> sell;

    for (int j = i; j < i + 10; ++j) {
        sell[discount[j]]++;
    }

    if (isCorrect(buy, sell)) {
        ++answer;
    }
}

    
    return answer;
}