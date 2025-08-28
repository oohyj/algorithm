#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rt[51] , rd[51];
tuple<int , int, int> edge[100000];

int Find(int node){
    if(node == rt[node]){
        return node;
    }
    return rt[node] = Find(rt[node]);
}

void Union(int a , int b){
    a = Find(a);
    b = Find(b);

    if(a==b) return;
    if(rd[a] < rd[b]) rt[a] = b;
    else if(rd[a]  > rd[b]) rt[b] = a;
    else {
        rt[b] = a;
        rd[a]++;
    }
}

int ch2int(char c){
    int ret = 0;
    if(c >= 'a' && c <= 'z') ret = c - 97 +1;
    if(c >= 'A' && c <= 'Z') ret = c -65 +27;
    return ret;
}

int main(){

    int N;
    cin >> N;

    int total = 0 , edgeCnt = 0;

    for(int i =1;i<=N; ++i){
       string str;
       cin >> str;
       for(int j =1; j <=N; ++j){
         if(str[j-1] != '0') {
             int len = ch2int(str[j - 1]);
             total += len; // 총 길이에 추가
             if (i != j) edge[edgeCnt++] = {len, i, j};
         }
       }
       rt[i] = i;
    }

    sort(edge , edge+edgeCnt);

    int cnt =0 , used = 0;

    for(int i =0; i<edgeCnt; ++i){
        auto[w , u , v] = edge[i];
        if(Find(u) == Find(v)) continue;
        Union(u , v);
        used += w;
        cnt++;
        if(cnt == N-1) break;
    }

    if(cnt < N-1) cout << "-1";
    else cout << total - used;
    return 0;
}