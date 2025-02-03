#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    int wallet_small = min(wallet[0], wallet[1]);
    int wallet_big = max(wallet[0], wallet[1]);

    while ((bill[0] > wallet_big || bill[1] > wallet_small) && 
           (bill[1] > wallet_big || bill[0] > wallet_small)) {
        
        if (bill[0] >= bill[1]) {
            bill[0] /= 2;
        } else {
            bill[1] /= 2;
        }
        answer++;
    }

    return answer;
}