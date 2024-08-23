#include<iostream>

using namespace std;
int n , r , c , answer = 0;


void dnc(int x , int y , int t){
    if(x==r && y == c){
        cout << answer;
        return;
    }
    else if( r >= x && r < x+t && c >=y && c < y+t){
        dnc(x , y , t/2);
        dnc(x , y+t/2 , t/2);
        dnc(x+t/2 , y , t/2);
        dnc(x+t/2 , y+t/2 , t/2);
    }
    else{
        answer += t*t;
    }

}

int main(){
    cin >> n >> r >> c;
    int t = 1<<n;

    dnc(0,0,t);
}
