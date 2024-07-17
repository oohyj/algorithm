#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string input;
    int sum =0;
    map<string, int> trees;
    cout << fixed;
    cout.precision(4);

    while(getline(cin , input)){
        trees[input]++;
        sum++;
    }

    for(auto itr : trees){
        double a = (double)(itr.second)/sum*100;
        cout << itr.first << " " << a <<'\n';
    }

    return 0;
}

