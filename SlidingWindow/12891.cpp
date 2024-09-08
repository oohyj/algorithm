#include <iostream>
#include <vector>
#include <map>

using namespace std;

int s , p , a , c, g, t , cnt =0 ;
vector<char> dna;
map<char , int> stand;
map<char , int> comp;

void isCorrect(){
    if(comp['A'] >= stand['A'] && comp['C'] >= stand['C'] && comp['G'] >= stand['G'] && comp['T'] >= stand['T']){
        cnt++;
    }
}

int main(){

    cin >> s >> p;
    dna.assign(s , ' ');

    for(int i =0; i<s; i++){
        cin >> dna[i];
    }

    cin >> a >> c >> g >> t;
    stand['A'] = a;
    stand['C'] = c;
    stand['G'] = g;
    stand['T'] = t;

    for(int i =0; i<p; i++){
        switch (dna[i]) {
            case 'A' :
                comp['A']++;
                break;
            case 'C' :
                comp['C']++;
                break;
            case 'G' :
                comp['G']++;
                break;
            case 'T' :
                comp['T']++;
                break;
        }
    }

    isCorrect();

    for(int i = p; i<dna.size(); i++){
        comp[dna[i-p]]--;
        comp[dna[i]]++;
        isCorrect();
    }

    cout << cnt << '\n';

    return 0;
}
