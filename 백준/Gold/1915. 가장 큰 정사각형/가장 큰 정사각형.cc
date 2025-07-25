#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int N , M;
    cin >> N >>M;

    vector<vector<int>> board(N , vector<int>(M , 0));
    vector<vector<int>> dp(N , vector<int>(M , 0));

    for(int i = 0; i<N; ++i){
        string input;
        cin >> input;
        for(int j = 0; j<M; ++j){
          board[i][j] = input[j] - '0';
        }
    }

   dp = board;


    int answer = 0;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if (i == 0 || j == 0) {
                answer = max(answer, dp[i][j]);
            } else if (board[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

    cout << answer * answer << '\n';



    return 0;
}