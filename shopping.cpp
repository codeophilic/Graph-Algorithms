// https://www.spoj.com/problems/SHOP/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define PII pair<int, int>

int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};
int n, m;

bool isValid(int x, int y) {
    return (x<n && y<m && x>=0 && y>=0);
}

int solve(vector<string> input) {
    int dp[26][26];
    for(int i = 0;i<26;i++) for(int j = 0;j<26;j++) dp[i][j] = INT_MAX;
    int xS, yS;
    for(int i = 0;i<n;i++) 
        for(int j= 0;j<m;j++) 
            if(input[i][j] == 'S') {
                xS = i; yS = j; break;
            }

    queue<PII> q;
    q.push(mk(xS, yS));
    dp[xS][yS] = 0;
    while(!q.empty()) {
        PII front = q.front(); q.pop();
        int x = front.first; int y = front.second;
        if(dp[x][y] != INT_MAX || input[x][y] == 'X' || input[x][y] == 'D') continue;
        
        

    }
    

}

int main() {
    vector<string> input;
    cin >> n >> m;
    while(n || m) {
        for(int i = 0;i<m;i++) {
            string temp; cin >> temp;
            input.pb(temp);

            
            
            int ans = solve(input);
        }
    }
    return 0;
}