#include <iostream>
#include <vector>

using namespace std;
int N , M , answer = 0;
vector<vector<bool>> board;

bool isSquare(int x , int y) { // 격자판에서 4각형이 만들어지거나 암튼 그런 거 체크할 때 오른쪽 맨 아래라고 생각해도 됨
    if (x > 0 && y > 0) {
        return board[x - 1][y] && board[x][y - 1] && board[x - 1][y - 1];
    }
    return false;
}


void backtracking(int idx){
    if(idx == N*M){ // 마지막 격자까지 탐색을 끝냄
        answer++;
        return;
    }

    int i = idx / M;
    int j = idx % M;
    backtracking(idx+1); // 이번 board[i][j]를 채우지 않고
    if(!isSquare(i , j)){
        board[i][j] = true;
        backtracking(idx+1);
        board[i][j] = false;
    }
}

int main(){

    cin >> N >> M;
    board.assign(N , vector<bool>(M , false));


    backtracking(0);

    cout << answer << '\n';

    return 0;
}
