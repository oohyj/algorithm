#include <string>
#include <vector>

using namespace std;

int toSec(string time) {
    int minute = stoi(time.substr(0, 2));
    int second = stoi(time.substr(3, 2));
    return minute * 60 + second;
}

string toTime(int totalSec) {
    int minute = totalSec / 60;
    int second = totalSec % 60;
    string mm = minute < 10 ? "0" + to_string(minute) : to_string(minute);
    string ss = second < 10 ? "0" + to_string(second) : to_string(second);
    return mm + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int now = toSec(pos);
    int videoLen = toSec(video_len);
    int opStart = toSec(op_start);
    int opEnd = toSec(op_end);


    if (opStart <= now && now <= opEnd) {
        now = opEnd;
    }

    for (auto& command : commands) {
        if (command == "next") {
            now += 10;
            if (now > videoLen) now = videoLen;
        } else { // prev
            now -= 10;
            if (now < 0) now = 0;
        }

        if (opStart <= now && now <= opEnd) {
            now = opEnd;
        }
    }

    return toTime(now);
}