#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
//typedef unsigned long long ll;
typedef __int128 ll;

ll stepen( ll a, ll n, ll m ) { // a na n mod m ~ log p, bolje od sqrt p
    if ( n == 0 ) return 1;

    if ( n % 2 == 0 ) // stepen je par?
        return stepen( ( a % m ) * ( a % m ), n / 2, m ) % m;
    // nepar
    return  ( ( a % m ) * stepen ( a, n-1, m) ) % m; }

bool ferma( ll p , ll br) {
    if ( p == 1 ) return false;
    if ( p == 2 || p == 3 ) return true;
    default_random_engine gen;
    uniform_int_distribution<unsigned>dist(2, p - 2); // a od 2 do p-2
    while ( br-- ) {
        ll a = dist(gen);
        if ( stepen(a, p-1, p) != 1 )
            return false; }
    return true; }

int main() {
    long long p;
    
    while ( cin >> p ) 
        if ( ferma(p, 100) )
            cout << p << '\n';

    return 0; }

