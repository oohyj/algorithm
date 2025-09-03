#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> button;

void changeMultiple(int num){
    for(int i = num-1; i < button.size(); i += num){
        button[i] =(button[i]== 1) ? 0 : 1;
    }
}

void changeRange(int num){ // num은 1-based 근데 지금 모든 연산은 0-based
    button[num-1] = (button[num-1] == 1)? 0 : 1;
    if(num == 1){ // 1인 경우
        return;
    }
    int left = num-2 , right = num;
    while(true){
        if(left < 0 || right >= button.size()) break;
        if(button[left] == button[right]) {
            button[left] = (button[left] == 1)? 0 : 1;
            button[right] = (button[right] == 1)? 0 : 1;
            left--;
            right++;
        }
        else break;
    }
}


int main(){
    int N;
    cin >> N;
    button.assign(N , 0);
    for(int i =0; i<N; ++i){
        cin >> button[i];
    }
    int T;
    cin >> T;
    map<int , int> gender;
    vector<int> number(T , 0);
    int a , b ;
    for(int i =0; i<T; ++i){
        cin >> a >> b;
        gender[i] = a;
        number[i] = b;
    }

    for(int i =0; i<T; ++i){
        if(gender[i] == 1){ // 남자면
            changeMultiple( number[i]);
        }else{ // 여자면
            changeRange(number[i]);
        }
    }


    for (int i = 0; i < N; i += 20) {
        int end = min(N, i + 20);
        for (int j = i; j < end; ++j) {
            cout << button[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}