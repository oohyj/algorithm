#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K, result = 0;
vector<vector<char>> words;  // 각 단어를 글자 리스트로 저장
bool visited[26];

int canReadable() {
    int cnt = 0;
    for (const auto& w : words) {
        bool canRead = true;
        for (char c : w) {
            if (!visited[c - 'a']) {
                canRead = false;
                break;
            }
        }
        if (canRead) cnt++;
    }
    return cnt;
}

void backtrack(int index, int depth) {
    if (depth == K - 5) {
        result = max(result, canReadable());
        return;
    }

    for (int i = index; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = true;
            backtrack(i + 1, depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> K;

    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }

    // 필수 글자 미리 방문 처리
    visited['a' - 'a'] = true;
    visited['c' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        vector<char> trimmed;

        for (int j = 4; j < s.size() - 4; ++j) {  // anta~tica 제외
            trimmed.push_back(s[j]);
        }

        words.push_back(trimmed);
    }

    backtrack(0, 0);
    cout << result << '\n';
    return 0;
}