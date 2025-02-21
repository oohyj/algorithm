#include <iostream>

using namespace std;

bool isHansoo(int num) {
    if (num < 100) return true; 

    int a = num / 100;      
    int b = (num / 10) % 10;
    int c = num % 10;        

    return (b - a) == (c - b);
}

int main() {
    int N, count = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (isHansoo(i)) count++;
    }

    cout << count << '\n';
    
    return 0;
}
