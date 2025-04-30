#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    int n , T;
    cin >> n >> T;
    vector<pair<int , int>> loc(n);
    vector<bool> visited(n , false);

    for(int i =0; i<n; ++i){
        int a , b;
        cin >> a >> b;
        loc[i] = {a , b};
    }

    sort(loc.begin() , loc.end() , [](const pair<int , int> a , const pair<int , int> b){
        return a.second < b.second; // y 좌표 오름차순으로 정렬
    });

    int now_x = 0 , now_y = 0;

    queue<tuple<int, int ,int>> q; // x , y , 횟수
    q.push({now_x  , now_y , 0});


    while(!q.empty()){
        auto[x ,y , cnt]  = q.front();
        if(y == T){
            cout << cnt << '\n';
            return 0;
        }
        q.pop();

        int left = 0 , right = 0;
        while(left < n && loc[left].second < y-2) left++;
        while(right <n && loc[right].second <= y+2) right++;

        for(int i = left; i <right; ++i){
            if(!visited[i] && abs(loc[i].first - x) <=2 && abs(loc[i].second - y) <=2){
                visited[i] = true;
                q.push({loc[i].first , loc[i].second , cnt+1});
            }
        }


    }

    cout << -1 << '\n';

    return 0;
}
