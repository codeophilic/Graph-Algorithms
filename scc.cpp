#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair

set<set<int>*> components;

vector<vector<int>> edges(100010);
vector<vector<int>> edgesT(100010);
int n, m;

void dfs2(int sv, set<int> &visited, set<int> *component) {
    visited.insert(sv);
    component -> insert(sv);
    for(int i = 0;i<edgesT[sv].size();i++) {
        int adj = edgesT[sv][i];
        if(visited.find(adj) != visited.end()) continue;
        dfs2(adj, visited, component);
    }
}

void dfs1(int sv, set<int> &visited, stack<int> &s) {
    visited.insert(sv);
    for(int i = 0;i<edges[sv].size();i++) {
        int adj = edges[sv][i];
        if(visited.find(adj) != visited.end()) continue;
        dfs1(adj, visited, s);
    }
    s.push(sv);
}

void SCC() {
    set<int> visited;
    stack<int> s;
    for(int i= 1;i<=n;i++) {
        if(visited.find(i) != visited.end()) continue;
        dfs1(i, visited, s);
    }
    visited.clear();
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        if(visited.find(top) != visited.end()) continue;
        set<int> *component = new set<int>();
        dfs2(top, visited, component);
        components.insert(component);
    }

    for(auto it = components.begin(); it != components.end(); it++) {
        auto k = (*it);
        for(auto j = (*k).begin(); j != (*k).end();j++) {
            cout << (*j) << " ";
        }
        cout << endl;
    }
}

int main() {

    cin >> n >> m;
    for(int i = 0;i<m;i++) {
        int f, s;
        cin >>f >> s;
        edges[f].pb(s);
        edgesT[s].pb(f);
    }
    SCC();
    return 0;
}