#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int to;
    int p , q; // a:b = p : q
};

vector<vector<Edge>> material; // 간선 배수 저장할 연결리스트
vector<long long> num;
vector<long long> den;
vector<bool> visited;

long long findGcd(long long a , long long b){

    while(b != 0){
        long long r = a % b;
        a = b;
         b = r;
    }

    return a >= 0? a : -a;
}

long long findLcm(long long a , long long b){
    if(a== 0 || b == 0) return 0;
    return (a / findGcd(a , b)) * b;
}

void bfs(int start){

    visited[start] = true;
    num[start] = 1;
    den[start] = 1;

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i =0; i<material[current].size(); ++i) {
            auto info = material[current][i];
            int b = info.to;
            int left = info.p;
            int right = info.q;

            if(visited[b]) continue;

            num[b] = num[current] * right;
            den[b] = den[current] * left;

            long long great_div = findGcd((long long)num[b], (long long)den[b]);

            num[b] /= great_div;
            den[b] /= great_div; // 최대공약수로 나눠주리기
            visited[b] = true;
            q.push(b);
        }
    }
}

int main(){

    int N; // 재료의 개수
    cin >> N;

    material.assign(N , {});


    for(int i =0; i<N-1; ++i){
        int a , b , left , right;
        cin >> a >> b >> left >> right;
        material[a].push_back({b , left , right});
        material[b].push_back({a , right , left});
    }

    num.assign(N , 0);
    den.assign(N , 0);
    visited.assign(N , false);

    bfs(0);

    long long lcm = 1;

    // 모든 분모들의 최소공배수 찾기
    for(int i =0; i<N; ++i){
        lcm = findLcm(lcm , den[i]);
    }

    for(int i =0; i<N; ++i){
      long long  t =  lcm / den[i];
      num[i] = num[i] * t;
    }

    long long gcd = 1;
    for(int i = 0; i<N; ++i){
        gcd = findGcd(num[i] , gcd);
    }

    for(int i =0; i <N; ++i){
        num[i] /= gcd;
        cout << num[i] << " ";
    }

    return 0;
}