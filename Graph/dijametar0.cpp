#include <bits/stdc++.h>
using namespace std;
// Depth-First Search function
void dfs(int cvor, int preth, const vector<vector<int>> &veze, vector<int> &rast) {
    for (auto c : veze[cvor]) { // Iterate over all children of the current node
        if (c != preth) { // If the child is not the parent
            rast[c] = rast[cvor] + 1; // Update the rastance of the child
            dfs(c, cvor, veze, rast);        }    }    } // Recursively call DFS for the child
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = 5;
    vector<pair<int, int>> parovi = { { 0,1 }, { 0,2 }, { 1,3 }, { 1,4 } };
    vector<vector<int>> veze(n); // Create an vezeacency list for the tree
    vector<int> rast(n); // Create an array to store the rastance of each node from the root
    for (auto p : parovi) {
        int u = p.first, v = p.second;
        veze[u].push_back(v);
        veze[v].push_back(u);  }

    rast[0] = 0; // Initialize the rastance of the first node and call DFS
    dfs(0, -1, veze, rast);

    int naj = 0, node = 0; // Find the node with the maximum rastance from the first node
    for (int i = 1; i < n; i++) {
        if (rast[i] > naj) {
            naj = rast[i];
            node = i;        }    }

    for (int i = 0; i < n; i++) // Reset the rastances and call DFS from the farthest node
        rast[i] = 0;

    dfs(node, -1, veze, rast);

    naj = 0; // Find the maximum rastance from the farthest node
    for (int i = 0; i < n; i++) 
        naj = max(naj, rast[i]);
    
    cout << naj << "\n"; // Print the diameter of the tree

    return 0;
}