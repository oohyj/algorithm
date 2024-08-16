#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n , k , sum =0;
    vector<int> sequence;
    vector<int> result;

    cin >> n >> k;

    sequence.assign(n , 0);
    for(int i =0; i<n; i++){
        cin >> sequence[i];
    }

    for(int i =0; i<k; i++){
        sum+=sequence[i];
    }
    result.push_back(sum);

    for(int i =k; i<n; i++){
        sum = sum + sequence[i] - sequence[i-k];
        result.push_back(sum);
    }


    sort(result.begin() , result.end());

    cout << result[result.size()-1] << '\n';

    return 0;
}
