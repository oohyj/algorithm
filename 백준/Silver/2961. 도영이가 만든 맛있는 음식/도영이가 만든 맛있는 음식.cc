#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int min_diff = INT_MAX;
int N;

vector<bool> visited;
vector<int> sour;
vector<int> bitter;

void backtracking(int now , bool isTrue){

    if(now >= N) return;
    if(isTrue == true) {
        visited[now] = true;
    }

    int S = 1 , B = 0;
    for(int i =0; i<N; i++){
        if(visited[i] == true){
            S *= sour[i];
            B += bitter[i];
        }
    }
    int difference = abs(S-B);
    min_diff = min(difference , min_diff);

    // 기존 방문 그대로 하고 다음 방문 시작
    backtracking(now+1 , true);

    // 기존 방문 취소
    visited[now] = false;
    backtracking(now+1 , true);

}

int main(){

    cin >> N;
    sour.assign(N , 0);
    bitter.assign(N , 0);
    visited.assign(N , false);

    for(int i =0; i<N; i++){
        cin >> sour[i] >> bitter[i];
    }


    //처음에는 0번 인덱스 true로 시작
    backtracking(0 , true);


    cout << min_diff <<'\n';

    return 0;
}
