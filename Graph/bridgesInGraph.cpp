#include <bits/stdc++.h>
using namespace std;

int timer;
vector<int> adj[101];
int tin[101], low[101], vis[101];

void dfs(int node, int parent) {

    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for(int child : adj[node]) {
        // if child is parent, then skip it
        if(child == parent) continue;

        if(vis[child] == 1) {
            // edge node -> child is a backedge
            low[node] = min(low[node], tin[child]);
        }
        else {
            //edge node -> child is a forward edge. Hence continue dfs
            dfs(child, node);

            if(low[child] > tin[node])
                cout << node << " -> " << child << " is a bridge\n";

            low[node] = min(low[node], low[child]);

        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    while(E--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
}
