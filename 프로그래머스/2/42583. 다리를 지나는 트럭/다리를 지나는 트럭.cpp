#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge; // 현재 다리 위에 있는 트럭
    int time = 0;
    int bridge_weight = 0;
    int index = 0;

    while(1){
        if(index == truck_weights.size()){
            time += bridge_length;
            break;
        }
        
        time++;
        
        if(bridge.size() == bridge_length){
            bridge_weight -= bridge.front();
            bridge.pop();
        }
        
        if(bridge_weight + truck_weights[index] <= weight){
            bridge_weight += truck_weights[index];
            bridge.push(truck_weights[index]);
            index++;
        }else {
            bridge.push(0);
        }
        
    }

  
    return time;
}