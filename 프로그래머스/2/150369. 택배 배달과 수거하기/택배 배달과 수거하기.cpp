#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int dIdx = n - 1;
    int pIdx = n - 1;

    while (dIdx >= 0 || pIdx >= 0) {
        // 배달, 수거의 마지막 위치 찾기
        while (dIdx >= 0 && deliveries[dIdx] == 0) dIdx--;
        while (pIdx >= 0 && pickups[pIdx] == 0) pIdx--;
        
        if (dIdx < 0 && pIdx < 0) break;

        int move = max(dIdx, pIdx) + 1;
        answer += move * 2;

        int dCap = cap;
        for (int i = dIdx; i >= 0 && dCap > 0; --i) {
            if (deliveries[i] == 0) continue;
            int delivered = min(deliveries[i], dCap);
            deliveries[i] -= delivered;
            dCap -= delivered;
        }

        int pCap = cap;
        for (int i = pIdx; i >= 0 && pCap > 0; --i) {
            if (pickups[i] == 0) continue;
            int picked = min(pickups[i], pCap);
            pickups[i] -= picked;
            pCap -= picked;
        }
    }

    return answer;
}