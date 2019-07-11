#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define PII pair<int, int>
#define mk make_pair
vector<vector<PII>> edges(100010);
int dist[100010];
int v, e;
int a, b;
void dijkstra() {
    set<PII> s;
    s.insert(mk(0, a));
    dist[a] = 0;
    while(!s.empty()) {

        PII p = *(s.begin());
        int node = p.second;
        int dd = p.first;
        s.erase(s.begin());
        // cout << node << " " <<dd << endl; 

        for(int i = 0;i<edges[node].size();i++) {
            int val = edges[node][i].second;
            int adj = edges[node][i].first;

            if(dd + val < dist[adj]) {
                auto ff = s.find(mk(dist[adj], adj));
                if(ff != s.end()) {
                    s.erase(ff);
                }

                dist[adj] = dd + val;
                s.insert(mk(dist[adj], adj));
            }
        }
    }
    // for(int i= 0;i<v;i++) cout << i << " " << dist[i] << endl;
    if(dist[b] == INT_MAX || dist[a] == INT_MAX) {
        cout << "NO" << endl;
        return ;
    }
    cout << dist[b] - dist[a] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        
        for(int i = 0;i<100010;i++) dist[i] = INT_MAX;
        cin >> v >> e;
        for(int i = 0;i<=v;i++) edges[i].clear();
        for(int i = 0;i<e;i++) {
            int f, s, w;
            cin >> f >>s >> w;
            edges[f].pb(mk(s, w));
            // edges[s].pb(mk(f, w));
        }
        cin >> a>> b;

        dijkstra();
    }

    return 0;
}