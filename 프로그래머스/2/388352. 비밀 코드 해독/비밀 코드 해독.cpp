#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    int m = q.size();
    vector<int> comb(n,0); // 크기가 n인 벡터 생성
    
    for(int i =0; i<5; i++){
        comb[n-i-1] = 1; // 전체 n 중에 5개만 1로 저장
    }
    
    //next_permutation을 사용해 모든 조합 확인
    do{
        bool flag = true;
        for(int i =0; i<m; i++){
            // comb에서 해당 인덱스가 선택된(1) 개수 계산
            if(ans[i] != comb[q[i][0]-1] +comb[q[i][1]-1]+comb[q[i][2]-1]+comb[q[i][3]-1]+comb[q[i][4]-1]){
                flag = false; // 하나라도 불일치하면 후보에서 제외
                break;
            }
        }
        
        if(flag) ++answer; // 모든 조건을 만족하면 증가
    }while(next_permutation(comb.begin() , comb.end())); // 다음 조합 생성

   

    return answer;
}
