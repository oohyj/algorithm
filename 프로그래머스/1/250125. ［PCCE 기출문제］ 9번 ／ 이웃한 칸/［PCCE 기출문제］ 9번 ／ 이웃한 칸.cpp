#include <string>
#include <vector>

using namespace std;

int dx[] = {1 , 0 , -1 , 0};
int dy[] = { 0 , 1 , 0 , -1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    string color = board[h][w];
    for(int i = 0; i<4; i++){
        int newX = w + dx[i]; // 열
        int newY = h + dy[i]; // 행
        if(newX < 0 || newX >=n || newY < 0 || newY >=n) continue;
        if(board[newY][newX] == color){
            answer++;
        }
    }
    return answer;
}