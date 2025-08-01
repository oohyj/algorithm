#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(9 , vector<int>(9));
vector<pair<int, int>> emptyCells;
bool row[9][10] , col[9][10] , square[9][10];

int getSquareIndex(int i , int j){
    return (i/3)*3 + (j/3);
}

bool solve(int idx){
    if(idx == emptyCells.size()){
        return true;
    }

    int x = emptyCells[idx].first;
    int y = emptyCells[idx].second;
    int sq = getSquareIndex(x , y);


    for (int num = 1; num <= 9; ++num) {
        if (!row[x][num] && !col[y][num] && !square[sq][num]) {
            board[x][y] = num;
            row[x][num] = col[y][num] = square[sq][num] = true;

            if (solve(idx + 1)) return true;

            board[x][y] = 0;
            row[x][num] = col[y][num] = square[sq][num] = false;
        }
    }

    return false;
}
int main(){

    for(int i = 0;  i < 9; ++i){
        string line;
        cin >> line;
        for(int j = 0; j<9; ++j){
       board[i][j] = line[j] - '0';
       if(board[i][j] == 0){
           emptyCells.emplace_back(i , j);
       }else{
           int num = board[i][j];
           row[i][num] = true;
           col[j][num] = true;
           square[getSquareIndex(i , j)][num] = true;
       }
        }
    }

    solve(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}