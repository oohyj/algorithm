#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int , int> m;
    for(int num : nums){
        m[num]++;
    }
    int m_size = m.size();
    int n_half = nums.size()/2;
    if(n_half <  m_size){
        answer = n_half;
    }
    else answer = m_size;
    return answer;
}