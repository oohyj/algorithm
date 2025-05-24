#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string& s , char delim){
    vector<string> result;
    stringstream ss(s);
    string part;
    while(getline(ss , part , delim)){
        result.push_back(part);
    }
    return result;
}

int sumOfParts(const string& s){
    vector<string> nums = split(s , '+');
    int sum = 0;
    for(const string& num : nums){
        sum += stoi(num);
    }
    return sum;
}

int main(){
    string expr;
    cin >> expr;

    vector<string> parts = split(expr , '-');

    int result = sumOfParts(parts[0]);

    for(int i =1; i<parts.size(); ++i){
        result -= sumOfParts(parts[i]);
    }

    cout << result << '\n';

    return 0;
}
