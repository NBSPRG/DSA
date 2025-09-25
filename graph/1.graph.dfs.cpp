#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void dfs(int node, vector <vector <int>> &adj, vector<int> &vis, vector <int> &store) {
    vis[node] = 1;
    store.push_back(node);
    for(auto &it: adj[node]) {
        if(vis[it] == 0) dfs(it, adj, vis, store);
    }
}

int main() {
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
    vector <int> store;
    for(int i=0; i<n; ++i) {
        if(vis[i]==0) {
            dfs(i, adj, vis, store);
        }
    }

    cout << "DFS Traversal: ";
    for(auto &it: store) {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}