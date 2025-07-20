#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 팰린드롬 판별 함수
bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();

    for (int i = 0; i < n; ++i) {
        string sub = s.substr(i);
        if (isPalindrome(sub)) {
            cout << n + i << '\n'; 
            return 0;
        }
    }

    return 0;
}