#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> pole(N , 0);
    for(int i =0; i<N; ++i){
        cin >> pole[i];
    }

    vector<int> tail;
    tail.reserve(N);

    for(int p : pole){
        auto it = lower_bound(tail.begin() , tail.end() ,p);
        if(it == tail.end() && p > tail[tail.size()-1]) tail.push_back(p);
        else *it = p;
    }

    cout << N - tail.size() << '\n';
    return 0;
}