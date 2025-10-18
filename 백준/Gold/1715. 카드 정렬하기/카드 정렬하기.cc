#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;
    priority_queue<int , vector<int> , greater<int>> pq;

    for(int i =0; i<N; ++i){
        int x;
        cin >> x;
        pq.push(x);
    }

    long long answer = 0;

    while(pq.size()>1){
        int a= pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        int sum = a + b;
        pq.push(sum);
        answer += sum;
    }

    cout << answer << '\n';
    return 0;
}
