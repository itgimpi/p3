#include <bits/stdc++.h> // C++ code to find the maximum path sum
using namespace std;
int dp[1000]; // globalna

void dfs(int a[], vector<int>v[], int node, int parent){
    dp[node] = a[node - 1];
    int maxsum = 0;
    for (int child : v[node]) {
        if (parent == child)
            continue; // produzi dalje
        dfs(a, v, child, node);
        maxsum = max (maxsum, dp[child]); }
    dp[node] += maxsum; }

int main() {
	int n = 14;	// number of nodes
	vector<int> v[n + 1];	// adjacency list
	v[1].push_back(2), v[2].push_back(1);	// create undirected edges, initialize the tree given in the diagram
	v[1].push_back(3), v[3].push_back(1);
	v[1].push_back(4), v[4].push_back(1);
	v[2].push_back(5), v[5].push_back(2);
	v[2].push_back(6), v[6].push_back(2);
	v[3].push_back(7), v[7].push_back(3);
	v[4].push_back(8), v[8].push_back(4);
	v[4].push_back(9), v[9].push_back(4);
	v[4].push_back(10), v[10].push_back(4);
	v[5].push_back(11), v[11].push_back(5);
	v[5].push_back(12), v[12].push_back(5);
	v[7].push_back(13), v[13].push_back(7);
	v[7].push_back(14), v[14].push_back(7);

	int a[] = { 3, 2, 1, 10, 1, 3, 9, 1, 5, 3, 4, 5, 9, 8 };	// values of node 1, 2, 3....14
    
	dfs(a, v, 1, 0);
	cout << dp[1];

	return 0; }
