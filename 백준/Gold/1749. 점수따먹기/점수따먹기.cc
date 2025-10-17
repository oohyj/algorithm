#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

long long kadane(const vector<long long>& v){
    long long best = v[0] , cur = v[0];

    for(int i =1; i<v.size(); ++i){
        cur = max(v[i] , cur+v[i]);
        best = max(best ,cur);
    }

    return best;
}

int main(){

   int N , M;
   cin >> N >> M;

   vector<vector<long long>> arr(N , vector<long long>(M ));


   for(int i = 0; i<N; ++i){
       for(int j =0; j<M; ++j){
           cin >> arr[i][j];
       }
   }

   long long answer = LLONG_MIN;

   for(int L = 0; L < M; ++L){
       vector<long long> temp(N , 0);
       for(int R = L; R < M; ++R){
           for(int i =0; i<N; ++i) temp[i] += arr[i][R];
           answer = max(answer , kadane(temp));
       }
   }

   cout << answer << '\n';


    return 0;
}
