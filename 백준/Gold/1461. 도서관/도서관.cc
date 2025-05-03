#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

   int N , M;
   vector<int> pos ,  neg;
   cin >> N >> M;
   for(int i =0; i<N; ++i){
       int x;
       cin >> x;
       if(x > 0){
           pos.push_back(x);
       }
       else {
           neg.push_back(-x);
       }
   }

   vector<int> dist;

   sort(pos.rbegin() ,pos.rend());
   sort(neg.rbegin() , neg.rend());

   for(int i =0; i<pos.size(); i+=M){
       dist.push_back(pos[i]);
   }

   for(int i =0; i<neg.size(); i+=M){
       dist.push_back(neg[i]);
   }

   sort(dist.rbegin() , dist.rend());

   int answer = 0;

   for(int i =0; i<dist.size(); ++i){
       if(i == 0) answer += dist[i];
       else answer += 2* dist[i];
   }

   cout << answer << '\n';
    return 0;
}