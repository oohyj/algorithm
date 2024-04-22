#include <iostream>
#include <stack>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n ;
    cin >> n;

    string input;
    int a;
    stack <int> s;

    while(n--){
        cin >> input;
        if(input == "push"){
            cin >> a;
            s.push(a);
        }
        else if( input == "pop"){
            if(s.empty()){
                cout << "-1" <<"\n";
            }
            else{
                cout << s.top()<<"\n";
                s.pop();
            }
        }
        else if(input == "size"){
            cout << s.size() <<"\n";
        }
        else if(input == "empty"){
            if(s.empty()){ // 비어있으면
                cout << "1" << "\n";
            }
            else cout << "0" <<"\n";
        }
        else if(input == "top"){
            if(s.empty()){
                cout << "-1" <<"\n";
            }
            else {
                cout << s.top()<<"\n";
            }
        }
    }
    return 0;
}