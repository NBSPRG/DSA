#include <bits/stdc++.h>
using namespace std;

vector <int> bfs_traversal(vector <vector <int>> &adj) {
    int n = adj.size();
    queue <int> q;
    vector <int> vis(n, 0);
    vector <int> ans;
    q.push(0);
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        vis[front] = 1;
        ans.push_back(front);
        for(auto it: adj[front]) {
            if(vis[it] == 0) q.push(it);
        }
    }
    return ans;
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

    vector <int> ans = bfs_traversal(adj);
    for(auto &it: ans) cout << it << " ";
    cout << "\n";

    return 0;
}