#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
vector<int> sequence;
vector<int> result;
vector<bool> check;


void backTrack(int cnt) {
    if(cnt == m){
        for(int i =0; i<m; i++){
            cout << result[i] <<" ";
        }
        cout << "\n";
        return;
    }

    int last =0;
    for(int i =0; i<n; i++){
        if(check[i] == false && sequence[i] != last){
            result[cnt] = sequence[i];
            last = result[cnt];
            check[i] = true;
            backTrack(cnt++);
            check[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    sequence.assign(n, 0);
    result.assign(m, 0);
    check.assign(n,false);

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    sort(sequence.begin(), sequence.end());

    backTrack(0);

    return 0;
}