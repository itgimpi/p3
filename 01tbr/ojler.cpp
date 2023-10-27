#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* Lenard Euler */
/* Broj medjusobno prostih sa n, od 1 do n */

ll fi (ll n) { // Brute Force solution
    ll res = 0;
    for ( ll i = 1; i <= n; i++ )
        if ( __gcd( i, n ) == 1 )
            res++; 
    return res; }

int main() {
    ll n; cin >> n;

    cout << fi(n);
    return 0; }