#include <iostream>
#include <stack>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    string input;
    cin >> n;

    while(n--){
      stack <char> s;
      cin >> input;
      for(int i =0; i<input.size(); i++){
         if(s.empty()){
             s.push(input[i]);
         }
         else{
             if(s.top() == '(' && input[i] == ')'){
                 s.pop();
             }
             else{
                 s.push(input[i]);
             }
         }
      }

      if(s.empty()){
          cout << "YES" <<"\n";
      }
      else{
          cout << "NO" <<"\n";
      }
    }

    return 0;
}
