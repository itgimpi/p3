#include<bits/stdc++.h>
using namespace std; 
// domine, duzina najveceg prefiksa - sufiksa, BF solution, O(nn)

int main() {
    string s; cin >> s;
    int br; cin >> br;
    int n = s.size();
    int najps = 0;

    for ( int duz = 1; duz < n; duz++ ) {
        bool ps = true; //
        for ( int l = 0, d = n - duz; l < duz; l++, d++ )
            if ( s[l] != s[d] ) {
                ps = false;
                break; } 
        if ( ps )
            najps = duz;  }
    
    cout << najps << '\n';
    cout << najps + ( n - najps ) * br;
   

  }