#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX  100001

vector<int> list[MAX];
bool visited[MAX];
int d[MAX];


void bfs(){

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i =0; i<list[x].size(); i++){
            int node = list[x][i];
            if(!visited[node]){
                d[node] = x;
                q.push(node);
                visited[node] = true;
            }
        }
    }
}



int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n , a , b;

    cin >> n;


    for(int i =0; i<n-1; i++){
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    bfs();

    for(int i =2; i<=n; i++){
        cout << d[i] <<'\n';
    }

    return 0;
}