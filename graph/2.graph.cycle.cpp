#include <bits/stdc++.h>
using namespace std;
bool dfs_cycle(int node, int par, vector <vector <int>> &adj, vector <int> &vis) {
    vis[node] = 1;
    bool isLoopExist = false;
    for(auto &it: adj[node]) {
        if(vis[it] == 1 && it == par) continue;
        if(vis[it] == 1) return true;
        isLoopExist |= dfs_cycle(it, node, adj, vis);
    }
    return isLoopExist;
}
int main(int args, char* argv[]) {
    int n, m;
    cin >> n >> m;

    vector<pair <int,int>> edges(m);
    for(int i=0; i<m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector <vector <int>> adj(n);
    for(int i=0; i<m; ++i) {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[1].second].push_back(edges[i].first);
    }

    vector <int> vis(n, 0);
    for(int i=0; i<n; i++) {
        if(vis[i] == 0) {
            if(dfs_cycle(i, -1, adj, vis)) {
                cout << "cycle exists..." << "\n";
                return EXIT_SUCCESS;
            }
        }
    }
    cout << "cycle does not exist..." << "\n";
    return 0;
}