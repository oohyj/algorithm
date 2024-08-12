#include <iostream>

using namespace std;
const int MAX_N = 8;

int n , m;
int sequence[MAX_N];

void printSequence(){
    for(int i =0; i<m; i++){
        cout << sequence[i] <<" ";
    }
    cout <<'\n';
}

void backTracking(int count){
    if(count == m){
        printSequence();
        return;
    }

    for(int i=1; i<=n; i++){
        sequence[count] = i;
        backTracking(count+1);

    }

}

int main(){

    cin >> n >> m;


    backTracking(0);

    return 0;
}