#include <bits/stdc++.h>
using namespace std;

int main() {
  
    long long N;
    if (!(cin >> N)) return 0;


    vector<long long> nums;
    nums.reserve(1023);

 
    for (int mask = 1; mask < (1 << 10); ++mask) {
        long long val = 0;
      
        for (int d = 9; d >= 0; --d) {
            if (mask & (1 << d)) {
                val = val * 10 + d;
            }
        }
        nums.push_back(val);
    }

   
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());


    if (N < (long long)nums.size()) {
        cout << nums[N] << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}