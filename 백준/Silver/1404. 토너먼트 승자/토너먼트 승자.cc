#include <bits/stdc++.h>
using namespace std;

int main() {
    
    double p[8][8] = {0};

    
    for (int i = 0; i < 7; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            int x;            // 0..100 (퍼센트)
            if (!(cin >> x)) return 0;
            p[i][j] = x / 100.0;
            p[j][i] = 1.0 - p[i][j];
        }
    }

    vector<double> dp0(8, 1.0), dp1(8, 0.0), dp2(8, 0.0), dp3(8, 0.0);

    auto transition = [&](const vector<double>& cur, vector<double>& nxt, int roundIdx) {
        
        int blockSize = 1 << (roundIdx + 1); // 2, 4, 8
        for (int i = 0; i < 8; ++i) {
            int blockStart = (i / blockSize) * blockSize;
            int mid = blockStart + blockSize / 2;
         
            int oppL, oppR;
            if (i < mid) { 
                oppL = mid;
                oppR = blockStart + blockSize;
            } else {     
                oppL = blockStart;
                oppR = mid;
            }

            double sumMeet = 0.0;
            for (int j = oppL; j < oppR; ++j) {
                sumMeet += cur[j] * p[i][j];
            }
            nxt[i] = cur[i] * sumMeet;
        }
    };

    transition(dp0, dp1, 0); 
    transition(dp1, dp2, 1); 
    transition(dp2, dp3, 2);

    cout.setf(std::ios::fixed);
    cout << setprecision(10);
    for (int i = 0; i < 8; ++i) {
        if (i) cout << ' ';
        cout << dp3[i];
    }
    cout << '\n';
    return 0;
}