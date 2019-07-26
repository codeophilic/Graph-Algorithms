#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mk make_pair

set<int> visited;
vector<vector<int>> edges(100010);
int low[100010];
int visiTime[100010];
int parent[100010];
int t = 0;
vector<pair<int, int>> ans;

bool compare(pair<int, int> i1, pair<int, int> i2) {
    if(i1.first == i2.first) return i1.second < i2.second;
    return i1.first < i2.first ; 
}

void allClear() {
    for(int i = 0;i<100010;i++) edges[i].clear();
    visited.clear();
    ans.clear();
}

void dfs(int sv) {
    visited.insert(sv);

    low[sv] = visiTime[sv] = t++;
    for(int i = 0;i<edges[sv].size();i++) {
        int adj = edges[sv][i];

        if(visited.find(adj) == visited.end()) {
            parent[adj] = sv;
            dfs(adj);

            low[sv] = min(low[sv], low[adj]);
            if(low[adj] > visiTime[sv]) {
                if(adj > sv) ans.pb(mk(sv, adj));
                else ans.pb(mk(adj, sv));
            }
        } else if(parent[sv] != adj) {
            low[sv] = min(low[sv], visiTime[adj]);
        }
    }
}

int main() {
    int t; cin >> t;
    for(int i = 1;i<=t;i++) {
        allClear();
        int n, m; cin >> n >> m;
        for(int i = 0;i<m;i++) {
            int f, s; cin >> f >> s;
            edges[f].pb(s);
            edges[s].pb(f);
        }

        for(int i = 1;i<=n;i++) {
            if(visited.find(i) == visited.end()) {
                dfs(i);
            }
        }
        sort(ans.begin(), ans.end(), compare);
        cout << "Caso #" << i << endl;
        if(ans.size() == 0) {
            cout << "Sin bloqueos" << endl;
            continue;
        }
        cout << ans.size() << endl;
        for(int i = 0;i<ans.size();i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}