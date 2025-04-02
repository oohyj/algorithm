#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 0 , 0 , -1 , 1};
int dy[] = { 1 , -1 , 0 , 0};
int dice[] = { 0 , 0 , 0 , 0 , 0 , 0};

void manageDice(int command){
    int top = dice[0] , bottom = dice[1] , front = dice[2] , back= dice[3] , left = dice[4] , right = dice[5];

    if(command == 1){ // 동쪽
        dice[0] = left;
        dice[1] = right;
        dice[4] = bottom;
        dice[5] = top;
    }
    else if(command == 2){ // 서쪽
        dice[0] = right;
        dice[1] = left;
        dice[4] = top;
        dice[5] = bottom;
    }
    else if(command == 3){ // 북쪽
        dice[0] = front;
        dice[1] = back;
        dice[2] = bottom;
        dice[3] = top;
    }
    else if(command == 4){ // 남쪽
        dice[0] = back;
        dice[1] = front;
        dice[2] = top;
        dice[3] = bottom;
    }
}


int main(){

    int n , m , x , y , k;

    cin >>  n >> m >> x >> y >> k;

    vector<vector<int>> board(n , vector<int>(m));

    for(int i =0; i<n; ++i){
        for(int j =0; j <m; ++j){
            cin >> board[i][j];
        }
    }



    vector<int> commands(k);

    for(int i =0; i<k; ++i){
        cin >> commands[i];
    }

    for(int command : commands){

        int nx = x + dx[command-1];
        int ny = y + dy[command-1];

        if(nx >=0 && nx <n && ny >= 0 && ny < m){
            manageDice(command);
            if(board[nx][ny] == 0){
                board[nx][ny] = dice[1];
            }
            else{
                dice[1] = board[nx][ny];
                board[nx][ny] = 0;
            }

            x = nx ;
            y = ny;

            cout << dice[0] <<'\n';
        }
    }


    return 0;
}
