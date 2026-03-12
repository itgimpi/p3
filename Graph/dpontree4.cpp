#include <bits/stdc++.h>
using namespace std;
/*
Given a tree T of N nodes, where each node i has Ci coins attached with it. 
You have to choose a subset of nodes such that no two adjacent nodes(i.e. nodes connected directly by an edge) 
are chosen and sum of coins attached with nodes in chosen subset is maximum.
*/


const int N = 10;
int C[] = {0,1,2,3,4,5,6,7,8,9,10};
//adjacency list
//adj[i] contains all neighbors of i
vector<int> adj[N];

//functions as defined above
int dp1[N], dp2[N];

//pV is parent of node V
void dfs(int v, int pV){

    //for storing sums of dp1 and max(dp1, dp2) for all children of V
    int sum1=0, sum2=0;

    //traverse over all children
    for(auto vv: adj[v]){
        if(vv == pV) continue;
        dfs(vv, v);
        sum1 += dp2[vv];
        sum2 += max(dp1[vv], dp2[vv]);     }

    dp1[v] = C[v] + sum1;
    dp2[v] = sum2;
}

int main(){

	adj[1].push_back(2); adj[1].push_back(3);
	adj[2].push_back(4);adj[2].push_back(5);adj[2].push_back(6);
	adj[3].push_back(7);
	adj[4].push_back(8); adj[4].push_back(9); adj[4].push_back(10);

    dfs(1, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl; }