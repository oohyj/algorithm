#include <iostream>

using namespace std;
int boards[128][128];
int answer[2];

void solve(int y , int x , int size){
    bool flag = true;
    for(int i =0; i<size; i++){
        for(int j=0; j<size;j++){
            if(boards[y][x] != boards[y+i][x+j]){
                flag = false;
            }
        }
    }

    if(flag) answer[boards[y][x]]++;
    else{
        size/=2;
        solve(y,x,size);
        solve(y+size , x , size);
        solve(y,x+size , size);
        solve(y+size , x+size , size);
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i =0; i < n; i++){
        for(int j =0; j <n; j++){
            cin >> boards[i][j];
        }
    }

    solve(0,0,n);

    cout << answer[0] <<'\n' << answer[1];
    return 0;
}
