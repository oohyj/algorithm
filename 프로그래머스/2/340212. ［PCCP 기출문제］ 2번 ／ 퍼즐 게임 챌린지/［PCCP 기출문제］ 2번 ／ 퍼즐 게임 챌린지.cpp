#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long timeTaken(vector<int>& diffs , vector<int>& times , int level){
    int size = diffs.size();
    long long taken = 0;

    for(int i = 0; i < size; i++) {
        if(diffs[i] <= level) {
            taken += times[i]; 
        } else {
            int cnt = diffs[i] - level;  // 틀린 횟수
            int prevTime = (i == 0) ? 0 : times[i - 1];
            long long failCost = (long long)(times[i] + prevTime) * cnt;
            taken += failCost + times[i];

            // 제한 시간을 초과하면 더 볼 필요 없음
            if(taken > 1e15) return taken;
        }
    }

    return taken;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int left = 1; 
    int right = *max_element(diffs.begin(), diffs.end());

    while(left <= right) {
        int mid = (left + right) / 2;
        long long taken = timeTaken(diffs, times, mid);

        if(taken <= limit) {
            answer = mid;    
            right = mid - 1;
        } else {
            left = mid + 1;    
        }
    }

    return answer;
}