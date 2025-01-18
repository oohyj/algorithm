#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
vector<vector<int> > map;
vector<vector<bool> > visited;
int dx[4] = {-1 , 0 , 1 , 0};
int dy[4] = { 0 , -1 , 0 , 1};

int bfs(int a , int b){
    queue<pair<int , int> > q;
    visited[a][b] = true;
    q.push(make_pair(a , b));
    int dimension = 1; // 넓이

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i =0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(new_x >=0  && new_x < N && new_y >=0 && new_y <N && map[new_x][new_y] == 1 && !visited[new_x][new_y]){
                q.push(make_pair(new_x , new_y));
                visited[new_x][new_y] = true;
                dimension += 1;
            }
        }
    }

    return dimension;
}

int main(){


    cin >> N;

    map.assign(N , vector<int>(N , 0));
    visited.assign(N , vector<bool>(N , false));
    vector<int> answer;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row; 
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0'; 
        }
    }


    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++) {
            if (map[i][j] == 1 && visited[i][j] == false){
                int extent = bfs( i , j);
                answer.push_back(extent);
            }
        }
    }

    sort(answer.begin() , answer.end());
    cout << answer.size() <<'\n';

    for(auto iter : answer){
        cout << iter << '\n';
    }

    return 0;
}
