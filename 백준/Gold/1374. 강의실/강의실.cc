#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> lectures(N);

    for (int i = 0; i < N; ++i) {
        int num, start, end;
        cin >> num >> start >> end;
        lectures[i] = {start, end};
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(lectures[0].second); 

    for (int i = 1; i < N; ++i) {
        if (lectures[i].first >= pq.top()) {
            pq.pop(); 
        }
        pq.push(lectures[i].second); 
    }

    cout << pq.size() << '\n';

    return 0;
}