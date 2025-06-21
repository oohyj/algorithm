#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> getPattern(const string& word) {
    unordered_map<char, int> mapping;
    vector<int> pattern;
    int nextIndex = 0;

    for (char ch : word) {
        if (mapping.find(ch) == mapping.end()) {
            mapping[ch] = nextIndex++;
        }
        pattern.push_back(mapping[ch]);
    }
    return pattern;
}

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    vector<vector<int>> patterns(N);

    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        patterns[i] = getPattern(words[i]);
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (patterns[i] == patterns[j]) {
                count++;
            }
        }
    }

    cout << count << '\n';
    return 0;
}