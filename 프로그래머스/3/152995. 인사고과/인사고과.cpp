#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 0;
 
 
    int myA = scores[0][0];
    int myB = scores[0][1];
    int mySum = myA + myB;
    sort(scores.begin() , scores.end() , [](const vector<int>& a , const vector<int>& b){  if(a[0] == b[0]) {return a[1] < b[1];} 
return a[0] > b[0]; });
         
    int maxPeer = 0;
    int rank = 1;
         
    for(auto& iter : scores){
        int a = iter[0] , b = iter[1];
        
        if(a > myA && b > myB){
            return -1;
        }
        
        if(b >= maxPeer){
            maxPeer = max(maxPeer , b);
            if(a+b > mySum){
                ++rank;
            }
        }
    }
    
    answer = rank; 
    return answer;
}