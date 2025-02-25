#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int n = schedules.size(); // 직원 수
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int goal = ((schedules[i]/100 + ((schedules[i]%100+10)/60))*100) + (schedules[i]%100+10)%60;
        
        cout <<"goal  : " << goal <<'\n';
        int temp = startday;
        for (int j = 0; j < 7; j++) {
            
            int current_day = (temp-1) % 7; 
            
            if (current_day < 5) { 
               if(timelogs[i][j] <=goal){
                   cnt++;
               }
            }
            
            temp++;

        }

        if (cnt == 5) answer++; 
    }
    
    return answer;
}