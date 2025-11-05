#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    deque<int> dq;
    for (int i = 1; i <= N; ++i) dq.push_back(i);

    long long ops = 0;
    for (int i = 0; i < M; ++i) {
        int target; 
        cin >> target;

    
        int idx = 0;
        for (; idx < (int)dq.size(); ++idx) if (dq[idx] == target) break;

      
        int leftMoves = idx;                   
        int rightMoves = (int)dq.size() - idx; 

        if (leftMoves <= rightMoves) {

            ops += leftMoves;
            while (leftMoves--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
           
            ops += rightMoves;
            while (rightMoves--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        dq.pop_front(); 
    }

    cout << ops << "\n";
    return 0;
}