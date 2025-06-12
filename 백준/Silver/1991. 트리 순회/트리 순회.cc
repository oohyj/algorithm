#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char , pair<char , char>> tree;

void preorder(char node){
    if(node =='.') return;
    cout << node;
    preorder(tree[node].first);
    preorder(tree[node].second);
}

void inorder(char node){
    if(node =='.') return;
    inorder(tree[node].first);
    cout << node;
    inorder(tree[node].second);
}

void postorder(char node){
    if(node =='.') return;
    postorder(tree[node].first);
    postorder(tree[node].second);
    cout << node;
}

int main(){

    int N;

    cin >> N;

    for(int i =0; i<N; ++i){
        char parent , left , right;
        cin >> parent >> left >> right;
        tree[parent] = {left , right};
    }

   
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}