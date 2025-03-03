#include <string>
#include <vector>
#include <iostream>
#include <cmath>  

using namespace std;

int calDivisor(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++; 
            if (i != n / i) cnt++;  
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++) {
        int divisorCount = calDivisor(i); 
        if (divisorCount > limit) {
            answer += power;
        } else {
            answer += divisorCount;
        }
    }
    return answer;
}