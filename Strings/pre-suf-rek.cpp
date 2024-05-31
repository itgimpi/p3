#include<bits/stdc++.h>
using namespace std; 
// domine, duzina najveceg prefiksa - sufiksa, rec solution

int najps(string s, int l, int d) {
    if ( d == 0 ) return 0; // samo 1 slovo

    int dps = najps(s, l-1, l); // s'

    if ( s[dps] == s[d] ) // a==b?
        return dps + 1;
    if ( dps == 0 )
        return 0;
    return najps(s, dps-1, d); }

int main() {
    string s; cin >> s;
    int br; cin >> br;
    int n = s.size();
     
    cout << najps(s, n-2, n-1) << '\n';

    cout << najps(s, n-2, n-1) + ( n - najps(s, n-2, n-1) ) * br; // domine
   

  }