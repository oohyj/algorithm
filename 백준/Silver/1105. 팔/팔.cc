#include <iostream>

using namespace std;

int main(){
    string L , R;
    cin >> L >> R;
    int answer =0;

    if(L.size() != R.size()){
        answer =0;
    }
    else{
        string substr ="";
        for(int i =0; i<L.size(); i++){
            if(L[i] == R[i]){
                substr +=L[i];
            }
            else break;
        }

        for(int i =0; i<substr.size(); i++){
            if(substr[i] =='8'){
                answer++;
            }
        }
    }


    cout << answer <<'\n';

    return 0;

}
