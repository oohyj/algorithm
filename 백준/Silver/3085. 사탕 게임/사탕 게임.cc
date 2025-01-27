#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4]={-1 , 0 , 1 , 0};
int dy[4] = { 0 , -1 , 0 , 1};
int max_candy = 0;
int N;

void cntCandy(vector<vector<char> >& candy){
    int max_count = 0;

    // 행 단위
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 1; j < N; j++) {
            if (candy[i][j] == candy[i][j - 1]) {
                count++;
            } else {
                max_count = max(max_count, count);
                count = 1;
            }
        }
        max_count = max(max_count, count); // 마지막 연속된 부분
    }

    // 열 단위
    for (int j = 0; j < N; j++) {
        int count = 1; // 현재 연속된 캔디 개수
        for (int i = 1; i < N; i++) {
            if (candy[i][j] == candy[i - 1][j]) {
                count++;
            } else {
                max_count = max(max_count, count);
                count = 1;
            }
        }
        max_count = max(max_count, count); // 마지막 연속된 부분
    }

    max_candy = max(max_count , max_candy);
}

int main(){

    vector<vector<char> > candy;

    cin >> N;
    candy.assign(N , vector<char>(N));

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> candy[i][j];
        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            for(int k =0; k<4; k++){
                int new_x = i + dx[k];
                int new_y = j + dy[k];
                if(new_x <N && new_x >=0 && new_y <N && new_y >=0){
                    swap(candy[i][j], candy[new_x][new_y]);
                    cntCandy(candy);
                    //되돌리기
                    swap(candy[i][j], candy[new_x][new_y]);
                }
            }
        }
    }

    cout << max_candy << '\n';

    return 0;
}
