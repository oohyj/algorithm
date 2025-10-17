#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<long long> v(N);

    for(int i =0; i<N; ++i){
        cin >> v[i];
    }

    sort(v.begin() , v.end());

    int answer = 0;



    for(int i =0; i<N; ++i){ // 어차피 첫번째랑 두번째는 두 개의 수로 나타내는 게 불가함
      int left = 0;
      int right = N-1; // 인덱스
      while(left < right){
          if(left == i){
              left++;
              continue;
          }
          if(right == i){
              right--;
              continue;
          } 
          
          long long sum = v[left] + v[right];
    
          if( sum == v[i]) {
              answer++;
              break;
          }
         else if(sum < v[i]) left++;
         else right--;
      }
    }

    cout << answer << '\n';

    return 0;
}