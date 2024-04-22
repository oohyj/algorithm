#include <iostream>
#include <deque>

using namespace std;

int main(){

    int n , a;
    string input;
    deque<int> deq;
    cin >> n;

    while(n--){
        cin >> input;
        if(input == "push_front"){
            cin >> a;
            deq.push_front(a);
        }
        else if(input == "push_back"){
            cin >> a;
            deq.push_back(a);
        }
        else if(input == "pop_front"){
            if(deq.empty()){
                cout << "-1" <<"\n";
            }
            else {
                cout << deq.front() <<"\n";
                deq.pop_front();
            }
        }
        else if(input == "pop_back"){
            if(deq.empty()){
                cout << "-1" <<"\n";
            }
            else {
                cout << deq.back() <<"\n";
                deq.pop_back();
            }
        } else if(input == "size"){
            cout << deq.size() <<"\n";
        }
        else if(input == "empty"){
            cout << deq.empty() <<"\n";
        }
        else if(input =="front") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.front() << "\n";
            }
        }
        else if(input == "back"){
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.back() << "\n";
            }
        }
    }
    return 0;
}
