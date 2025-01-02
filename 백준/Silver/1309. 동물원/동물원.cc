#include <iostream>
#include <vector>
using namespace std;
#define MOD 9901
int N;
vector<vector<int>> cages;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    cages = vector<vector<int>>(N, vector<int>(3));
    cages[0][0] = cages[0][1] = cages[0][2] = 1;
    for (int i = 1; i < N; ++i)
    {
        cages[i][0] = (cages[i - 1][1] + cages[i - 1][2]) % MOD;
        cages[i][1] = (cages[i - 1][0] + cages[i - 1][2]) % MOD;
        cages[i][2] = (cages[i - 1][0] + cages[i - 1][1] + cages[i - 1][2]) % MOD;
    }
    cout << (cages[N - 1][0] + cages[N - 1][1] + cages[N - 1][2]) % MOD;
    return 0;
}