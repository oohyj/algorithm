#include <iostream>
#include <vector>
#include <unordered_set> // 정렬할 필요가 없어서 unordered_set
#include <string>

//백트래킹 사용해야함

using namespace  std;

int n , k;
unordered_set<string> result;
vector<int> cards;
vector<int> visited;

void func(string sum , int count){
    if(count != k){
        for(int i =0; i<n; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                func(sum+ to_string(cards[i]) , count+1);
                visited[i] = 0;
            }
        }
    }
    else {
        result.insert(sum);
    }
}


int main(){

    cin >> n >> k;

    cards.assign(n,0);
    visited.assign(n,false);
    for(int i =0; i<n; i++){
        cin >> cards[i];
    }

    func("" , 0);
    cout << result.size() <<'\n';
    return 0;
}
