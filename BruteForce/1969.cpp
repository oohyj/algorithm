#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char> > dna(n, vector<char>(m)); // 2차원 벡터 초기화
    int count[4] = {}; // A, C, G, T의 빈도수를 저장하는 배열
    string result = "";
    int answer = 0;

    // 입력 받기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> dna[i][j];
        }
    }

    // 각 열을 순회
    for (int j = 0; j < m; ++j) {
        // count 배열 초기화
        count[0] = count[1] = count[2] = count[3] = 0;

        // 각 행을 순회하며 빈도수 계산
        for (int i = 0; i < n; ++i) {
            switch (dna[i][j]) {
                case 'A':
                    count[0]++;
                    break;
                case 'C':
                    count[1]++;
                    break;
                case 'G':
                    count[2]++;
                    break;
                case 'T':
                    count[3]++;
                    break;
            }
        }

        // 가장 빈도수가 높은 문자 찾기
        int max_index = 0;
        for (int i = 1; i < 4; ++i) {
            if (count[i] > count[max_index]) {
                max_index = i;
            }
        }

        // 결과 문자열에 추가
        result.push_back("ACGT"[max_index]);
    }

    // Hamming distance 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (result[j] != dna[i][j]) {
                answer++;
            }
        }
    }

    cout << result << '\n' << answer << endl;

    return 0;
}
