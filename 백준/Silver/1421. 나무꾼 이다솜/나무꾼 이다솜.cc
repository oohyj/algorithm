#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, C, W;
    cin >> N >> C >> W;

    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    int max_length = *max_element(trees.begin(), trees.end());
    long long max_profit = 0;

    for (int L = 1; L <= max_length; L++) {
        long long current_profit = 0;

        for (int tree : trees) {
            if (tree < L) {
                continue;
            }

            int num_pieces = tree / L;
            int num_cuts = tree % L == 0 ? num_pieces - 1 : num_pieces;

            int profit_from_tree = (num_pieces * L * W) - (num_cuts * C);
            if (profit_from_tree > 0) {
                current_profit += profit_from_tree;
            }
        }

        max_profit = max(max_profit, current_profit);
    }

    cout << max_profit << '\n';
    return 0;
}