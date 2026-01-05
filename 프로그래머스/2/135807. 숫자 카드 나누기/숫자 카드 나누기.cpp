#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findGcd(int a , int b){
    if(b == 0) return a;
    else return findGcd( b , a %b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];
    
    for(int i = 1; i < arrayA.size(); ++i){
        gcdA = findGcd(gcdA ,arrayA[i]);
        gcdB = findGcd(gcdB , arrayB[i]);
    }
    bool isgcdA = true , isgcdB = true;
    // A 카드들에 적힌 모든 숫자를 나눌 수 o , B 카드들에 적힌 모든 숫자를 나눌 수 x
    for(int i = 0; i<arrayB.size(); ++i){
        if(arrayB[i] % gcdA == 0) {
            isgcdA = false;
        }
    }
    
    // B 카드들에 적힌 모든 숫자를 나눌 수 o , A 카드들에 적힌 모든 숫자를 나눌 수 x
     for(int i = 0; i<arrayA.size(); ++i){
        if(arrayA[i] % gcdB == 0) {
            isgcdB = false;
        }
    }
    
    if(isgcdA && isgcdB){
        answer = max(gcdA , gcdB);
    }
    else if(isgcdA && !isgcdB){
        answer = gcdA;
    }
    else if(!isgcdA && isgcdB){
        answer = gcdB;
    }
    else{
        answer = 0;
    }
    return answer;
}