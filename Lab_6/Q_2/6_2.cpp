#include <bits/stdc++.h>
using namespace std;
vector<int> toposort(vector<vector<int>> adj, int n) {
    vector<int> result; // The topological sorted order

    vector<int> indegree(n); // Indegrees of vertices
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(auto it : adj[node]) {
            indegree[it]--;

            if(indegree[it] == 0) {
                q.push(it);
            }
        }

    }
    return result;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, E;  // Verices and Edges
    cin >> n >> E;

    vector<vector<int>> edges(E); // Store edges
    for(int i = 0; i < E; i++) {  // Get edges as input.
        int x, y;
        cin >> x >> y;
        edges[i].push_back(x);
        edges[i].push_back(y);
    }

    vector<vector<int>> adj(n); // Adjencency list

    for(auto i : edges) {      // Making Adjacency list from the edges
        adj[i[0]].push_back(i[1]);
    }

    vector<int> result = toposort(adj, n);

    reverse(result.begin(), result.end());

    vector<int> dist(n);
    for(auto s:result) {
        for(auto x:adj[s]) {
            dist[s] = max(dist[s], dist[x]+1);
        }
    }
    cout << *max_element(dist.begin(), dist.end()) << endl;

}