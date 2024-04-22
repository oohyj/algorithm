#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , a;
    queue<int> q;
    string input;

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> input;
        if (input == "push") {
            cin >> a;
            q.push(a);
        } else if (input == "pop") {
            if (q.empty()) { //큐가 비어있으면
                cout << "-1" << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (input == "size") {
            cout << q.size() << "\n";
        } else if (input == "empty") {
            cout << q.empty() << "\n";
        } else if (input == "front") {
            if (q.empty()) {
                cout << "-1" << "\n";
            }
            else cout << q.front() << "\n";
        } else if (input == "back") {
            if (q.empty()) {
                cout << "-1" << "\n";
            }
            else cout << q.back() << "\n";
        }
    }

    return 0;
}
