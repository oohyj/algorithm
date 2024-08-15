#include <iostream>
#include <string>

using namespace std;

string findMax(string input) {
    string result = "";
    int cnt = 0; // 연속된 M의 개수

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'M') {
            cnt++;
        } else if (input[i] == 'K') {
            if (cnt > 0) {
                result += "5";
                for (int j = 0; j < cnt; j++) {
                    result += "0";
                }
            } else {
                result += "5";
            }
            cnt = 0;
        }
    }
    // M으로 끝나는 경우
    if (cnt > 0) {
        result += "1";
        for (int j = 1; j < cnt; j++) {
            result += "1";
        }
    }

    return result;
}

string findMin(string input) {
    string result = "";
    int cnt = 0; // 연속된 M의 개수

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'M') {
            cnt++;
        } else if (input[i] == 'K') {
            if (cnt > 0) {
                result += "1";
                for (int j = 1; j < cnt; j++) {
                    result += "0";
                }
            }
            result += "5";
            cnt = 0;
        }
    }
    // M으로 끝나는 경우
    if (cnt > 0) {
        result += "1";
        for (int j = 1; j < cnt; j++) {
            result += "0";
        }
    }

    return result;
}

int main() {
    string input;
    cin >> input;

    cout << findMax(input) << '\n';
    cout << findMin(input) << '\n';

    return 0;
}
