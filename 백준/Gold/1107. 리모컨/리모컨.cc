#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N , M;
vector<bool> isBroken(10);

bool isValid(int num){
    if(num == 0) return !isBroken[0];
    while(num > 0){
        if(isBroken[num%10]) return false;
        num /= 10;
    }
    return true;
}

int getLength(int num){
    if(num == 0) return 1;
    int len = 0;
    while(num >0){
        len++;
        num /= 10;
    }
    return len;
}


int main(){

    cin >> N >> M;
    while(M--){
        int channel;
        cin >> channel;
        isBroken[channel] = true;
    }

    int minPress = abs(N-100);

    for(int i =0; i<=999999; ++i){
        if(isValid(i)){
            int press = getLength(i) + abs(N-i);
            minPress = min(minPress , press);
        }
    }

   cout << minPress << '\n';

    return 0;
}
