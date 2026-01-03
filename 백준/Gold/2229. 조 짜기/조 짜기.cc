#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> student(N); // 점수 , 나이

    for (int i = 0; i<N; ++i)
    {
        int score;
        cin >> score;
        student[i] = score;
    }

    vector<int> dp(N, 0);
    dp[0] = 0;

    for (int i =1; i<N; ++i)
    {
        int min_score= student[i];
        int max_score = student[i];
        int best = 0;
       for (int j = i; j >=0; --j)
       {
          min_score = min(min_score , student[j]);
           max_score = max(max_score , student[j]);
           int groupScore = max_score - min_score;
           int prev = ( j > 0 ? dp[j-1] : 0);

           best = max(best , prev + groupScore);
       }
        dp[i] = best;

    }
    cout << dp[N-1] << '\n';
    return 0;

}
