#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;

    cin >> N;

    vector<int> current(N , 0); // 현재 탬
    vector<int> correct(N , 0); // 올바른 탭
    vector<int> diff(N , 0);

    for(int i =0; i<N; ++i){
        cin >> current[i];
    }

    for(int i =0; i<N; ++i){
        cin >> correct[i];
    }

    for(int i =0; i<N; ++i){
        diff[i] = current[i] - correct[i];
    }

    long long boundary = 0;
    boundary = llabs(diff[0]);
    for(int i =1; i<N; ++i){
       boundary += llabs((long long)diff[i] - diff[i-1]);
    }

    boundary += llabs(diff[N-1]);

    cout << boundary/2 << '\n';

    return 0;
}