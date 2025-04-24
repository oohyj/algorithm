#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> word(N);

    map<char , int> weight; // 문자별 가중치
    for(int i =0; i<N; ++i){
        cin >> word[i];
        int len = word[i].size();
        for(int j =0; j<len; ++j){
            char c = word[i][j];
            weight[c] += pow(10 , len-j-1); // 자릿수대로
        }
    }

    vector<pair<char , int>> vec(weight.begin() , weight.end());
    sort(vec.begin() , vec.end() , [](auto &a , auto &b){
        return a.second > b.second;
    });

    map<char , int> charToDigit;
    int num = 9;
    for(auto &p : vec){
        charToDigit[p.first] = num--;
    }

    int total = 0;
    for(auto &w : word){
        int val = 0;
        for(char c : w ){
            val = val * 10 + charToDigit[c];
        }
        total += val;
    }

    cout << total << '\n';

    return 0;
}
