#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, k;
    cin >> N >> k;

    long long digit = 1;    
    long long start = 1;      
    long long count;          

    while (true) {
        long long end = start * 10 - 1;
        if (end > N) end = N;

        count = end - start + 1;
        if (count <= 0) break;

        long long total_digits = count * digit;

        if (k > total_digits) {
            k -= total_digits;
            digit++;
            start *= 10;
        } else {
            break;
        }
    }

    if (count <= 0) {
        cout << -1;
        return 0;
    }

    long long index = (k - 1) / digit;        
    long long number = start + index;

    if (number > N) {
        cout << -1;
        return 0;
    }

    int digit_index = (k - 1) % digit;

    string s = to_string(number);
    cout << s[digit_index];

    return 0;
}