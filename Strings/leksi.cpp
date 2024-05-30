#include<bits/stdc++.h>
using namespace std; 
//-1 prva manja, 1 druga manja, 0 iste.

int f( const string &s1, const string &s2 ) {
    for ( int i = 0; i < s1.size() && i < s2.size(); i++  ) {
        if ( s1[i] != s2[i] )
            return s1[i] - s2[i]; // + ako je s2 manja
    }
    return s1.size() - s2.size(); }

int main() {
    string s1, s2; cin >> s1 >> s2;
    int res = f(s1, s2);
    if ( res < 0 ) cout << -1;
    else if ( res > 0 ) cout << 1;
    else cout << 0;

  }