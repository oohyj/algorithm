#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    int n = topping.size();
    unordered_set <int> left; // 철수
    unordered_map <int , int> right; // 동생
    
    left.insert(topping[0]);
    for(int i =1; i<n; ++i){
        right[topping[i]]++;
    }
    for(int i =1; i<n; ++i){
        left.insert(topping[i]);
        right[topping[i]]--;
        if(right[topping[i]] == 0){
            right.erase(topping[i]);
        }
        if(left.size() == right.size()){
            ++answer;
        }
    }
    
    return answer;
}