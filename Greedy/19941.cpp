#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n , k , answer =0;
    cin >> n >> k;

    vector<char> hamburger;
    hamburger.assign(n , 0);
    for(int i =0; i<n; i++){
        cin >> hamburger[i];
    }

    for(int i =0; i<n; i++){
        if(hamburger[i] == 'P'){
            for(int j = i-k; j < i+k+1; j++){
                if (j >= 0 && j < n && hamburger[j] == 'H'){
                    answer++;
                    hamburger[j] = 'T';
                    break;
                }
            }
        }
    }

    cout << answer <<'\n';

    return 0;
}
