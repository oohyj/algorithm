#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool isPossible(vector<int>& lectures, int N, int M, int mid) {
    int count = 1; 
    int sum = 0;

    for (int i = 0; i < N; i++) {
        if (sum + lectures[i] > mid) { 
            count++;
            sum = 0;
        }
        sum += lectures[i]; 
    }

    return count <= M; 
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> lectures(N);
    int maxLength = 0, totalLength = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> lectures[i];
        maxLength = max(maxLength, lectures[i]); 
        totalLength += lectures[i]; 
    }

    int left = maxLength, right = totalLength, result = totalLength;
    
    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(lectures, N, M, mid)) {
            result = mid; 
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}