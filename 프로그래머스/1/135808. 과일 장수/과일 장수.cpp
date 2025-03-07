#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.rbegin(), score.rend());

    int max_profit = 0;
    int n = score.size();

    for (int i = 0; i + m <= n; i += m) {
        int box_min_score = score[i + m - 1]; 
        max_profit += box_min_score * m;
    }

    return max_profit;
}