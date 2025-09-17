#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> scale(N , 0);

    for(int i =0; i<N; ++i){
        cin >> scale[i];
    }

    sort(scale.begin() , scale.end());


     long long reach =0;

     for(int w : scale){
         if(w > reach+1) break;
         reach += w;
     }

     cout << reach+1 << '\n';

    return 0;
}
