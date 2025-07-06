#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k;
char sign[9];
bool visited[10];
vector<string> answers;

bool isValid(char a, char b, char op) {
    if (op == '<') return a < b;
    if (op == '>') return a > b;
    return false;
}

void dfs(int depth, string num) {
    if (depth == k + 1) {
        answers.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (!visited[i]) {
            if (depth == 0 || isValid(num[depth - 1], i + '0', sign[depth - 1])) {
                visited[i] = true;
                dfs(depth + 1, num + to_string(i));
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> sign[i];
    }

    dfs(0, "");

    sort(answers.begin(), answers.end());

    cout << answers.back() << '\n'; 
    cout << answers.front() << '\n'; 

    return 0;
}