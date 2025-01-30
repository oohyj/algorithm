#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool isSame(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

void flip(vector<vector<int> >& A, int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            A[i][j] = 1 - A[i][j];
        }
    }
}

int main() {
    cin >> N >> M;
    vector<vector<int> > A(N, vector<int>(M));
    vector<vector<int> > B(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            A[i][j] = c - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            B[i][j] = c - '0';
        }
    }
    
    if (N < 3 || M < 3) {
        cout << (isSame(A, B) ? 0 : -1) << '\n';
        return 0;
    }

    int cnt = 0;
    
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (A[i][j] != B[i][j]) {
                flip(A, i, j);
                cnt++;
            }
        }
    }
    
    if (isSame(A, B)) {
        cout << cnt << '\n';
    } else {
        cout << "-1\n";  // 변환이 불가능한 경우
    }

    return 0;
}