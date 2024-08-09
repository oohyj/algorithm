#include <iostream>


using namespace std;
const int MAX_N = 8;

int n , m;
int sequence[MAX_N];
bool is_used[MAX_N+1];

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
        if(is_used[i]){
            continue;
        }

        sequence[count] = i;
        is_used[i] = true;

        backTracking(count+1);

        is_used[i] = false;
    }

}

int main(){

    cin >> n >> m;


    backTracking(0);

    return 0;
}