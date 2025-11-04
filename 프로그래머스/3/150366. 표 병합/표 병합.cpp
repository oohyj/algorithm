#include <bits/stdc++.h>

using namespace std;

const int N = 50;

vector<vector<string>> cells(N, vector<string>(N, ""));
vector<int> parent(N * N), rnk(N * N, 0);

inline int idx(int r, int c) { return (r - 1) * N + (c - 1); }
inline int rowOf(int id) { return id / N; }
inline int colOf(int id) { return id % N; }

int findParent(int x) {
    return parent[x] == x ? x : parent[x] = findParent(parent[x]);
}

void uniteIds(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
}

inline string& groupValueRef(int id) {
    int r = findParent(id);
    return cells[rowOf(r)][colOf(r)];
}

void updateCell(int r, int c, const string& value) {
    int id = idx(r, c);
    groupValueRef(id) = value;
}

void updateAll(const string& value1, const string& value2) {
    if (value1 == value2) return;
    for (int id = 0; id < N * N; ++id) {
        if (parent[id] == id) {
            string& v = cells[rowOf(id)][colOf(id)];
            if (v == value1) v = value2;
        }
    }
}

void mergeCells(int r1, int c1, int r2, int c2) {
    int id1 = idx(r1, c1);
    int id2 = idx(r2, c2);
    int a = findParent(id1), b = findParent(id2);
    if (a == b) return;

    string va = cells[rowOf(a)][colOf(a)];
    string vb = cells[rowOf(b)][colOf(b)];

    uniteIds(a, b);
    int root = findParent(a);

    string keep;
    if (!va.empty() && !vb.empty()) keep = va;
    else if (!va.empty()) keep = va;
    else keep = vb;

    cells[rowOf(root)][colOf(root)] = keep;
    if (root != a) cells[rowOf(a)][colOf(a)] = "";
    if (root != b) cells[rowOf(b)][colOf(b)] = "";
}

void unmergeCells(int r, int c) {
    int id = idx(r, c);
    int root = findParent(id);
    string keep = cells[rowOf(root)][colOf(root)];

    vector<int> members;
    for (int i = 0; i < N * N; ++i)
        if (findParent(i) == root)
            members.push_back(i);

    for (int m : members) {
        parent[m] = m;
        cells[rowOf(m)][colOf(m)] = "";
    }

    cells[rowOf(id)][colOf(id)] = keep;
}

vector<string> solution(vector<string> commands) {
    for (int i = 0; i < N * N; ++i) {
        parent[i] = i;
        rnk[i] = 0;
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cells[i][j] = "";

    vector<string> answer;

    for (const string& command : commands) {
        stringstream ss(command);
        vector<string> tok;
        string t;
        while (ss >> t) tok.push_back(t);

        const string& op = tok[0];

        if (op == "UPDATE") {
            if (tok.size() == 4) {
                int r = stoi(tok[1]);
                int c = stoi(tok[2]);
                updateCell(r, c, tok[3]);
            } else {
                updateAll(tok[1], tok[2]);
            }
        }
        else if (op == "MERGE") {
            int r1 = stoi(tok[1]);
            int c1 = stoi(tok[2]);
            int r2 = stoi(tok[3]);
            int c2 = stoi(tok[4]);
            mergeCells(r1, c1, r2, c2);
        }
        else if (op == "UNMERGE") {
            int r = stoi(tok[1]);
            int c = stoi(tok[2]);
            unmergeCells(r, c);
        }
        else if (op == "PRINT") {
            int r = stoi(tok[1]);
            int c = stoi(tok[2]);
            string v = groupValueRef(idx(r, c));
            answer.push_back(v.empty() ? "EMPTY" : v);
        }
    }

    return answer;
}