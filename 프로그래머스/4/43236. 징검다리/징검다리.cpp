#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin() , rocks.end());
    rocks.push_back(distance);
    
    int left = 0;
    int right = distance;
    int mid;
    while(left <= right){
        mid = (left+right) / 2;
        int prev = 0 , removed = 0;
        for(int i =0; i<rocks.size(); ++i){
            if(rocks[i] - prev < mid){ // 최소 거리보다 작다면 제거해야 함
                removed++;
            }
            else{
                prev = rocks[i];
            }
        }
        
        if(removed > n){ // 제거 해야하는 돌이 n보다 크다면 거리를 줄여야 함
            right = mid -1;
        }
        else{
            answer = mid;
            left = mid+1;
        }

    }
    return answer;
}