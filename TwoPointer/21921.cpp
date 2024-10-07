#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n , x  , answer =0; //x는 구간
    vector<int> guest;
    vector<int> cnt;
    cin >> n >> x;

    guest.assign(n , 0);
    for(int i =0; i<n; i++){
        cin >> guest[i];
    }
     int sum =0;
    for(int i =0; i<x; i++){
        sum += guest[i];
    }
    cnt.push_back(sum);

    for(int i = x; i<n; i++){
        sum = sum - guest[i-x] + guest[i];
        cnt.push_back(sum);
    }

    int max_cnt = *max_element(cnt.begin() , cnt.end());

    if(max_cnt == 0){
        cout <<"SAD";
    }
    else {

        for (int i = 0; i < cnt.size(); i++) {
            if (max_cnt == cnt[i]) {
                answer++;
            }
        }

        cout << max_cnt << '\n' << answer;
    }

    return 0;
}
