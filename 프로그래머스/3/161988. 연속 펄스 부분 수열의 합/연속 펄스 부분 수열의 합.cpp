#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long findMax(vector<long long>& arr){
    long long maxValue = arr[0];
    long long current = arr[0];
    for(int i =1; i<arr.size(); ++i){
        current = max(arr[i] , current+arr[i]);
        maxValue = max(maxValue , current);
    }
    
    return maxValue;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    int n = sequence.size();
    vector <long long> pulse1(n);
    vector <long long> pulse2(n);
    
    for(int i =0; i<n; ++i){
        int sign = (i%2 == 0)?1 : -1;
        pulse1[i] = sequence[i] * sign;
        pulse2[i] = sequence[i] * -sign;
    }
    
    answer = max(findMax(pulse1) , findMax(pulse2));
    
    return answer;
}