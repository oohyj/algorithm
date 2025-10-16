#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<pair<long long,long long>> postOffice(N);

    long long sum =0; // 총 사람 수

    for(int i =0; i<N; ++i){
        long long a , b;
        cin >> a >> b;
        postOffice[i].first = a;
        postOffice[i].second = b;
        sum += b;
    }


    sort(postOffice.begin() , postOffice.end() , [](const auto& a , const auto& b){
        return a.first < b.first;
    }); // 첫번째 인자를 기준으로 오름차순 정렬

    long long target = (sum+1)/2; // 전체 인구의 절반을 넘기면 해당 지점에서 만나는 게 가장 모두에게 이득임
    long long current = 0;

   for(const auto& iter : postOffice){
       if(current + iter.second >= target){
           cout << iter.first << '\n';
           return 0;
       }
       else {
           current += iter.second;
       }
   }

    return 0;
}