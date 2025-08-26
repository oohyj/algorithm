#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

void buildAllSums(const vector<vector<int>>& dice , vector<int>& selectedDice , int diceIdx ,
                 int currentSum , vector<int>& cases){
    if(diceIdx == selectedDice.size()){
        cases.push_back(currentSum);
        return;
    }
    int d = selectedDice[diceIdx];
    for(int face : dice[d]){
        buildAllSums(dice , selectedDice , diceIdx+1 , currentSum+face , cases);
    }
}

int countWinCase(int target , vector<int>& vec){
    int left = 0 , right = vec.size()-1;
    while(left <= right){
        int mid = (left+right) /2;
        if(vec[mid] < target){
            left =mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return left;
    
}

void backtrackChooseA(const vector<vector<int>>& dice , 
                     int start, // 현재 주사위 인덱스
                      vector<int>& aDice, // 현재 A가 고른 주사위
                      vector<int>& bestAnswer, //최대 승 수일 때 A의 조합
                      ll& maxWins //최대 승수
                     ){
                     
    int n = dice.size();
    int k = n/2;
    
    if(aDice.size() == k){ // 만약 A 주사위를 다 골랐으면 B를 고르기 시작해야함
        vector<int> bDice;
        vector<bool> isA(n , false);
        for(int idx : aDice) isA[idx] = true;
        for(int i =0; i<n; ++i){
            if(!isA[i]) bDice.push_back(i);
        }
        
        // A와 B의 모든 합 구하기
        vector<int> aCases , bCases;
        buildAllSums(dice , aDice , 0 , 0 , aCases);
        buildAllSums(dice , bDice , 0 , 0 , bCases);
        
        sort(aCases.begin() , aCases.end());
        sort(bCases.begin() , bCases.end());
        
        ll aWins = 0;
        for(int c : aCases){
            aWins += countWinCase(c , bCases);
        }
        
        if(aWins > maxWins){
            maxWins = aWins;
            bestAnswer = aDice;
        }
        return;
    }
     
    // 조합 생성 : start부터 다음 인덱스를 하나씩 선택
    for(int i = start; i<n; ++i){
        aDice.push_back(i);
        backtrackChooseA(dice , i+1 , aDice , bestAnswer,maxWins);
        aDice.pop_back();
    }
                     
                     }

vector<int> solution(vector<vector<int>> dice) {
   vector<int> answer;
   int n = dice.size();
   vector<int> aDice;
    ll maxWins = -1;
    
    backtrackChooseA(dice , 0 , aDice , answer , maxWins);
    
    for(int& a : answer) a++;
    sort(answer.begin() , answer.end());
    return answer;
    
}