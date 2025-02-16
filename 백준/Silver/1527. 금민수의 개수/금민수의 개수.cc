#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> luckyNumbers;

void generateLuckyNumbers(long long num) {
    if (num > 1e9) return; 
    luckyNumbers.push_back(num);
    generateLuckyNumbers(num * 10 + 4); 
    generateLuckyNumbers(num * 10 + 7); 
}

int main() {
    long long A, B;
    cin >> A >> B;
    
    generateLuckyNumbers(4);
    generateLuckyNumbers(7);
    
    sort(luckyNumbers.begin(), luckyNumbers.end());
    
    int left = lower_bound(luckyNumbers.begin(), luckyNumbers.end(), A) - luckyNumbers.begin();
    int right = upper_bound(luckyNumbers.begin(), luckyNumbers.end(), B) - luckyNumbers.begin();

    cout << right - left << '\n';

    return 0;
}