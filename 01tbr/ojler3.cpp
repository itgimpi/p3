#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* Lenard Euler */
/* Broj medjusobno prostih sa n, od 1 do n */

ll fi (ll n) { // Num. Theory Solution
    ll res = n;
    ll d = 2;
    while( d * d <= n ) {
        if ( n % d == 0 ) {
            res = ( res / d ) * ( d - 1 );
            while ( n % d == 0 )
                n /= d; }
        d++; }

    if ( n > 1 ) res = ( res / n ) * ( n - 1 ); 
 
    return res; }

int main() {
    ll n; cin >> n;

    cout << fi(n);
    return 0; }