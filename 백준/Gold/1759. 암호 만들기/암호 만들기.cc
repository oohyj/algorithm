#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int L , C;
vector<char> letters;
vector<char> result;
string vowels = "aeiou";

void dfs(int idx , int depth){
    if(depth == L){
        int vowel_cnt = 0 , consonant_cnt = 0;
        for(char ch : result){
            if(vowels.find(ch) != string::npos){
                vowel_cnt++;
            }
            else{
                consonant_cnt++;
            }
        }
        if(vowel_cnt >= 1 && consonant_cnt >=2){
            for(char ch : result) cout << ch;
            cout << '\n';
        }
        return;
    }

    for(int i = idx; i<C; ++i){
       result.push_back(letters[i]);
        dfs(i+1 , depth+1);
        result.pop_back();
    }
   
}

int main(){

    cin >> L >> C;
    letters.resize(C);
    for(int i =0; i<C; ++i){
        cin >> letters[i];
    }

    sort(letters.begin() , letters.end());
    dfs(0 , 0);

    return 0;
}
