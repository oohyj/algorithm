#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

   int t; // 테스트케이스 수
   int n , m; // n: 문서의 개수 , M: 내가 궁금한 문서가 지금 있는 위치
   cin >> t;

   for(int i =0; i<t; i++){
       queue < pair <int ,int> > q;
       vector <int> v;

       int count =0;
       cin >> n >> m;

       for(int j =0;j < n; j++){ //큐에 중요도 넣기
           int a;
           cin >> a;
           v.push_back(a);
           if(j == m){
               q.push(make_pair(a,1));
           }
           else{
               q.push(make_pair(a,0));
           }
       }

       sort(v.begin() , v.end()); // 중요도 오름차순

       while(1){
           if(v.back() == q.front().first){ // 현재 있는 중요도 중에 가장 크고 그게 큐의 가장 앞에 있으면
               if(q.front().second == 1){ //그리고 내가 찾는 문서면
                   count++;
                   break;
               }
               else{
                   count++;
                   q.pop();
                   v.pop_back();
               }
           }
           else{
               q.push(make_pair(q.front().first , q.front().second));
               q.pop();
           }
       }
       cout << count <<"\n";
   }
}
