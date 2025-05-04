#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int n = routes.size();
    sort(routes.begin() , routes.end() , [](const vector<int>& a , const vector<int>& b){
        return a[1] < b[1];
    });
    
    int camera_loc = routes[0][1];
    answer +=1;
    for(int i =1; i<n; ++i){
        if(routes[i][0] > camera_loc){
            ++answer;
            camera_loc = routes[i][1];
        }
        else continue;
    }
    
    return answer;
}