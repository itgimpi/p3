#include<bits/stdc++.h>
using namespace std; 
//-1 prva manja, 1 druga manja, 0 iste.

int main() {
    string s1, s2; cin >> s1 >> s2;

    if ( s1 < s2 ) cout << -1;
    else if ( s1 > s2 ) cout << 1;
    else cout << 0;

  }