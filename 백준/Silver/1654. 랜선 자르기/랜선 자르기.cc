#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int K , N;
    cin >> K >> N;
    vector<long long> line(K , 0);

    for(int i =0; i<K; ++i){
        cin >> line[i];
    }

    long long right = *max_element(line.begin() , line.end());
    long long left = 1;
    long long mid;
    while(left <= right){
        mid = (left+right)/2;
        int cnt = 0;
        for(int i =0; i<K; ++i){
             cnt += line[i]/mid;
        }

        if(cnt >= N){
            left = mid+1;
        }
        else{
            right = mid -1;
        }
    }

    cout << right << '\n';


    return 0;
}
