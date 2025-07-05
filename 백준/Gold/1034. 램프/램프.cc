#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

int main(){

    int N , M , K;
    cin >> N >> M;
    vector<string> lamp(N);
    vector<int> zeroCounts(N);


    for(int i =0; i<N; ++i){
        cin >> lamp[i];
        int cnt = 0;
        for(char c : lamp[i]){
            if(c == '0') cnt++;
        }
        zeroCounts[i] = cnt;
    }

    cin >> K;

    map<string , int> samePattern;
    int answer = 0;

   for(int i =0; i<N; ++i){
       int zeros = zeroCounts[i];
       if(zeros <= K && ( K - zeros) % 2 == 0){
           samePattern[lamp[i]]++;
           answer = max(answer , samePattern[lamp[i]]);
       }
   }

    cout << answer << '\n';

    return 0;
}