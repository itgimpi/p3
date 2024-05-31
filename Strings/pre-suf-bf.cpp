#include<bits/stdc++.h>
using namespace std; 
// domine, duzina najveceg prefiksa - sufiksa, BF solution, O(nn)

int main() {
    string s; cin >> s; // izgled "domine"
    int br; cin >> br; // br. domina

    int n = s.size();
    int najps = 0; // resenje na pocetku je 0

    for ( int duz = 1; duz < n; duz++ ) { // probaj sve duzine...
        bool ps = true; // recimo da jeste...
        //levi ide od 0, desni od n-duz...
        for ( int l = 0, d = n - duz; l < duz; l++, d++ )
            if (s[l] != s[d]) { // nisu isti?
                ps = false; // ipak nije pre suf.
                break; } 
        if ( ps ) // ako jeste pre suf
            najps = duz; }

    cout << najps + br * ( n - najps );

    

  }