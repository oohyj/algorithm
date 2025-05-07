#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<string> result;
int dx[] = { 1 , 0 , 0 , -1};
int dy[] = { 0 , -1 , 1 , 0};
char dir[] = { 'd' , 'l' , 'r' , 'u'};

void dfs(int n , int m , int x , int y , int r , int c , int k , string now){
    int dist = abs(r-x) + abs(c-y);
   if (now.size() > k || now.size() + dist > k || (k - now.size() - dist) % 2 != 0) return;
    
    if(now.size() == k){
        if(x == r && y == c){
            result.push_back(now);
        }
        return;
    }
    
    for(int i =0; i<4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >=0 && nx <n && ny >=0 && ny < m){
            dfs(n  , m , nx , ny , r , c , k , now+dir[i]);
            if(!result.empty()) return;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    dfs(n , m , x-1 , y-1 , r-1 , c-1, k ,"");
    
    if(result.empty()) answer = "impossible";
    else answer = result[0];
    
    return answer;
}