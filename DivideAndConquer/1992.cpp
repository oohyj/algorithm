#include <iostream>

using namespace std;

int n;
int arr[65][65];
string answer = "";

void dnc(int x, int y, int size) {
    bool flag = false;
    int first = arr[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != first) {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        answer += '(';
        dnc(x, y, size / 2);
        dnc(x, y + size / 2, size / 2);
        dnc(x + size / 2, y, size / 2);
        dnc(x + size / 2, y + size / 2, size / 2);
        answer += ')';
    } else {
        answer += to_string(first);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            arr[i][j] = temp - '0'; // 0,1만 나오는 것처럼 단일문자만 나오는 경우라면 char로 하는 게 더 메모리가 효율 ,char는 1바이트 int는 8바이트
        }
    }

    dnc(0, 0, n);

    cout << answer << '\n';

    return 0;
}
