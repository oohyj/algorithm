#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double calArea(int start , int end , vector<double>& area){
    double result = 0;
    for(int i = start;  i < end; ++i){
        result += area[i];
    }
    return result;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int rn = ranges.size(); // range의 크기
    vector<int> collatz;
    collatz.push_back(k);
    int target = k;
    
    while(true){
        if(target == 1) break;
        if(target % 2  == 0){
            target /= 2;
        }
        else{
            target = target*3 +1;
        }
        collatz.push_back(target);
    }
    
    int n = collatz.size();
    
    // 각 구간 넓이 구하기
    vector<double> area(n-1 , 0);
    for(int i = 0; i < n-1; ++i){
        area[i] = (collatz[i] + collatz[i+1]) / 2.0; 
    }
    
    
    for(int i = 0; i< rn; ++i){
        int start = ranges[i][0];
        int end = (n-1) + ranges[i][1];
       
        if(start > end){ // end가 적으면 -1.0
            answer.push_back(-1.0);
            continue;
        }
              
        if(start == end){
            answer.push_back(0.0);
            continue;
        }
        
       
        double sum = calArea(start , end , area);
        answer.push_back(sum);
        
    }
    return answer;
}