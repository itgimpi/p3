#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* Lenard Euler */
/* Broj medjusobno prostih sa n, od 1 do n */
/* fi(n) = n x (p1-1) / p1 ...              */

ll fi ( ll n ) {
    ll res = n;
    ll p = 2; // prvi potencijalni prost cinilac

    while ( p * p <= n ) {
        if ( n % p == 0 ) {
            res = ( res / p ) * ( p - 1 );
            while ( n % p == 0 ) // sve dok cinilac postoji u broju
                n /= p;  // izbacuj cinilac
        }
        p++; } // probaj novi prost cin.

    if ( n > 1 )
        res = ( res / n ) * ( n - 1 );

    return res; }

int main() { // Number Theory solution
    ll n; cin >> n;

    cout << fi(n);
    return 0; }