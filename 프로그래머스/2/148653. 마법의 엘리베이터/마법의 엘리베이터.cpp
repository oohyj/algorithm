#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0) {
        int remainder = storey % 10; // 현재 자리의 숫자
        
        if (remainder > 5) { // 5보다 큰 경우
            answer += (10 - remainder); // 올림 선택
            storey += 10; // 다음 자리로 올림
        } else if (remainder < 5) { // 5보다 작은 경우
            answer += remainder; // 내림 선택
        } else { // remainder == 5인 경우
            // 다음 자리 숫자가 5 이상인지에 따라 올림 결정
            if ((storey / 10) % 10 >= 5) {
                answer += (10 - remainder);
                storey += 10; // 다음 자리로 올림
            } else {
                answer += remainder; // 내림 선택
            }
        }
        
        storey /= 10; // 다음 자리로 이동
    }
    
    return answer;
}