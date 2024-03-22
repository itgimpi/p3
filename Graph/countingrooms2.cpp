#include <bits/stdc++.h>
using namespace std;
// Counting Rooms
// smerovi: R, D,  L,   U
int dr[] = {0, 1,  0, -1};
int dk[] = {1, 0, -1,  0}; 

void dfs(int r, int k, int brr, int brk, vector<vector<bool>>&posecen) {
    posecen[r][k] = true;
    for ( int i = 0; i < 4; i++ ) { // za sva 4 smera...
        int rr = r + dr[i]; // novi red
        int kk = k + dk[i]; // nova kolona
        if ( 0 <= rr && rr < brr &&
             0 <= kk && kk < brk &&
             !posecen[rr][kk])
            dfs(rr, kk, brr, brk, posecen);  } }

int main() {
    ios_base::sync_with_stdio(false);
    int brr, brk; cin >> brr >> brk;
    vector<vector<bool>>posecen(brr, vector<bool>(brk, false));
    for (int r = 0; r < brr; r++) {
        for (int k = 0; k < brk; k++) {
            char c; cin >> c;
            posecen[r][k] = ( c == '#' ); // if...
        } }
    
    int res = 0;
    for (int r = 0; r < brr; r++) {
        for (int k = 0; k < brk; k++) {
            if (!posecen[r][k]) { 
                dfs(r, k, brr, brk, posecen);
                res++;  } } }
    cout << res;
    return 0; }
