#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

static vector<int> allSums(const vector<vector<int>>& dice, const vector<int>& indices) {
    vector<int> sums = {0};
    for (int idx : indices) {
        vector<int> next;
        next.reserve(sums.size() * 6);
        for (int base : sums) {
            for (int face : dice[idx]) {
                next.push_back(base + face);
            }
        }
        sums.swap(next);
    }
    sort(sums.begin(), sums.end());
    return sums;
}

static tuple<long long,long long,long long> countWinDrawLose(const vector<int>& a, const vector<int>& b) {
    ll win = 0, draw = 0;
    
    for (int s : a) {
        auto itL = lower_bound(b.begin(), b.end(), s);   
        auto itU = upper_bound(b.begin(), b.end(), s);      
        win  += distance(b.begin(), itL);
        draw += distance(itL, itU);
    }
    ll total = (ll)a.size() * (ll)b.size();
    ll lose  = total - win - draw;
    return {win, draw, lose};
}


vector<int> solution(vector<vector<int>> dice) {
    int n = (int)dice.size();
    int k = n / 2;

    
    vector<int> allIdx(n);
    iota(allIdx.begin(), allIdx.end(), 0);

    vector<int> bestPick;
    long double bestScore = -1.0L;

  
    vector<int> bit(n, 0);
    fill(bit.begin(), bit.begin()+k, 1);
    sort(bit.begin(), bit.end(), greater<int>()); 
    do {
        vector<int> pickA, pickB;
        pickA.reserve(k); pickB.reserve(k);
        for (int i = 0; i < n; ++i) {
            if (bit[i]) pickA.push_back(i);
            else        pickB.push_back(i);
        }

        // A/B의 모든 합 벡터
        vector<int> sumsA = allSums(dice, pickA);
        vector<int> sumsB = allSums(dice, pickB);

        auto [win, draw, lose] = countWinDrawLose(sumsA, sumsB);
        long double score = (long double)win / (long double)(win + draw + lose);

        if (score > bestScore) {
            bestScore = score;
            bestPick = pickA;
        }
    } while (prev_permutation(bit.begin(), bit.end()));

 
    for (int& x : bestPick) x += 1;
    sort(bestPick.begin(), bestPick.end());
    return bestPick;
}