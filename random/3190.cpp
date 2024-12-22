#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace  std;

int arr[101][101]; // 1 뱀 , 2 사과
int N , K , L;
int ans;
int dir_idx = 1; //방향
int dx[4] = { 0 , 1 , 0 , -1};
int dy[4] = { -1 , 0 , 1 , 0};

int main(){

    cin >> N >> K;
    for(int i =0; i<K; i++){
        int row , col;
        cin >> row >> col;
        arr[row][col] = 2;
    }
    cin >> L;
    queue<pair<int , char> > time;
    for(int i =0; i<L; i++){
        int X; char C;
        cin >> X >> C;
        time.push(make_pair(X , C));
    }

    arr[1][1] = 1;
    deque<pair<int , int> > dq;
    dq.push_back(make_pair(1 ,1));

    while(1){
        ans++; // 시간
        int nRow = dq.back().first + dy[dir_idx];
        int nCol = dq.back().second + dx[dir_idx]; // 처음에 오른쪽 방향을 보고 있음
        if(nRow <= 0 || nRow >N || nCol <=0 || nCol > N){
            break;
        }
        if(arr[nRow][nCol] !=2){ // 사과가 아니면
            arr[dq.front().first][dq.front().second] = 0; // 끝을 줄이기
            dq.pop_front();
        }
        arr[nRow][nCol] = 1; // 뱀 이동
        dq.push_back(make_pair(nRow , nCol)); // 뱀 위치 deque에 넣기

        if(ans == time.front().first){ // 현재 시간이 방향 변경 시간과 같다면
            char ch = time.front().second;
            if(ch == 'D'){
                dir_idx = (dir_idx +1) %4;
            }
            else dir_idx = (dir_idx -1 +4) %4;
            time.pop();
        }
    }

    cout << ans << '\n';
    return 0;
}