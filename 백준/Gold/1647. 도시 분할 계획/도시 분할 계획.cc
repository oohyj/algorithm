#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> depth;

int findParent(int x){
   if(parent[x] == -1) return x;
   return parent[x] = findParent(parent[x]);
}

void unionSets(int a , int b){
    a = findParent(a);
    b = findParent(b);

    if(a == b) return; //  부모 같으면 종료

    if(depth[a] < depth[b]){ // 깊이 기준으로 더 많은 쪽으로 붙이기
        parent[a] = b;
    }else{
        parent[b] = a;
        if(depth[a] == depth[b]) depth[a]++;
    }
}

int main(){

    int N , M;
    cin >> N >> M;

   vector<tuple<int , int, int>> expense(M);


   for(int i =0; i<M; ++i){
       int A , B , C;
       cin >> A >> B >> C;
       expense[i] = {A , B , C};
   }

   sort(expense.begin() , expense.end() ,[](const auto& a , const auto& b){
       return get<2>(a) < get<2>(b);
   });

   parent.assign(N+1 , -1);
   depth.assign(N+1  , 1); // 트리 깊이

   int answer = 0;
   int maxEdge = 0;
   int edgeUsed = 0;

   for(const auto& t : expense){
       int a = get<0>(t);
       int b = get<1>(t);
       int cost = get<2>(t);

       int pa = findParent(a);
       int pb = findParent(b);

       if(pa != pb){
           unionSets(a , b);
           answer += cost;
           maxEdge = max(maxEdge , cost);
           edgeUsed++;

           if(edgeUsed == N-1) break; // mst 완성
       }
   }

   cout << (answer - maxEdge) << '\n';


    return 0;
}