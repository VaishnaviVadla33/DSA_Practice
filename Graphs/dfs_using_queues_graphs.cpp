#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;

    // For each connected node, recursive call
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, adj, visited, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Prepare adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    int V = 5; // Example number of vertices
    int E = 4; // Example number of edges
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}}; // Example edges

    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    // Print the result
    for (const auto &component : result) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
