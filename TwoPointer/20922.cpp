#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n  , k;
    vector<int> nums;
    cin >> n >> k;

    nums.assign(n,0);
    for(int i =0; i<n; i++){
        cin >> nums[i];
    }

    map<int , int> cnt;
    int length =0;
    int start =0;

    for(int i =0; i<n; i++){
        cnt[nums[i]]++;

        while(cnt[nums[i]] > k){
            cnt[nums[start]]--;
            if(cnt[nums[start]] == 0){
                cnt.erase(nums[start]);
            }
            start++;
        }
        length = max(length , i - start +1);
    }

    cout << length <<'\n';

    return 0;


}
