#include <iostream>

using namespace std;

int main(){

    long long monkey , dog;
    cin >> monkey >> dog;

    long long dist = dog-monkey;
    long long day =0;
    long long move = 1;
    long long sum = 0;

    while(sum < dist){
        day++;
        sum += move;
        if(day % 2 == 0){ // 만약 짝수
            move++;
        }
    }

    cout << day << '\n';

    return 0;
}