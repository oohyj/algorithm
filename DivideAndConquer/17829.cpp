#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int boards[1025][1025];

int solve(int len , int r , int c){
    vector<int> v;
    if(len ==2){
        for(int i =r; i<r+2; i++){
            for(int j=c; j<c+2; j++){
                v.push_back(boards[i][j]);
            }
        }
        sort(v.begin() , v.end());
        return v[2];
      }
   else{
       v.push_back(solve(len/2 , r , c));
       v.push_back(solve(len/2 , r+len/2 ,c));
       v.push_back(solve(len/2 , r, c+len/2));
       v.push_back(solve(len/2 , r+len/2 , c+len/2));
       sort(v.begin() , v.end());
       return v[2];
   }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> boards[i][j];
        }
    }

    cout << solve(n , 0 , 0) << '\n';


    return 0;
}
