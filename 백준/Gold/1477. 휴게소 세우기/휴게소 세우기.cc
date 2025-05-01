#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N , M , L;
vector<int> loc;
vector<int> diff; // 휴게소 거리 차이

int calRest(int mid){
    int cnt = 0;
    for(int i =0; i<diff.size(); ++i){
        if(diff[i] == 0) continue;
        cnt += (diff[i] -1) / mid;
    }

    return cnt;
}

int main(){

    cin >> N >> M >> L;

    loc.assign(N , 0);

    for(int i =0; i<N; ++i){
        cin >> loc[i];
    }

    sort(loc.begin() , loc.end());

    if (N == 0) {
        diff.push_back(L);
    } else {
        diff.push_back(loc[0]);
        for (int i = 1; i < N; ++i) {
            diff.push_back(loc[i] - loc[i - 1]);
        }
        diff.push_back(L - loc[N - 1]);
    }

    int left = 1;
    int right = L;
    int mid;

    while(left <= right){
        mid = (left+right)/2;

        // 해당 길이로 하려면 필요한 휴게소 수 확인
        if(calRest(mid) > M){ // M 보다 크다면 길이 늘림
            left = mid+1;
        }
        else {
            right = mid -1;
        }
    }

    cout << left << '\n';
    return 0;
}