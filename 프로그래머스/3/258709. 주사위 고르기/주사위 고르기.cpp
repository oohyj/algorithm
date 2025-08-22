#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

// selectedDice가 가리키는 주사위들로 만들 수 있는 "모든 합"을 cases에 담는다.
void buildAllSums(const vector<vector<int>>& dice,
                  const vector<int>& selectedDice,
                  int diceIndex,
                  int currentSum,
                  vector<int>& cases) {
    if (diceIndex == (int)selectedDice.size()) {
        cases.push_back(currentSum);
        return;
    }
    int d = selectedDice[diceIndex];            // 이번에 사용할 주사위 인덱스
    for (int face : dice[d]) {                  // 6면 각각에 대해
        buildAllSums(dice, selectedDice, diceIndex + 1,
                     currentSum + face, cases); // 누적 합을 넘겨 재귀
    }
}

// vec에서 target 미만(< target) 원소의 개수를 반환 (lower_bound)
int countLessThan(const vector<int>& vec, int target) {
    int left = 0, right = (int)vec.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid] < target) {
            left = mid + 1;     // 더 오른쪽으로
        } else {
            right = mid - 1;    // 더 왼쪽으로
        }
    }
    return left; // 마지막에 left가 "< target 개수"가 됨
}

// 백트래킹으로 A의 조합을 모두 생성하고, 각 조합의 "A 승 수"를 계산해 최대를 갱신
void backtrackChooseA(const vector<vector<int>>& dice,
                      int start,
                      vector<int>& aDice,            // 현재까지 A가 고른 주사위(0-based)
                      vector<int>& bestAnswer,       // 최대 승 수일 때의 A 조합(0-based)
                      ll& maxWins) {                 // 최대 승 수
    int n = (int)dice.size();
    int k = n / 2;

    // A가 k개를 다 골랐으면, 보완 집합(B) 구성 후 승 수 계산
    if ((int)aDice.size() == k) {
        // B 집합 만들기: A로 고른 인덱스를 boolean으로 표시 후 나머지 모음
        vector<int> bDice;
        bDice.reserve(k);
        vector<char> isA(n, 0);
        for (int idx : aDice) isA[idx] = 1;
        for (int i = 0; i < n; ++i) if (!isA[i]) bDice.push_back(i);

        // A/B의 모든 합 구하기
        vector<int> aCases, bCases;
        aCases.reserve(1); bCases.reserve(1); // 미리 잡을 필요는 없지만 형식상
        buildAllSums(dice, aDice, 0, 0, aCases);
        buildAllSums(dice, bDice, 0, 0, bCases);

        // 정렬 후, A의 각 합 s에 대해 "B에서 s보다 작은 개수"를 더해 승 수 계산
        sort(aCases.begin(), aCases.end());
        sort(bCases.begin(), bCases.end());

        ll aWins = 0;
        for (int s : aCases) {
            aWins += countLessThan(bCases, s);
        }

        // 최대 갱신
        if (aWins > maxWins) {
            maxWins = aWins;
            bestAnswer = aDice;
        }
        return;
    }

    // 조합 생성: start부터 다음 인덱스들을 하나씩 선택
    for (int i = start; i < n; ++i) {
        aDice.push_back(i);
        backtrackChooseA(dice, i + 1, aDice, bestAnswer, maxWins);
        aDice.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int n = (int)dice.size();

    vector<int> bestAnswer;     // 0-based
    vector<int> aDice;          // 현재 선택 경로
    ll maxWins = -1;            // 승 수 최대값

    backtrackChooseA(dice, 0, aDice, bestAnswer, maxWins);

    // 1-based로 변환 후 오름차순 정렬해 반환
    for (int& x : bestAnswer) ++x;
    sort(bestAnswer.begin(), bestAnswer.end());
    return bestAnswer;
}