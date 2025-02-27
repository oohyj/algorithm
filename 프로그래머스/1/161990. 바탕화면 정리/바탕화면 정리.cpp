#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int n = wallpaper.size();
    int m = wallpaper[0].size();
    vector<vector<char>> wall(wallpaper.size(), vector<char>(wallpaper[0].size()));
    for(int i =0;i< n; i++){
        for(int j=0; j<m; j++){
            wall[i][j] = wallpaper[i][j];
        }
    }
    int min_x = m , min_y=n , max_x =0, max_y=0;
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(wall[i][j] == '#'){
                min_x = min(min_x , j);
                min_y = min(min_y , i);
                max_x = max(max_x , j+1);
                max_y = max(max_y , i+1);
            }
        }
    }
    
    answer.push_back(min_y);
    answer.push_back(min_x);
    answer.push_back(max_y);
    answer.push_back(max_x);
    
    return answer;
}