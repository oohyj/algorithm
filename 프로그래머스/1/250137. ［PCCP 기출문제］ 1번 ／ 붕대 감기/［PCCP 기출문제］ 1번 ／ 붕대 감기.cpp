#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int limit = health; // 최대 체력 저장
    int sequence = 0;   // 연속 성공 횟수
    int current_time = 1; // 현재 시간
    queue<pair<int, int>> info;

    for (const auto &attack : attacks) {
        info.push({attack[0], attack[1]});
    }

    while (!info.empty() || current_time <= attacks.back()[0]) {
        if (!info.empty() && info.front().first == current_time) {
            health -= info.front().second; 
            sequence = 0; 
            info.pop();
        } else {
            sequence++;
            if (sequence == bandage[0]) { 
                health += bandage[2];   
                sequence = 0;
            }
            health = min(health + bandage[1], limit); 
        }

        if (health <= 0) {
            return -1;
        }

        current_time++;
    }

    return health; 
}