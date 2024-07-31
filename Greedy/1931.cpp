#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int , int> ci;

bool compBySecond(const ci& a , const ci& b){
    if(a.second == b.second){
        return a.first<b.first;
    }
    return a.second < b.second;
}

int main(){

    int n , a , b;

    vector<ci> meetings;

    cin >> n;

    for(int i =0; i<n; i++){
        cin >> a >> b;
        meetings.push_back(make_pair(a , b));
    }

    // 이전 회의보다는 늦으면서 끝나는 시간이 가장 빠른 걸 골라야함
    int end_time = 0;
    int count =0; //회의 개수
    sort(meetings.begin() , meetings.end() , compBySecond); //meetings의 첫번째 요소를 기준으로 정렬

//    for(int i =0; i<n; i++){
//        cout << meetings[i].first <<" " <<meetings[i].second<<'\n';
//    }

    for(int i =0; i<n; i++){
            if(end_time <= meetings[i].first){
                count++;
                end_time = meetings[i].second;
                //cout << "end_time : " << end_time <<'\n';
            }
    }

    cout << count << '\n';


    return 0;
}
