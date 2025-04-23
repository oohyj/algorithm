#include <iostream>
#include <vector>

using namespace std;

int parent[51];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionParty(int a , int b){
    a = find(a);
    b = find(b);
    if(a!=b) parent[b] = a;
}

int main(){

    int N , M;
    cin >> N >> M;

    for(int i =1; i<=N; ++i) parent[i] = i;

    int truthCount;
    cin >> truthCount;
    vector<int> truthPeople(truthCount);
    for(int i =0; i<truthCount; ++i){
        cin >> truthPeople[i];
    }

    vector<vector<int>> parties(M);

    for(int i =0; i<M; ++i){
        int count;
        cin >> count;
        parties[i].resize(count);
        for(int j =0; j<count; ++j){
            cin >> parties[i][j];
        }

        for(int j =1; j<count; ++j){
            unionParty(parties[i][0] , parties[i][j]);
        }
    }

    vector<int> truthRoots;
    for(int person : truthPeople){
        truthRoots.push_back(find(person));
    }

    int result = 0;

    for(auto& party : parties){
        bool canLie = true;
        for(int person : party ){
            for(int truth : truthRoots){
                if(find(person) == truth){
                    canLie = false;
                    break;
                }
            }
            if(!canLie) break;
        }
        if(canLie) result++;
    }

    cout << result << '\n';


    return 0;
}