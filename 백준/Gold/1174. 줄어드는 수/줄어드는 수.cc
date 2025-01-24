#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> numbers;

// string( size_t n , char c) 길이가 n인 문자열을 생성

void backtrack(int idx, string temp) {
    if (!temp.empty()) {
        numbers.push_back(stoll(temp));
    }
    for (int i = idx - 1; i >= 0; i--) {  // 감소하는 순서로 숫자 추가
        backtrack(i, temp + char('0' + i)); // 처음에 idx가 9라면 backtrack(8 , "98") 이런식으로 재귀 호출
        // 문자열 길이 추가
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 9; i >= 0; i--) {  // 각 숫자(0~9)로 시작
        backtrack(i, string(1, '0' + i));
    }

    sort(numbers.begin(), numbers.end());  // 생성된 숫자 정렬

    if (N > numbers.size()) {
        cout << -1;
    } else {
        cout << numbers[N - 1];
    }

    return 0;
}