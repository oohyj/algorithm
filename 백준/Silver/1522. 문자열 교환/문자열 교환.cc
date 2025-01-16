#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int n = input.size();
    int cnt_a = 0;
    
    for (int i = 0; i < n; i++) {
        if (input[i] == 'a') {
            cnt_a++;
        }
    }
    int comp = 0;
    for (int i = 0; i < cnt_a; i++) {
        if (input[i] == 'a') {
            comp++;
        }
    }

    int min_swaps = cnt_a - comp;

 
    for (int i = 0; i < n; i++) {
       
        if (input[i] == 'a') {
            comp--;
        }

      
        if (input[(i + cnt_a) % n] == 'a') {
            comp++;
        }

       
        min_swaps = min(min_swaps, cnt_a - comp);
    }

    cout << min_swaps;

    return 0;
}