#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parents; // 부모 여부
vector<int> ranks; // 트리 깊이

int findParent(int x ){
    if(parents[x] == -1) return x;
    return parents[x] = findParent(parents[x]);
}

void unionSets(int a , int b){
    a = findParent(a);
    b = findParent(b);

    if(a==b) return; // 부모가 같으면 종료

    if(ranks[a] < ranks[b]){
        parents[a] = b;
    }else{
        parents[b] = a;
        if(ranks[a] == ranks[b]) ranks[a]++;
    }
}

int main(){
int N , M;
    cin >> N >> M;
    vector<tuple<int , int, int>> edges;
    for(int i =0; i<M; ++i){
        int a , b , c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});// 비용 , a 컴퓨터 , b 컴퓨터
    }

    sort(edges.begin() , edges.end());
    parents.assign(N+1 , -1);
    ranks.assign(N+1 , 1);

    int answer = 0; // 필요한 최소 비용
    int edgeUsed = 0; // 현재 연결한 노드 개수

    for(const auto& edge : edges){
        int cost = get<0>(edge);
        int node1 = get<1>(edge);
        int node2 = get<2>(edge);

        int pnode1 = findParent(node1);
        int pnode2 = findParent(node2);

        if(pnode1 != pnode2){
            unionSets(pnode1 , pnode2);
            answer += cost;
            edgeUsed++;

            if(edgeUsed == N-1) break;
        }
    }

    cout << answer << '\n';
    return 0;
}