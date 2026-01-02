#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getGcd(int a , int b)
{
    if (b == 0) return a;
    if (a % b == 0)
    {
        return b;
    }

    return getGcd(b, a % b);
}

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N , 0);

    for (int i = 0; i<N; ++i)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<int> diff(N-1 , 0);

    for (int i =1; i<N; ++i)
    {
       diff[i-1] = nums[i] - nums[i-1];
    }

    int answer = getGcd(diff[0] , diff[1]);
    for (int i = 2; i< N-1; ++i){
       answer = getGcd(answer  , diff[i]);
    }

    for (int i = 2; i <= answer; ++i)
    {
        if (answer % i == 0)
        {
            cout << i << '\n';
        }
    }

}
