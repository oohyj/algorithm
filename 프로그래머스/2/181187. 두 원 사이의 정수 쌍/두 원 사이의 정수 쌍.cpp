#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int x =1; x<=r2; x++){
        int maxY = (int)floor(sqrt(1LL * r2 * r2 - 1LL *x*x));
        int minY = 0;
        if(x < r1){
          minY = (int)ceil(sqrt(1LL*r1*r1 - 1LL *x*x));
            }
        answer +=(maxY - minY +1);
    }
    
    answer *=4;
    
    return answer;
}