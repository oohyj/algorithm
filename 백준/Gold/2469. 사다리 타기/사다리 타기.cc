#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    string target;
    cin >> target;

    vector<string> ladder(n);
    int hidden = -1;
    for (int i = 0; i < n; i++) {
        cin >> ladder[i];
        if (ladder[i][0] == '?') hidden = i;
    }

    vector<char> top(k), bottom(k);
    for (int i = 0; i < k; i++) top[i] = char('A' + i);
    for (int i = 0; i < k; i++) bottom[i] = target[i];

    for (int i = 0; i < hidden; i++) {
        for (int j = 0; j < k - 1; j++) {
            if (ladder[i][j] == '-') {
                swap(top[j], top[j + 1]);
            }
        }
    }

    for (int i = n - 1; i > hidden; i--) {
        for (int j = 0; j < k - 1; j++) {
            if (ladder[i][j] == '-') {
                swap(bottom[j], bottom[j + 1]);
            }
        }
    }

    string answer(k - 1, '*');
    bool possible = true;

    int j = 0;
    while (j < k - 1) {
        if (top[j] == bottom[j]) {
            j++;
        } else if (top[j] == bottom[j + 1] && top[j + 1] == bottom[j]) {
            answer[j] = '-';
            swap(top[j], top[j + 1]);
            j += 2;
        } else {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << string(k - 1, 'x') << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}