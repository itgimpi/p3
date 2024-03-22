#include <bits/stdc++.h>
using namespace std;
// Counting Rooms
int dr[]={1, -1, 0,  0}; // dole, gore, desno, levo
int dk[]={0,  0, 1, -1};

void dfs(int r, int k, int brr, int brk, vector<vector<bool>>&posecen){
    posecen[r][k]=true;
    // za sva 4 smera...
    for (int i = 0; i < 4; i++) {
        // promeni polozaj...
        int rr = r + dr[i];
        int kk = k + dk[i];
        if ( 0 < rr && rr < brr &&
             0 < kk && kk < brk &&
             !posecen[rr][kk])
            dfs(rr, kk, brr, brk, posecen);  } }

int main() {
    ios_base::sync_with_stdio(false);
    int brr, brk; cin >> brr >> brk;
    vector<vector<bool>>posecen(brr, vector<bool>(brk, false));
    for ( int r = 0; r < brr; r++ ){
        for ( int k = 0; k < brk; k++ ) {
            char c; cin >> c;
            posecen[r][k] = ( c == '#' ); // ?
        } }

    int res = 0;
    for ( int r = 0; r < brr; r++ ){
        for ( int k = 0; k < brk; k++ ) {
            // ideja je da se obilazi cela soba, npr. DFS
            if (!posecen[r][k]) { 
                dfs(r, k, brr, brk, posecen);
                res++;  } } }
        
    cout << res;
    return 0; }
