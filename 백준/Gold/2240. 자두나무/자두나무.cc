#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T , W;
    cin >> T >> W;

    vector<int> apple(T+1 , 0);

    for (int i = 1; i<=T; ++i)
    {
        cin >> apple[i];
    }

    vector<vector<int>> dp(T+1 , vector<int>(W+1 , 0));

    for (int t = 1; t <= T; t++)
    {
        for (int w = 0; w <= min(W , t); w++)
        {
            int cur = dp[t-1][w]; // 이동 안함
            if (w > 0)
            {
                cur = max (cur , dp[t-1][w-1]);
            }
            int pos = (w%2 == 0 ? 1 :2);
            if (apple[t] == pos) cur++;
            
            dp[t][w] = cur;

        }
    }
    
    int answer = 0;
    for (int w = 0; w <=W; ++w)
    {
        answer = max(answer , dp[T][w]);
    }
    
    cout << answer << '\n';

    return 0;
}
