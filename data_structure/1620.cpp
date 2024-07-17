#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n , m;
    string input;
    cin>> n >> m;
    map<string , int> name;
    vector<string> num(n+1 , "");
    for(int i =1; i<=n; i++){
        cin >> input;
        name[input] = i;
        num[i] = input;
    }
    while(m--){
        cin >> input;
        if(isdigit(input[0])){
            cout << num[stoi(input)] << '\n';
        }
        else{
            cout << name[input] <<'\n';
        }
    }

    return 0;

}
