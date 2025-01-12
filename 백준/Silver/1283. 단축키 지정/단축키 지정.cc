#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    int N;
    cin >> N;
    cin.ignore();

    vector<string> menu(N);
    unordered_set<char> used_shortcuts;

    for(int i =0; i<N;i++){
        getline(cin , menu[i]);
    }

    for(string& option : menu){
        istringstream iss(option);
        string word;
        bool shortcut_assigned = false;

        // 단어의 첫 글자로 단축키 찾기
        while (iss >> word) {
            char first_letter = tolower(word[0]);
            if (used_shortcuts.find(first_letter) == used_shortcuts.end()) {
                // 단축키가 아직 아닌 경우 
                used_shortcuts.insert(first_letter);
                size_t pos = option.find(word); 
                option.insert(pos, "[");
                option.insert(pos + 2, "]");
                shortcut_assigned = true;
                break;
            }
        }

        
        if (!shortcut_assigned) {
            for (size_t j = 0; j < option.size(); j++) {
                if (option[j] != ' ' && used_shortcuts.find(tolower(option[j])) == used_shortcuts.end()) {
                    used_shortcuts.insert(tolower(option[j]));
                    option.insert(j, "[");
                    option.insert(j + 2, "]");
                    break;
                }
            }
        }
        
        cout << option << '\n';
    }

    return 0;
}