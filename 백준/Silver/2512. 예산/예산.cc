#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, limit, sum = 0, max_money;
    vector<int> region;

    cin >> N;
    region.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> region[i];
        sum += region[i];
    }

    cin >> limit;

    if (sum <= limit) {
        max_money = *max_element(region.begin(), region.end());
        cout << max_money << '\n';
    } else {
        int start = 0;
        int end = *max_element(region.begin(), region.end());
        int mid , result;

        while (start <= end) {
            mid = (start + end) / 2;
            
            int total = 0;
            for (int i = 0; i < N; i++) {
                total += min(region[i], mid);
            }

            if (total <= limit) {
                result = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        cout << result << '\n';
    }

    return 0;
}