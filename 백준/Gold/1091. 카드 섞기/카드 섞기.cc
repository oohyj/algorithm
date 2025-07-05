#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N ;
    cin >> N;

    vector<int> P(N);
    vector<int> S(N);
    vector<int> deck(N); // 현재 위치 저장할 deck
    vector<int> original(N); // 처음 상태 deck

    for(int i =0; i<N; ++i){
        cin >> P[i];
        deck[i] = i;
        original[i] = i;
    }

    for(int i =0; i<N; ++i){
        cin >> S[i];
    }
    int answer = 0;
    while(true){
      bool isValid = true;

      for(int i =0; i<N; ++i){
          if(i%3 != P[deck[i]]){
              isValid = false;
              break;
          }
      }

      if(isValid == true) break;

      vector<int> tempDeck(N);

      for(int i =0; i<N; ++i){
          tempDeck[S[i]] = deck[i];
      }

      deck = tempDeck;
      answer++;

      if(deck == original){
          answer = -1;
          break;
      }

    }


    cout << answer << '\n';

    return 0;
}