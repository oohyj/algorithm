#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int count = 0;
    int i = 0;
    
    while (i < s.size()) {
        char x = s[i];
        int countX = 0, countOthers = 0;
        
        while (i < s.size()) {
            if (s[i] == x) countX++;
            else countOthers++;
            
            i++;
            
            if (countX == countOthers) break;
        }
        count++; 
    }
    
    return count;
}