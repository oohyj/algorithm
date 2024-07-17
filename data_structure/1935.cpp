#include <iostream>
#include <stack>

using namespace std;

const int MAX = 26;

int n , a ;
string input;

int num[MAX];
stack <double> s;

double cal(char c){

    double op1 , op2;
    op2 = s.top();
    s.pop();
    op1 = s.top();
    s.pop();
    switch(c){
        case '+' :
            return op1 + op2;
        case '-' :
            return op1 - op2;
        case '*' :
            return op1 * op2;
        case '/' :
            return op1 / op2;
    }
}

int main(){

    cin >> n >> input;

    for(int i = 0; i< n ; i++){
        cin >> a;
        num[i] = a;
    }

    for(int i =0; i< input.length(); i++){
        if( 'A' <= input[i] && input[i] <= 'Z'){
            s.push(num[input[i] - 'A']);
        }
        else {
            s.push(cal(input[i]));
        }
    }

    cout << fixed; // 고정시키기
    cout.precision(2);  // 무조건 소수점 두자리로 고정

    cout << s.top();

    return 0;
}