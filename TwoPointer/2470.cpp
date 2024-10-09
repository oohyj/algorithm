#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> liquid;
    cin >> n;

    liquid.assign(n , 0);

    for(int i =0; i<n; i++){
        cin >> liquid[i];
    }

    sort(liquid.begin() , liquid.end());

    int start = 0;
    int end = n-1;

    int closest_sum = liquid[start] + liquid[end];
    int closest_left = start;
    int closest_right = end;

    while(start < end){

        int sum = liquid[start] + liquid[end];

        if(abs(sum) < abs(closest_sum)){
            closest_sum = sum;
            closest_left = start;
            closest_right = end;
        }

        if(sum > 0){
            end--;
        }
        else {
            start++;
        }
    }

    cout << liquid[closest_left] << ' ' << liquid[closest_right] <<'\n';

    return 0;
}
