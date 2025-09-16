#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main(){

    int N;
    cin >> N;

    vector<vector<int>> A(N , vector<int>(N));

    for(int i =0; i<N; ++i){
        for(int j = 0; j<N; ++j){
            cin >> A[i][j];
        }
    }
    
    vector<vector<int>> dist = A;

    for(int k = 0; k<N; ++k){
        for(int i =0; i<N; ++i){
            for(int j =0; j<N; ++j){
                if(dist[i][k] + dist[k][j] <dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i =0; i<N; ++i){
       for(int j =0; j<N; ++j){
           if(dist[i][j] < A[i][j]){
               cout << -1 << '\n';
               return 0;
           }
       }
    }

    vector<vector<bool>> redundant(N , vector<bool>(N ,false));
    for(int k =0; k<N; ++k){
        for(int i = 0; i<N; ++i){
            if(i == k) continue;
            for(int j =0; j<N; ++j){
                if(j ==k || i ==j) continue;
                if(A[i][j] == A[i][k] + A[k][j]){
                    redundant[i][j] = redundant[j][i] = true;
                }
            }
        }
    }

    long long sum = 0;
    for(int i =0; i<N; ++i){
        for(int j = i+1; j <N; ++j){
            if(!redundant[i][j]) sum += A[i][j];
        }
    }

   cout << sum << '\n';

    return 0;
}