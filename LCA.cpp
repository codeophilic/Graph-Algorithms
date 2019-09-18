#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long

vector<vector<int>> edges(1005);
map<int, int> first;
vector<int> path(100000);
int height[1005];
set<int> visited;
int idx = 0;

int query(int u, int v) {
    int idx1 = first[u]; int idx2 = first[v];
    if(idx1 > idx2) swap(idx1, idx2);
    int h = INT_MAX;
    int ans;
    for(int i = idx1;i<=idx2;i++) {
        if(height[path[i]] < h) {
            ans = path[i];
            h = height[path[i]];
        }
    }
    return ans;
}

void dfs(int sv, int h) {
    visited.insert(sv);
    path[idx++] = sv;
    height[sv] = h;
    if(first.count(sv) == 0) first[sv] = idx-1;
    for(int i =0;i<edges[sv].size();i++) {
        int adj = edges[sv][i];
        dfs(adj, h+1);
        path[idx++] = sv;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cout.tie(NULL); cin.tie(NULL);

    int t; cin >> t;
    for(int i = 1;i<=t;i++) {
        for(int i = 0;i<1005;i++) edges[i].clear();

        int n; cin >> n;
        for(int i = 1;i<=n;i++){
            int nodes; cin >> nodes;
            for(int j = 0;j<nodes;j++) {
                int temp; cin >> temp;
                edges[i].push_back(temp);
            }
        }
        first.clear(); 
        memset(height, 0, sizeof height);
        visited.clear(); idx = 0;
        dfs(1, 1);

        int q; cin >> q;
        cout << "Case " << i << ":\n";
        while(q--) {
            int u, v; cin >> u >> v;
            cout << query(u, v) << endl;
        }
    }
    
    return 0;
}
