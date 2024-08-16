#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges) {
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void printAdj(unordered_map<int, list<int>> &adjList) {
    for(auto &i : adjList) {
        cout << i.first << " -> ";
        for(auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Store frontNode into ans
        ans.push_back(frontNode);

        // Traverse all neighbors of frontNode
        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        } 
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Traverse all components of a graph
    for(int i = 0; i < vertex; i++) {
        if(!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    
    return ans;
}

int main() {
    int vertex = 5; // Example number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}}; // Example edges

    vector<int> result = BFS(vertex, edges);

    // Print the result
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
