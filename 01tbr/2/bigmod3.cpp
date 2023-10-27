#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull resi( ull a, ull n, ull m ) {
    ull res = 1;
    while ( n > 0 ) {
        if ( n % 2 == 0 ) { 
            a = (a * a) % m;
            n /= 2; }
        else {
            res = ( res * a ) % m;
            n--; } }

    return res; }

int main() {
    ull a, n, m; cin >> a >> n >> m;

    cout << resi( a % m, n, m);
    return 0; }