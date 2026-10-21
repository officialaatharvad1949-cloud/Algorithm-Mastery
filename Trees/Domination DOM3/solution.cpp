#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long nC3(long long n) {
    if (n < 3) return 0;
    return n * (n - 1) * (n - 2) / 6;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    // 1. Total ways to pick 3 vertices to exclude
    long long total_ways = nC3(n);

    // Track invalid sets of size 3 using Inclusion-Exclusion
    long long invalid_count = 0;

    // A. Leaf conditions: Each leaf u with neighbor p forms invalid sets {u, p, w} for any w != u, p
    vector<int> leaves;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            leaves.push_back(i);
        }
    }

    // Add (N - 2) invalid sets for each leaf
    invalid_count += (long long)leaves.size() * (n - 2);

    // Subtract overlaps between pairs of leaves sharing the same parent
    // If leaves u1 and u2 share parent p, the set {u1, u2, p} was counted twice
    for (int i = 1; i <= n; ++i) {
        int leaf_children_count = 0;
        for (int neighbor : adj[i]) {
            if (deg[neighbor] == 1) {
                leaf_children_count++;
            }
        }
        if (leaf_children_count >= 2) {
            invalid_count -= nC3(leaf_children_count); // Subtract duplicate pairs
        }
    }

    // B. Degree-2 node conditions: N[v] = {v, v1, v2} forms 1 unique invalid set
    vector<int> deg2_nodes;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 2) {
            deg2_nodes.push_back(i);
        }
    }

    for (int v : deg2_nodes) {
        int v1 = adj[v][0];
        int v2 = adj[v][1];

        // Check if N[v] = {v, v1, v2} was ALREADY counted by a leaf condition
        // N[v] is counted by a leaf if it contains a leaf u and its parent p
        bool counted_by_leaf = false;
        
        // Count how many leaves are in N[v]
        int leaves_in_Nv = 0;
        if (deg[v] == 1) leaves_in_Nv++;
        if (deg[v1] == 1) leaves_in_Nv++;
        if (deg[v2] == 1) leaves_in_Nv++;

        // If N[v] contains a leaf u and its parent p, it was already accounted for
        if ((deg[v1] == 1 && (v == adj[v1][0] || v2 == adj[v1][0])) ||
            (deg[v2] == 1 && (v == adj[v2][0] || v1 == adj[v2][0]))) {
            counted_by_leaf = true;
        }

        if (!counted_by_leaf) {
            invalid_count++;
        }
    }

    // Output valid dominating sets
    cout << total_ways - invalid_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
