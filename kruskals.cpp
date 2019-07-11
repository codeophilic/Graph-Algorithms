#include <bits/stdc++.h>
using namespace std;

int n, e;
struct node {
    int u;
    int v;
    int wt;
};

bool compare(struct node i1, struct node i2) {
    return i1.wt < i2.wt;
}

struct node ans[100005];

int parent[100005];

int find(int x) {
    if(parent[x] == x) return x;
    int val = find(parent[x]);
    parent[x] = val;
    return parent[x];
}

bool isValid(int x, int y) {
    int parentx = find(x);
    int parenty = find(y);
    if(parentx == parenty) return false;
    parent[parentx] = parenty;
    return true;
}

void kruskals(struct node *edges) {
    sort(edges, edges+e, compare);
    for(int i = 0;i<=100000;i++) parent[i] = i;
    int count = 0; int idx = 0;
    while(count < n-1) {
        int U = edges[idx].u;
        int V = edges[idx].v;
        int W = edges[idx].wt;
        if(isValid(U, V)) {
            ans[count].u = U;
            ans[count].v = V;
            ans[count].wt = W;
            count++;
        }
        idx++;
    }
    
}

int main() {

    cin >> n >> e;
    struct node *edges = new node[e];
    for(int i = 0;i<e;i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    kruskals(edges);
    long long f= 0;
    for(int i = 0;i<n-1;i++) {
        f += (long long)ans[i].wt;

        // if(ans[i].u < ans[i].v) cout << ans[i].u << " " << ans[i].v << " " << ans[i].wt << endl;
        // else cout << ans[i].v << " " << ans[i].u << " " << ans[i].wt << endl;
    }
    cout <<f << endl;
    delete [] edges;
    return 0;
}