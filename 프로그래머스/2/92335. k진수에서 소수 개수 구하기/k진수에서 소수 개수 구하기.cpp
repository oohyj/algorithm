#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBaseK(int n , int k){
    if(n == 0) return "0";
    string result;
    
    while(n > 0){
        result.push_back(char('0' + n %k));
        n /= k;
    }
    reverse(result.begin() , result.end());
    return result;
}

bool isPrime(long long x){
    if( x < 2) return false;
    if(x == 2) return true;
    if( x %2 == 0) return false;
    for(long long i =3; i*i <=x; i+=2){
        if(x % i == 0) return false;
    }
    return true;
}


int solution(int n, int k) {
    int answer = 0;

    string target = toBaseK(n , k);
    string token;
    
    for(char c : target){
        if(c== '0'){
            if(!token.empty()){
                long long val = stoll(token);
                if(isPrime(val)) answer++;
            }
            token.clear();
        }
        else  token.push_back(c);
    }
    
    if(!token.empty()){
        long long val = stoll(token);
        if(isPrime(val))answer++;
    }
    
    
    return answer;
}