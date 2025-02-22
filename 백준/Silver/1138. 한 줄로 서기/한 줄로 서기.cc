#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> leftCount(N);
    vector<int> result(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> leftCount[i];
    }

    for (int i = 0; i < N; i++) {
        int count = leftCount[i];


        for (int j = 0; j < N; j++) {
            if (result[j] == 0) {
                if (count == 0) {
                    result[j] = i + 1;
                    break;
                }
                count--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << '\n';

    return 0;
}
