#include<iostream>
#include<algorithm>
#include <string>

using namespace std;

string factorial[101][101];

string bigNumAdd(string n1 , string n2){
    int sum =0;
    string result;

    //1의 자리부터 더하기
    while(!n1.empty() || !n2.empty() || sum){
        if(!n1.empty()){
            sum += n1.back() -'0';
            n1.pop_back();
        }
        if(!n2.empty()){
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum%10) +'0'); // n1과 n2 더한 수의 1의 자리
        sum /= 10;
    }

    //1의 자리부터 더했으니까 뒤집어준다.
    reverse(result.begin() , result.end());
    return result;
}

string combination(int n , int m){
    if(n==m || m==0 ){
        return "1";
    }

    string &result = factorial[n][m]; // 참조형 변수

    if(result !=""){ // 이미 계산했으면 바로 return, memoization 기법
        return result; //factorial 배열에 이미 값이 있다면 바로 return
    }

    //파스칼삼각형 원리 이용
    result = bigNumAdd(combination(n-1 , m-1) , combination(n-1, m));
    return result;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , m;

    cin >> n >> m;

    cout << combination(n , m) <<'\n';


    return 0;
}