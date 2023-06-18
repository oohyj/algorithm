#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solution(int x) {
    bool answer = true;

    int temp = x;

    vector <int> v;

    while(x>0){
        v.push_back(x%10);
        x /= 10;
    }

    int sum =0;

    for(int i  =0; i<v.size(); i++)
        sum += v[i];

    if((temp%sum) != 0 ) answer = false;

    return answer;
}

int main() {

    int n =13;
    cout << solution(n)<<endl;

    return 0;
}