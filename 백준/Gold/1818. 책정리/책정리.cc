#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> books(N , 0);
    vector<int> tail;
    for(int i =0; i<N; ++i){
        cin >> books[i];
    }

    for(int x : books){
        auto it = lower_bound(tail.begin() , tail.end() , x);

        if(it == tail.end())  tail.push_back(x);
        else *it = x; // 끝값을 더 작은 값으로 바꿔주기
    }

    int len = tail.size();

    cout << N - len << '\n';



    return 0;
}