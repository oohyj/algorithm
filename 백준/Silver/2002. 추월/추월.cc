#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<string, int> enter;
    vector<string> exit(N);

    string car;
    for (int i = 0; i < N; i++) {
        cin >> car;
        enter[car] = i;
    }

    for (int i = 0; i < N; i++) {
        cin >> exit[i];
    }

    int overtakes = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (enter[exit[i]] > enter[exit[j]]) {
                overtakes++;
                break;
            }
        }
    }

    cout << overtakes << '\n';

    return 0;
}