#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N , K;

    cin >> N >> K;

    vector<int> a(N);
    vector<int> dp(K+1 , 0);
    dp[0] = 1;

    for (int i = 0; i<N; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i<N; ++i)
    {
        for (int j = a[i]; j <=K; ++j)
        {
            dp[j] += dp[j - a[i]];
        }
    }

    cout << dp[K] << '\n';
    
    return 0;
}
