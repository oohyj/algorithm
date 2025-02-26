#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int changeNum(string str) {
    if (str == "code") return 0;
    else if (str == "date") return 1;
    else if (str == "maximum") return 2;
    else return 3; // remain의 경우
}

struct Compare {
    int index;  
    Compare(int idx) : index(idx) {}  

    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[index] < b[index]; 
    }
};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int ext_num = changeNum(ext);
    int sort_num = changeNum(sort_by);
 
    for (const auto& row : data) {
        if (row[ext_num] < val_ext) {
            answer.push_back(row);
        }
    }
    sort(answer.begin(), answer.end(), Compare(sort_num));
    
    return answer;
}