#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void generateCombinations(int n, vector<vector<int>>& combinations) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) nums.push_back(i);

    vector<int> selected(5, 1);
    selected.resize(n, 0);

    do {
        vector<int> comb;
        for (int i = 0; i < n; i++) {
            if (selected[i]) comb.push_back(nums[i]);
        }
        combinations.push_back(comb);
    } while (prev_permutation(selected.begin(), selected.end()));
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<vector<int>> candidates;
    generateCombinations(n, candidates);

    int answer = 0;

    for (const auto& secret : candidates) {
        bool isValid = true;
        for (size_t k = 0; k < q.size(); k++) {
            set<int> secretSet(secret.begin(), secret.end());
            set<int> querySet(q[k].begin(), q[k].end());

            int intersectionSize = 0;
            for (int num : querySet) {
                if (secretSet.count(num)) {
                    intersectionSize++;
                }
            }

            if (intersectionSize != ans[k]) {
                isValid = false;
                break;
            }
        }
        if (isValid) answer++;
    }

    return answer;
}
