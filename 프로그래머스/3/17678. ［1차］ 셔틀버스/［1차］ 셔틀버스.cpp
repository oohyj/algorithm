#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector<int> convert_t;
vector<bool> visited;
// 분으로 시간 변환
int toMinute(string time){
    int result = 0;
    int temp_hour = stoi(time.substr(0 , 2));
    int temp_min = stoi(time.substr(3 , 2));
    result  = temp_hour * 60 + temp_min;
    return result;
}

string toHHMM(int x){
    if(x<0) x=0;
    int h = x/60  , m = x%60;
    
    stringstream ss;
    ss << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m;
    return ss.str();
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int k = timetable.size();
    convert_t.assign(k , 0);
    for(int i =0; i<k; ++i){
      convert_t[i] = toMinute(timetable[i]);
    }
    sort(convert_t.begin() , convert_t.end()); //시간을 오름차순으로 정렬
    int bus = toMinute("09:00");
    int idx = 0;
    int lastBoarded = -1;
    
    for(int trip =1; trip <= n; ++trip){
        lastBoarded = -1;
        int cap = m;
        while(idx < convert_t.size() && convert_t[idx] <=  bus && cap > 0){
            lastBoarded = convert_t[idx];
            --cap;
            ++idx;
        }
        
        if(trip == n){
            if(cap > 0){
                return toHHMM(bus);
            }else{
                return toHHMM(lastBoarded -1);
            }
        }
        bus += t;
    }
    
    return answer;
}