#include <bits/stdc++.h> // C++ code to find the maximum path length considering any node as root
using namespace std;
const int MAX_NODES = 100;

int in[MAX_NODES];
int out[MAX_NODES];

// function to pre-calculate the array in[] which stores the maximum height when travelled via branches
void dfs1(vector<int> v[], int u, int parent) {
	in[u] = 0; 	// initially every node has 0 height
	for (int child : v[u]) {	// traverse in the subtree of u
		if (child == parent)		// ako nema potomke, ostaje na 0
			continue;
		dfs1(v, child, u);		// dfs
		in[u] = max(in[u], 1 + in[child]); 	} }		// recursively calculate the max height

// function to pre-calculate the array out[] which stores the maximum height when traveled via parent
void dfs2(vector<int> v[], int u, int parent) {
	int mx1 = -1, mx2 = -1;	// stores the longest and second longest branches
	for (int child : v[u]) { 	// traverse in the subtress of u
		if (child == parent)
			continue;
		if (in[child] >= mx1) {		// compare and store the longest and second longest
			mx2 = mx1;
			mx1 = in[child]; }
		else if (in[child] > mx2)
			mx2 = in[child]; }
	for (int child : v[u]) {	// traverse in the subtree of u
		if (child == parent)
			continue;
		int longest = mx1;
		if (mx1 == in[child])		// if longest branch has the node, then consider the second longest branch
			longest = mx2;
		out[child] = 1 + max(out[u], 1 + longest);		// recursively calculate out[i]
		dfs2(v, child, u); 	} } 		// dfs function call

void printHeights(vector<int> v[], int n) { // function to print all the maximum heights from every node
	dfs1(v, 1, 0); 	// traversal to calculate in[] array
	dfs2(v, 1, 0);	// traversal to calculate out[] array
	for (int i = 1; i <= n; i++) 	// print all maximum heights
		cout << "The maximum height when node " << i << " is considered as root" << " is " << max(in[i], out[i]) << "\n"; }

int main() {
	int n = 11;
	vector<int> v[n + 1];

	v[1].push_back(2), v[2].push_back(1); 	// initialize the tree given in the diagram
	v[1].push_back(3), v[3].push_back(1);
	v[1].push_back(4), v[4].push_back(1);
	v[2].push_back(5), v[5].push_back(2);
	v[2].push_back(6), v[6].push_back(2);
	v[3].push_back(7), v[7].push_back(3);
	v[7].push_back(10), v[10].push_back(7);
	v[7].push_back(11), v[11].push_back(7);
	v[4].push_back(8), v[8].push_back(4);
	v[4].push_back(9), v[9].push_back(4);
	printHeights(v, n);	// function to print the maximum height from every node
	return 0; }
