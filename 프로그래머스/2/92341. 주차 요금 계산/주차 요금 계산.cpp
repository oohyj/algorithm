#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> totalTime; // 차량별 누적 주차 시간
    map<int, int> inTime;    // 차량별 마지막 입차 시간

    int basicMin = fees[0], basicFee = fees[1];
    int perMin = fees[2], perFee = fees[3]; 

    for (string record : records) {
        stringstream ss(record);
        string timeStr, carStr, status;
        ss >> timeStr >> carStr >> status;

        int hour = stoi(timeStr.substr(0, 2));
        int minute = stoi(timeStr.substr(3, 2));
        int time = hour * 60 + minute;

        int car = stoi(carStr);

        if (status == "IN") {
            inTime[car] = time;
        } else {
            int parked = time - inTime[car];
            totalTime[car] += parked;
            inTime.erase(car);  
        }
    }

  
    for (auto [car, in] : inTime) {
        int parked = (23 * 60 + 59) - in;
        totalTime[car] += parked;
    }

    for (auto [car, t] : totalTime) {
        int fee = basicFee;
        if (t > basicMin) {
            fee += ceil((t - basicMin) / (double)perMin) * perFee;
        }
        answer.push_back(fee);
    }

    return answer;
}