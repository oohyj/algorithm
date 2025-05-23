#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1 , q2;
    long long sum1 = 0 , sum2 = 0;
    for(int i =0; i<queue1.size(); ++i){
        sum1 += queue1[i];
        q1.push(queue1[i]);
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }
    
    int maxCount = queue1.size()*3;
    int count = 0;
    while(count <= maxCount){
        if(sum1 == sum2){
           return count;
        }
        if(sum1 > sum2){
            if(q1.empty()) return -1;
            int n = q1.front();
            q1.pop();
            q2.push(n);
            sum1 -= n;
            sum2 += n;
        }
        else{
            if(q2.empty()) return -1;
            int n = q2.front();
            q2.pop();
              q1.push(n);
            sum1 +=n;
            sum2 -=n;
        }
        ++count;
    }
    return -1;
}