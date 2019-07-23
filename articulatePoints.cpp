#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<vector<int>> edges(100010);
set<int> visited;
set<int> artiPoint;
map<int, int> lowTime;
map<int, int> visiTime;
map<int, int> parent;
int t = 0;

void clearAll() {
    for(int i = 0;i<=10000;i++) edges[i].clear();
    visited.clear();
    artiPoint.clear();
    lowTime.clear();
    visiTime.clear();
    parent.clear();
    t = 0;
}

void dfs(int sv) {
    int childCount = 0;
    visited.insert(sv);
    lowTime[sv] = t;
    visiTime[sv] = t;
    bool isArti = false;
    t++;
    for(int i = 0;i<edges[sv].size();i++) {
        
        int adj = edges[sv][i];
        if(parent[sv] == adj) continue;
        if(visited.find(adj) == visited.end()) {
            // cout << adj << " " << sv << endl;
            parent[adj] = sv;
            childCount++;
            dfs(adj);

            if(visiTime[sv] <= lowTime[adj]) {
                isArti = true;
            } else {
                lowTime[sv] = min(lowTime[sv], lowTime[adj]);
            }
        } else {
            lowTime[sv] = min(lowTime[sv], visiTime[adj]);
        }
    }
    
    if((parent[sv] == 0 && childCount >= 2) ||
        parent[sv] != 0 && isArti) {
            artiPoint.insert(sv);
    } 
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    while(n != 0 && m!= 0) {
        clearAll();
        for(int i = 0;i<m;i++) {
            int f, s; cin >> f >> s;
            edges[f].pb(s);
            edges[s].pb(f);
        }

        dfs(1);
    
        
        // for(auto it = artiPoint.begin(); it!=artiPoint.end();it++) {
        //     cout << (*it) << endl;
        // }
        cout << artiPoint.size() << endl;
        cin >> n >> m;
    }
    return 0;
}