#include <iostream>
#include <vector>

using namespace std;

int n , s ,cnt =0;
vector<int> sequence;

void backTrack(int a , int sum){
    if(a == n){
         if( sum == s){
             cnt++;
         }
         return;
    }
    backTrack(a+1 , sum);
    backTrack(a+1 , sum + sequence[a]);
}

int main() {

    cin >> n >> s;
    sequence.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    backTrack(0 , 0);

    if(s == 0){
        cnt--;
    }

    cout << cnt << '\n';

    return 0;
}
