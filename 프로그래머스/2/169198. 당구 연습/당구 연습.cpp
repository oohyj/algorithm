#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(auto& ball : balls){
        int minDist = 1e9;
        int targetX = ball[0];
        int targetY = ball[1];
        
        vector<pair<int, int>> mirrors;
        
        mirrors.push_back({-targetX , targetY});
        mirrors.push_back({2*m-targetX , targetY});
        mirrors.push_back({targetX , -targetY});
        mirrors.push_back({targetX , 2*n-targetY});
        
        for(auto [mx , my] : mirrors){
            int dx = startX - mx;
            int dy = startY - my;
            
            if(startX == targetX){
                if((startY > targetY && my < targetY)||(startY < targetY && my > targetY)) continue;
            }
            if(startY == targetY){
                if((startX > targetX && mx < targetX)||(startX < targetX && mx > targetX)) continue;
            }
            int dist = dx*dx + dy*dy;
            minDist = min(minDist , dist);
        }
        
        answer.push_back(minDist);
        
    }
    
    return answer;
}