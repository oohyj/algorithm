#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> buildings(n , {0 , 0});

    stack<int> st ; // y의 길이를 저장할 스택

    for (int i = 0; i < n; ++i) cin >> buildings[i].first >> buildings[i].second;
    int answer = 0;

    for(int i =0; i<n; ++i){
        int y = buildings[i].second;

        while(!st.empty() && st.top() > y){
            st.pop();
            answer++;
        }

        if(!st.empty() && st.top() == y) continue;

        if(y > 0) st.push(y);
    }

    answer += st.size();


    cout << answer << '\n';

    return 0;
}