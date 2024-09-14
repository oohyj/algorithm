#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >>n;

    vector<double> amount;
    amount.assign(n , 0);

    for(int i =0; i<n; i++){
        cin >> amount[i];
    }

    sort(amount.begin() , amount.end());

    double sum = 0;
    sum += amount[amount.size()-1];

    for(int i =0; i<amount.size()-1; i++){
        sum += amount[i]/2;
    }

    cout << sum << '\n';

    return 0;
}
