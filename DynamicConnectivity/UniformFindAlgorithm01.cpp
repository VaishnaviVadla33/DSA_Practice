#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 1);
        for (int i = 0; i < size; ++i) {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    int find(int p) {
        if (parent[p] != p) {
            parent[p] = find(parent[p]); // Path compression
        }
        return parent[p];
    }

    void unionSets(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP != rootQ) {
            // Union by rank
            if (rank[rootP] > rank[rootQ]) {
                parent[rootQ] = rootP;
            } else if (rank[rootP] < rank[rootQ]) {
                parent[rootP] = rootQ;
            } else {
                parent[rootQ] = rootP;
                rank[rootP]++;
            }
        }
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

int main() {
    UnionFind uf(10); // Create a union-find structure for 10 elements

    // Hardcoded union operations
    uf.unionSets(1, 2);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);
    
    // Check connectivity
    if (uf.connected(1, 3)) {
        cout << "1 and 3 are connected." << endl;
    } else {
        cout << "1 and 3 are not connected." << endl;
    }

    if (uf.connected(1, 4)) {
        cout << "1 and 4 are connected." << endl;
    } else {
        cout << "1 and 4 are not connected." << endl;
    }

    return 0;
}
