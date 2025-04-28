#include <iostream>
#include <vector>

using namespace std;
int N , M;
vector<long long> waiting;

long long isPossible(long long time){
   long long result = 0;
   for(int i = 0; i<N; ++i){
       result += time/waiting[i];
       if(result >= M) return result;
   }
   return result;
}

int main(){

    cin >> N >> M;
    waiting.assign(N , 0);
    for(int i =0; i<N; ++i){
        cin >> waiting[i];
    }
    long long left = 0;
    long long right = 1e18;
    long long answer = right;
    while(left <= right){
        long long mid = (left+right)/2;
        if(isPossible(mid) >=M){
            answer = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }

    cout << answer << '\n';

    return 0;
}