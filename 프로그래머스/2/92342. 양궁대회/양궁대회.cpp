#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> info;
vector<int> curr(11) , best(11); //현재 시도중인 분배 , 최적의 분배
int bestDiff = INT_MIN;

int delta(int i , int b){
    int a = info[i];
    int v = 10-i;
    if(a == 0 && b == 0) return 0;
    if(a > 0 && b == 0) return -v;
    if(a == 0 && b > 0) return +v;
    if(b > a) return +v;
    return -v;
}

bool betterTie(const vector<int>& cand , const vector<int>& base){
    for(int i =10; i>=0; --i){
        if(cand[i] == base[i]) continue;
        return cand[i] > base[i];
    }
    return false;
}

void dfs(int i , int remain ,int diff){ // 현재 점수 인덱스 , 남아있는 횟수 , 점수 차이
    if(i == 10){
        curr[10] += remain;
        int finalDiff = diff + delta(10 , curr[10]);
        
        // 라이언이 이긴 경우만 후보로 고려
        if(finalDiff > 0){
            if(finalDiff > bestDiff || finalDiff == bestDiff &&betterTie(curr , best))              {
                bestDiff = finalDiff;
                best = curr;
            }
        }
        curr[10] -= remain;
        return;
    }
    
    
    int need = info[i]+1;
    if(remain>= need){
        curr[i] = need;
        dfs(i+1 , remain - need , diff+delta(i , need));
        curr[i] = 0;
    }
    
    curr[i] = 0;
    dfs(i+1 , remain  , diff + delta(i , 0));
}

vector<int> solution(int _n, vector<int> _info) {
    vector<int> answer;
    n = _n;
    info = _info;
    fill(curr.begin() , curr.end(), 0);
    fill(best.begin() , best.end() , 0);
  
    
    dfs(0 , n , 0);
    
     if(bestDiff == INT_MIN) return {-1};
    return best;
    
    
    return answer;
}