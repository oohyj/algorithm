#include <iostream>
#include <vector>

using namespace std;
int alpha[26] = {3, 2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};


int main(){

    string input;
    cin >> input;

    vector<int> numbers;
    numbers.assign(input.size() , 0);

    for(int i =0; i<input.size(); i++){
      numbers[i] = alpha[input[i]-65];
    }
     int sum =0;

    for(int i =0; i<numbers.size(); i++){
            if(sum > 10){
                sum %=10;
            }
            sum += numbers[i];
    }

    if((sum  % 2 )==0){
        cout << "You're the winner?" <<'\n';
    }
    else {
        cout << "I'm a winner!" <<'\n';
    }


    return 0;
}